/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:56:17 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/25 12:15:12 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "time_management.h"
#include <unistd.h>
#include <stdio.h>

static bool	check_for_death(t_philo_data *philo_data_array,
		t_sim_data *sim_data, t_config *config)
{
	int	i;

	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_lock(&(philo_data_array->last_meal_time_mutex[i]));
		if (get_time_us(sim_data)
			- philo_data_array[i].last_meal_time_us >= config->death_time_us)
		{
			pthread_mutex_unlock(&(philo_data_array->last_meal_time_mutex[i]));
			pthread_mutex_lock(&sim_data->death_mutex);
			sim_data->some_philo_is_dead = true;
			philo_data_array[i].is_dead = true;
			usleep(1000);
			printf("%05ld %d died\n", get_time_ms(sim_data), i + 1);
			pthread_mutex_unlock(&sim_data->death_mutex);
			return (true);
		}
		pthread_mutex_unlock(&(philo_data_array->last_meal_time_mutex[i]));
		i++;
	}
	return (false);
}

static bool	check_for_quota_met(t_sim_data *sim_data, t_config *config)
{
	int	i;

	i = 0;
	while (i < config->n_philo)
	{
		pthread_mutex_lock(&(sim_data->meals_had_mutexes[i]));
		if (config->n_meals > 0 && sim_data->meals_had[i] < config->n_meals)
		{
			pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
			return (false);
		}
		else
			pthread_mutex_unlock(&(sim_data->meals_had_mutexes[i]));
		i++;
	}
	return (true);
}

void	monitor_threads(t_sim_data *sim_data, t_config *config,
		t_philo_data *philo_data_array)
{
	while (true)
	{
		if (check_for_death(philo_data_array, sim_data, config))
		{
			return ;
		}
		if (config->n_meals > 0 && check_for_quota_met(sim_data, config))
		{
			pthread_mutex_lock(&sim_data->quota_mutex);
			sim_data->quota_has_been_met = true;
			pthread_mutex_unlock(&sim_data->quota_mutex);
			return ;
		}
		usleep(1000);
	}
}
