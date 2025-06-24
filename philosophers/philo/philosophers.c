/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:22:20 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 19:36:57 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "parsing.h"
#include "philosophers.h"
#include "setup.h"
#include "simulation.h"
#include "time_management.h"
#include "utils.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

pthread_t	*create_philo_threads(t_data *data_array, t_config *config)
{
	pthread_t	*philo_threads;
	int			i;

	philo_threads = allocate(config->n_philo * sizeof(pthread_t));
	if (philo_threads == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		if (pthread_create(&philo_threads[i], NULL, simulate_philo,
				&data_array[i]) != 0)
			return (NULL);
		i++;
	}
	return (philo_threads);
}

// bool check_for_death() {
//
// }

void	monitor_threads(t_sim_data *sim_data, t_config *config,
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
				pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
			i++;
		}
		if (config->n_meals > 0 && all_philos_met_the_quota)
		{
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
		i++;
	}
}

int	end_simulation(t_data *data_array, t_philo_data *philo_data_array,
		pthread_t *philo_threads)
{
	join_threads(data_array[0].config, philo_threads);
	destroy_mutexes(data_array[0].sim, philo_data_array, data_array[0].config);
	free_stuff(data_array, philo_threads);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_config		*config;
	t_sim_data		*sim_data;
	pthread_t		*philo_threads;
	t_philo_data	*philo_data_array;
	t_data			*data_array;

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
	data_array = create_data_array(config, sim_data, philo_data_array);
	if (data_array == NULL)
		return (EXIT_FAILURE);
	philo_threads = create_philo_threads(data_array, config);
	if (!philo_threads)
		return (EXIT_FAILURE);
	monitor_threads(sim_data, config, philo_data_array);
	return (end_simulation(data_array, philo_data_array, philo_threads));
}
// TODO: Check LEAKS!
