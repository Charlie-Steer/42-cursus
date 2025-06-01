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

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

enum					e_state
{
	STATE_EATING,
	STATE_THINKING,
	STATE_SLEEPING,
};

struct					s_config
{
	int					n_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					n_meals;
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

void	*simulate_philo(void *args)
{
	struct timeval	tv;

	while (true)
	{
		gettimeofday(&tv, NULL);
		// TODO: Handle error.
		tv.tv_usec;
	}
}

enum					e_fork_state
{
	AVAILABLE,
	UNAVAILABLE,
};

typedef struct s_sim_data
{
	long				simulation_start_time;
	long				simulation_time;
	enum e_fork_state	*forks;
	long				sleep_time;
	long				death_time;
	long				min_number_of_meals;
}						t_sim_data;

enum					e_philo_state
{
	IDLE,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
};

typedef struct s_philo_data
{
	int					id;
	enum e_philo_state	state;
	bool				has_fork;
	enum e_fork_state	*left_fork;
	enum e_fork_state	*right_fork;
	long				time_till_death;
	long				time_till_awake;
}						t_philo_data;

// TODO: Pass this to philos as argument.
// TODO: Pass this to philos as argument.
// TODO: Pass this to philos as argument.
typedef struct s_data
{
	t_sim_data			sim;
	t_philo_data		philo;
}						t_data;

int	main(int argc, char *argv[])
{
	struct s_config	config;
	pthread_t		*philos;
	int				i;

	// TODO: Parse args.
	if (argc != 4 && argc != 5)
	{
		printf("Format: philo number_of_philosophers time_to_die time_to_sleep "
				"[number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	else if (!check_if_arguments_are_valid(argc, argv))
	{
		printf("ERROR: All arguments must be numbers.\n");
		return (EXIT_FAILURE);
	}
	zero_block(&config, sizeof(config));
	config.n_philo = str_to_int(argv[1]);
	config.time_to_die = str_to_int(argv[2]);
	config.time_to_sleep = str_to_int(argv[3]);
	if (argc == 5)
		config.n_meals = str_to_int(argv[4]);
	printf("%d\n", config.n_philo);
	printf("%d\n", config.time_to_die);
	printf("%d\n", config.time_to_sleep);
	printf("%d\n", config.n_meals);
	// NOTE: Fork availability is global state. array of bools?
	philos = allocate(config.n_philo * sizeof(pthread_t));
	i = 0;
	while (i < config.n_philo)
	{
		pthread_create(&(philos[i]), NULL, simulate_philo, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
