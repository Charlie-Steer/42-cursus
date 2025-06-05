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
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

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

// enum					e_fork_state
// {
// 	AVAILABLE,
// 	UNAVAILABLE,
// };

typedef struct s_sim_data
{
	long				simulation_start_time;
	long				simulation_time;
	// enum e_fork_state	*forks;
	pthread_mutex_t		*forks;
	bool				some_philo_is_dead;
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
	// bool				has_fork;
	// enum e_fork_state	*left_fork;
	// enum e_fork_state	*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long				last_meal_time;
}						t_philo_data;

// enum					e_state
// {
// 	STATE_EATING,
// 	STATE_THINKING,
// 	STATE_SLEEPING,
// };

typedef struct s_config
{
	int					n_philo;
	int					death_time;
	int					eat_time;
	int					sleep_time;
	int					n_meals;
}						t_config;

// TODO: Pass this to philos as argument.
// TODO: Pass this to philos as argument.
// TODO: Pass this to philos as argument.
typedef struct s_data
{
	t_config			*config;
	t_sim_data			*sim;
	t_philo_data		*philo;
}						t_data;

long	get_timestamp(t_sim_data *sim_data)
{
	struct timeval	tv;
	long			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_usec - sim_data->simulation_start_time;
	return (current_time);
}

void	*simulate_philo(void *args)
{
	t_config		*config;
	t_sim_data		*sim;
	t_philo_data	*philo;

	config = ((t_data *)args)->config;
	sim = ((t_data *)args)->sim;
	philo = ((t_data *)args)->philo;
	printf("%ld %d is thinking\n", get_timestamp(sim), philo->id);
	while (!(sim->some_philo_is_dead))
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			printf("%ld %d has taken a fork\n", get_timestamp(sim), philo->id);
			pthread_mutex_lock(philo->right_fork);
			printf("%ld %d has taken a fork\n", get_timestamp(sim), philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			printf("%ld %d has taken a fork\n", get_timestamp(sim), philo->id);
			pthread_mutex_lock(philo->left_fork);
			printf("%ld %d has taken a fork\n", get_timestamp(sim), philo->id);
		}
		// for (int i = 0; i < config->n_philo; i++)
		// {
		// 	if (&(sim->forks[i]) == philo->left_fork)
		// 		printf("philo %d TOOK fork %d (LEFT)\n", philo->id, i);
		// }
		// for (int i = 0; i < config->n_philo; i++)
		// {
		// 	if (&(sim->forks[i]) == philo->right_fork)
		// 		printf("philo %d TOOK fork %d (RIGHT)\n", philo->id, i);
		// }
		philo->state = EATING;
		philo->last_meal_time = get_timestamp(sim);
		pthread_mutex_lock(&(sim->meals_had_mutexes[philo->id - 1]));
		sim->meals_had[philo->id - 1] += 1;
		pthread_mutex_unlock(&(sim->meals_had_mutexes[philo->id - 1]));
		printf("%ld %d is eating\n", get_timestamp(sim), philo->id);
		usleep(config->eat_time * 1000);
		philo->state = SLEEPING;
		printf("%ld %d is sleeping\n", get_timestamp(sim), philo->id);
		pthread_mutex_unlock(philo->left_fork);
		// for (int i = 0; i < config->n_philo; i++)
		// {
		// 	if (&(sim->forks[i]) == philo->left_fork)
		// 		printf("philo %d RELEASED fork %d (LEFT)\n", philo->id, i);
		// }
		pthread_mutex_unlock(philo->right_fork);
		// for (int i = 0; i < config->n_philo; i++)
		// {
		// 	if (&(sim->forks[i]) == philo->right_fork)
		// 		printf("philo %d RELEASED fork %d (RIGHT)\n", philo->id, i);
		// }
		usleep(config->sleep_time * 1000);
		printf("%ld %d is thinking\n", get_timestamp(sim), philo->id);
		philo->state = THINKING;
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
	config->death_time = str_to_int(argv[2]) * 1000;
	config->eat_time = str_to_int(argv[3]);
	config->sleep_time = str_to_int(argv[4]);
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

t_sim_data	*get_sim_data(t_config *config)
{
	t_sim_data		*sim_data;
	int				i;
	pthread_mutex_t	fork_mutex;

	sim_data = allocate(sizeof(t_sim_data));
	if (sim_data == NULL)
		return (NULL);
	sim_data->simulation_start_time = get_timestamp(sim_data);
	sim_data->forks = allocate(config->n_philo * sizeof(pthread_mutex_t));
	if (sim_data->forks == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_init(&(sim_data->forks[i]), NULL);
		i++;
	}
	sim_data->meals_had = allocate(config->n_philo * sizeof(int));
	sim_data->meals_had_mutexes = allocate(config->n_philo
			* sizeof(pthread_mutex_t));
	if (sim_data->meals_had_mutexes == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_init(&(sim_data->meals_had_mutexes[i]), NULL);
		i++;
	}
	return (sim_data);
}

t_philo_data	*create_philo_data_array(t_config *config, t_sim_data *sim_data)
{
	t_philo_data	*philo_data_array;
	int				i;

	philo_data_array = allocate(config->n_philo * sizeof(t_philo_data));
	if (philo_data_array == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		philo_data_array[i] = (t_philo_data){
			.id = i + 1,
			.state = THINKING,
			.left_fork = &(sim_data->forks[i]),
			.right_fork = &(sim_data->forks[(i + 1) % config->n_philo]),
		};
		i++;
	}
	return (philo_data_array);
}

pthread_t	*create_philo_threads(t_config *config, t_sim_data *sim_data,
		t_philo_data *philo_data_array)
{
	pthread_t	*philo_threads;
	int			i;
	t_data		*data;

	philo_threads = allocate(config->n_philo * sizeof(pthread_t));
	if (philo_threads == NULL)
		return (NULL);
	data = allocate(config->n_philo * sizeof(t_data));
	if (data == NULL)
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
		pthread_detach(philo_threads[i]);
		i++;
	}
	return (philo_threads);
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
		while (i < config->n_philo)
		{
			if (get_timestamp(sim_data)
				- philo_data_array[i].last_meal_time >= config->death_time)
			{
				printf("%ld %d died\n", get_timestamp(sim_data), i + 1);
				return ;
			}
			pthread_mutex_lock(&(sim_data->meals_had_mutexes[i]));
			if (sim_data->meals_had[i] < config->n_meals)
			{
				pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
				all_philos_met_the_quota = false;
				break ;
			}
			pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
			i++;
		}
		if (all_philos_met_the_quota)
			return ;
		// usleep(100);
	}
}

// NOTE: TIME MANAGEMENT IS FUCKED. OUT OF ORDER PRINTS. RIDICULOUS NUMBERS.
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
	// TODO: Join threads on death or meal goal met.
	// usleep(5000000);
	// TODO: Clean up threads and mutexes.
	return (EXIT_SUCCESS);
}
