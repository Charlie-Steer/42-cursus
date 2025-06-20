/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:22:20 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/30 13:27:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Make MAKEFILE!
// TODO: Check LEAKS!
#include <assert.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

enum					e_time_unit
{
	USEC,
	MSEC,
};

void	zero_block(void *block, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)block)[i] = '\0';
		i++;
	}
}

int	str_to_int(char *str)
{
	int		num;
	int		i;
	bool	is_negative;

	num = 0;
	i = 0;
	is_negative = false;
	if (str[0] == '-')
	{
		is_negative = true;
		i += 1;
	}
	else if (str[0] == '+')
		i += 1;
	while (str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (is_negative)
		num = -num;
	return (num);
}

bool	check_if_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[1] == '+')
		i += 1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '\0')
		return (true);
	else
		return (false);
}

bool	check_if_arguments_are_valid(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_if_number(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

void	*allocate(int bytes)
{
	void	*block;

	block = malloc(bytes);
	zero_block(block, bytes);
	return (block);
}

typedef struct s_sim_data
{
	struct timeval		simulation_start_timeval;
	long				simulation_time;
	pthread_mutex_t		*forks;
	bool				some_philo_is_dead;
	bool				quota_has_been_met;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		quota_mutex;
	int					*meals_had;
	pthread_mutex_t		*meals_had_mutexes;
}						t_sim_data;

enum					e_philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD,
};

typedef struct s_philo_data
{
	int					id;
	enum e_philo_state	state;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long				last_meal_time_us;
	pthread_mutex_t		*last_meal_time_mutex;
}						t_philo_data;

typedef struct s_config
{
	int					n_philo;
	int					death_time_us;
	int					eat_time_us;
	int					sleep_time_us;
	int					n_meals;
}						t_config;

typedef struct s_data
{
	t_config			*config;
	t_sim_data			*sim;
	t_philo_data		*philo;
}						t_data;

long	get_time_ms(t_sim_data *sim_data)
{
	struct timeval	tv;
	long			current_time;
	long			now_secs;
	long			now_usecs;

	gettimeofday(&tv, NULL);
	now_secs = tv.tv_sec - sim_data->simulation_start_timeval.tv_sec;
	now_usecs = tv.tv_usec - sim_data->simulation_start_timeval.tv_usec;
	if (now_usecs < 0)
	{
		now_secs--;
		now_usecs += 1000000;
	}
	current_time = now_secs * 1000000 + now_usecs;
	current_time /= 1000;
	return (current_time);
}

long	get_time_us(t_sim_data *sim_data)
{
	struct timeval	tv;
	long			now_secs;
	long			now_usecs;
	long			current_time;

	gettimeofday(&tv, NULL);
	now_secs = tv.tv_sec - sim_data->simulation_start_timeval.tv_sec;
	now_usecs = tv.tv_usec - sim_data->simulation_start_timeval.tv_usec;
	if (now_usecs < 0)
	{
		now_secs--;
		now_usecs += 1000000;
	}
	current_time = now_secs * 1000000 + now_usecs;
	return (current_time);
}

bool	is_some_philo_dead(t_sim_data *sim_data, t_philo_data *philo,
		bool is_during_meal)
{
	pthread_mutex_lock(&sim_data->death_mutex);
	if (sim_data->some_philo_is_dead)
	{
		pthread_mutex_unlock(&sim_data->death_mutex);
		if (is_during_meal)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&sim_data->death_mutex);
		return (false);
	}
}

bool	has_quota_been_met(t_sim_data *sim_data, t_philo_data *philo,
		bool is_during_meal)
{
	bool	quota_has_been_met;

	pthread_mutex_lock(&sim_data->quota_mutex);
	quota_has_been_met = sim_data->quota_has_been_met;
	pthread_mutex_unlock(&sim_data->quota_mutex);
	if (quota_has_been_met)
	{
		if (is_during_meal)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}
		return (true);
	}
	else
	{
		return (false);
	}
}

void	*simulate_philo(void *args)
{
	t_config		*config;
	t_sim_data		*sim;
	t_philo_data	*philo;

	config = ((t_data *)args)->config;
	sim = ((t_data *)args)->sim;
	philo = ((t_data *)args)->philo;
	printf("%05ld %d is thinking\n", get_time_ms(sim), philo->id);
	while (true)
	{
		if (is_some_philo_dead(sim, philo, false) || has_quota_been_met(sim,
				philo, false))
			return (NULL);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
			pthread_mutex_lock(philo->right_fork);
			printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
			pthread_mutex_lock(philo->left_fork);
			printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
		}
		pthread_mutex_lock(&(philo->last_meal_time_mutex[0]));
		philo->last_meal_time_us = get_time_us(sim);
		pthread_mutex_unlock(&(philo->last_meal_time_mutex[0]));
		pthread_mutex_lock(&(sim->meals_had_mutexes[philo->id - 1]));
		sim->meals_had[philo->id - 1] += 1;
		pthread_mutex_unlock(&(sim->meals_had_mutexes[philo->id - 1]));
		printf("%05ld %d is eating\n", get_time_ms(sim), philo->id);
		usleep(config->eat_time_us);
		if (is_some_philo_dead(sim, philo, true) || has_quota_been_met(sim,
				philo, true))
			return (NULL);
		printf("%05ld %d is sleeping\n", get_time_ms(sim), philo->id);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		usleep(config->sleep_time_us);
		if (is_some_philo_dead(sim, philo, false) || has_quota_been_met(sim,
				philo, false))
			return (NULL);
		printf("%05ld %d is thinking\n", get_time_ms(sim), philo->id);
	}
	return (NULL);
}

t_config	*get_config(int argc, char *argv[])
{
	t_config	*config;

	config = NULL;
	config = allocate(sizeof(t_config));
	if (config == NULL)
		return (NULL);
	config->n_philo = str_to_int(argv[1]);
	config->death_time_us = str_to_int(argv[2]) * 1000;
	config->eat_time_us = str_to_int(argv[3]) * 1000;
	config->sleep_time_us = str_to_int(argv[4]) * 1000;
	if (argc == 6)
		config->n_meals = str_to_int(argv[5]);
	// printf("%d\n", config->n_philo);
	// printf("%d\n", config->death_time);
	// printf("%d\n", config->eat_time);
	// printf("%d\n", config->sleep_time);
	// printf("%d\n", config->n_meals);
	return (config);
}

bool	are_arguments_valid(int argc, char *argv[])
{
	// TODO: Parse args.
	if (argc != 5 && argc != 6)
	{
		printf("Format: philo number_of_philosophers time_to_die time_to_eat "
				"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (false);
	}
	else if (!check_if_arguments_are_valid(argc, argv))
	{
		printf("ERROR: All arguments must be numbers.\n");
		return (false);
	}
	else
		return (true);
}

struct timeval	get_timeval(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv);
}

t_sim_data	*get_sim_data(t_config *config)
{
	t_sim_data	*sim_data;
	int			i;

	sim_data = allocate(sizeof(t_sim_data));
	if (sim_data == NULL)
		return (NULL);
	*sim_data = (t_sim_data){0};
	*sim_data = (t_sim_data){
		.simulation_start_timeval = get_timeval(),
		// .simulation_start_time_us = get_time_us(sim_data),
		.forks = allocate(config->n_philo * sizeof(pthread_mutex_t)),
		.meals_had = allocate(config->n_philo * sizeof(int)),
		.meals_had_mutexes = allocate(config->n_philo
				* sizeof(pthread_mutex_t)),
		// .death_mutex = allocate(config->n_philo * sizeof(pthread_mutex_t)),
	};
	if (sim_data->forks == NULL || sim_data->meals_had_mutexes == NULL
		|| sim_data->meals_had == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_init(&(sim_data->forks[i]), NULL);
		pthread_mutex_init(&(sim_data->meals_had_mutexes[i]), NULL);
		pthread_mutex_init(&(sim_data->death_mutex), NULL);
		pthread_mutex_init(&(sim_data->quota_mutex), NULL);
		i++;
	}
	return (sim_data);
}

t_philo_data	*create_philo_data_array(t_config *config, t_sim_data *sim_data)
{
	t_philo_data	*philo_data_array;
	int				i;
	pthread_mutex_t	*mutexes;

	philo_data_array = allocate(config->n_philo * sizeof(t_philo_data));
	if (philo_data_array == NULL)
		return (NULL);
	mutexes = allocate(config->n_philo * sizeof(pthread_mutex_t));
	if (mutexes == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_init(&mutexes[i], NULL);
		philo_data_array[i] = (t_philo_data){
			.id = i + 1,
			.left_fork = &(sim_data->forks[i]),
			.right_fork = &(sim_data->forks[(i + 1) % config->n_philo]),
			.last_meal_time_us = get_time_us(sim_data),
			.last_meal_time_mutex = &mutexes[i],
		};
		i++;
	}
	return (philo_data_array);
}

typedef struct s_threads_and_data
{
	pthread_t			*philo_threads;
	t_data				*data;
}						t_threads_and_data;

pthread_t	*create_philo_threads(t_config *config, t_sim_data *sim_data,
		t_philo_data *philo_data_array)
{
	pthread_t	*philo_threads;
	int			i;
	t_data		*data;

	// t_threads_and_data	threads_and_data;
	philo_threads = allocate(config->n_philo * sizeof(pthread_t));
	if (philo_threads == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		data[i].config = config;
		data[i].sim = sim_data;
		data[i].philo = &philo_data_array[i];
		if (pthread_create(&philo_threads[i], NULL, simulate_philo,
				&data[i]) != 0)
			return (NULL);
		// pthread_detach(philo_threads[i]);
		i++;
	}
	// threads_and_data = (t_threads_and_data){
	// 	.philo_threads = philo_threads,
	// 	.data = data,
	// };
	return (philo_threads);
}

t_data	*create_data_struct(t_config *config, t_sim_data *sim_data,
		t_philo_data *philo_data_array)
{
	t_data	*data_array;
	int		i;

	data_array = allocate(config->n_philo * sizeof(t_data));
	if (data_array == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		data_array[i] = (t_data){
			.config = config,
			.sim = sim_data,
			.philo = &philo_data_array[i],
		};
		i++;
	}
	return (data_array);
}

void	infinite_check_for_death(t_sim_data *sim_data, t_config *config,
		t_philo_data *philo_data_array)
{
	int		i;
	bool	all_philos_met_the_quota;

	i = 0;
	while (true)
	{
		all_philos_met_the_quota = true;
		i = 0;
		// printf("ms: %ld\n", get_time_ms(sim_data));
		// printf("us: %ld\n", get_time_us(sim_data));
		while (i < config->n_philo)
		{
			pthread_mutex_lock(&(philo_data_array->last_meal_time_mutex[i]));
			if (get_time_us(sim_data)
				- philo_data_array[i].last_meal_time_us >= config->death_time_us)
			{
				pthread_mutex_unlock(&(philo_data_array->last_meal_time_mutex[i]));
				printf("%05ld %d died\n", get_time_ms(sim_data), i + 1);
				pthread_mutex_lock(&sim_data->death_mutex);
				sim_data->some_philo_is_dead = true;
				pthread_mutex_unlock(&sim_data->death_mutex);
				return ;
			}
			pthread_mutex_unlock(&(philo_data_array->last_meal_time_mutex[i]));
			pthread_mutex_lock(&(sim_data->meals_had_mutexes[i]));
			if (config->n_meals > 0 && sim_data->meals_had[i] < config->n_meals)
			{
				pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
				all_philos_met_the_quota = false;
				break ;
			}
			else
			{
				pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
				// printf("%d IS SATED\n", i + 1);
			}
			i++;
		}
		if (config->n_meals > 0 && all_philos_met_the_quota)
		{
			printf("ALL PHILOS MET THE QUOTA!!!\n");
			pthread_mutex_lock(&sim_data->quota_mutex);
			sim_data->quota_has_been_met = true;
			pthread_mutex_unlock(&sim_data->quota_mutex);
			return ;
		}
		usleep(1000);
	}
}

void	join_threads(t_config *config, pthread_t *philo_threads)
{
	int	i;

	i = 0;
	while (i < config->n_philo)
	{
		pthread_join(philo_threads[i], NULL);
		printf("THREAD %d joined\n", i + 1);
		i++;
	}
}

void	cleanup(t_sim_data *sim_data, t_philo_data *philo_data_array,
		t_config *config, pthread_t *philo_threads)
{
	int	i;

	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_destroy(&sim_data->meals_had_mutexes[i]);
		pthread_mutex_destroy(&sim_data->forks[i]);
		pthread_mutex_destroy(philo_data_array[i].last_meal_time_mutex);
		i++;
	}
	pthread_mutex_destroy(&sim_data->death_mutex);
	pthread_mutex_destroy(&sim_data->quota_mutex);
}

int	main(int argc, char *argv[])
{
	t_config		*config;
	t_sim_data		*sim_data;
	pthread_t		*philo_threads;
	t_philo_data	*philo_data_array;

	if (!are_arguments_valid(argc, argv))
		return (EXIT_FAILURE);
	config = get_config(argc, argv);
	if (config == NULL)
		return (EXIT_FAILURE);
	sim_data = get_sim_data(config);
	if (sim_data == NULL)
		return (EXIT_FAILURE);
	philo_data_array = create_philo_data_array(config, sim_data);
	if (philo_data_array == NULL)
		return (EXIT_FAILURE);
	philo_threads = create_philo_threads(config, sim_data, philo_data_array);
	if (!philo_threads)
		return (EXIT_FAILURE);
	infinite_check_for_death(sim_data, config, philo_data_array);
	// usleep(10000000);
	join_threads(config, philo_threads);
	cleanup(sim_data, philo_data_array, config, philo_threads);
	return (EXIT_SUCCESS);
}
