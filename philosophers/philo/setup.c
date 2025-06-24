/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:35:20 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 19:55:42 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "time_management.h"
#include "utils.h"

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
	return (config);
}

t_sim_data	*get_sim_data(t_config *config)
{
	t_sim_data	*sim;
	int			i;

	sim = allocate(sizeof(t_sim_data));
	if (sim == NULL)
		return (NULL);
	*sim = (t_sim_data){.simulation_start_timeval = get_timeval(),
		.forks = allocate(config->n_philo * sizeof(pthread_mutex_t)),
		.meals_had = allocate(config->n_philo * sizeof(int)),
		.meals_had_mutexes = allocate(config->n_philo
			* sizeof(pthread_mutex_t))};
	if (sim->forks == NULL || sim->meals_had_mutexes == NULL
		|| sim->meals_had == NULL)
		return (NULL);
	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_init(&(sim->forks[i]), NULL);
		pthread_mutex_init(&(sim->meals_had_mutexes[i]), NULL);
		pthread_mutex_init(&(sim->death_mutex), NULL);
		pthread_mutex_init(&(sim->quota_mutex), NULL);
		i++;
	}
	return (sim);
}

t_philo_data	*create_philo_data_array(t_config *config, t_sim_data *sim_data)
{
	t_philo_data	*philo_data_array;
	int				i;
	pthread_mutex_t	*mutexes;

	philo_data_array = allocate(config->n_philo * sizeof(t_philo_data));
	mutexes = allocate(config->n_philo * sizeof(pthread_mutex_t));
	if (philo_data_array == NULL || mutexes == NULL)
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
	if (config->n_philo == 1)
		philo_data_array[0].right_fork = NULL;
	return (philo_data_array);
}

t_data	*create_data_array(t_config *config, t_sim_data *sim_data,
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
