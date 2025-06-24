/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:37:41 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:44:58 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	destroy_mutexes(t_sim_data *sim_data, t_philo_data *philo_data_array,
		t_config *config)
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

void	free_stuff(t_data *data_array, pthread_t *philo_threads)
{
	free(data_array->config);
	free(data_array->sim->forks);
	free(data_array->sim->meals_had);
	free(data_array->sim->meals_had_mutexes);
	free(data_array->sim);
	free(data_array->philo->last_meal_time_mutex);
	free(data_array->philo);
	free(data_array);
	free(philo_threads);
}
