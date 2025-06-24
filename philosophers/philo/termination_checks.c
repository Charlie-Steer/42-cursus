/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:19:58 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 19:25:01 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdbool.h>

bool	is_philo_dead(t_sim_data *sim_data, t_philo_data *philo,
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

bool	is_quota_met(t_sim_data *sim_data, t_philo_data *philo,
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
