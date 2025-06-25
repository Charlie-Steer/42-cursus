/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:17:41 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/25 12:31:08 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "termination_checks.h"
#include "time_management.h"
#include <stdio.h>
#include <unistd.h>

int	manage_single_philo(t_philo_data *philo, t_sim_data *sim)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
		return (-1);
	printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
	while (true)
	{
		if (is_philo_dead(sim, philo, false))
			return (-1);
		usleep(1000);
	}
}

int	grab_forks(t_philo_data *philo, t_config *config, t_sim_data *sim)
{
	if (config->n_philo == 1)
		return (manage_single_philo(philo, sim));
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
			return (-1);
		printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
		pthread_mutex_lock(philo->right_fork);
		if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
			return (-1);
		printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
			return (-1);
		printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
		pthread_mutex_lock(philo->left_fork);
		if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
			return (-1);
		printf("%05ld %d has taken a fork\n", get_time_ms(sim), philo->id);
	}
	return (0);
}

int	eat(t_philo_data *philo, t_sim_data *sim, t_config *config)
{
	pthread_mutex_lock(&sim->death_mutex);
	pthread_mutex_lock(&(philo->last_meal_time_mutex[0]));
	philo->last_meal_time_us = get_time_us(sim);
	pthread_mutex_unlock(&(philo->last_meal_time_mutex[0]));
	pthread_mutex_lock(&(sim->meals_had_mutexes[philo->id - 1]));
	sim->meals_had[philo->id - 1] += 1;
	pthread_mutex_unlock(&(sim->meals_had_mutexes[philo->id - 1]));
	printf("%05ld %d is eating\n", get_time_ms(sim), philo->id);
	pthread_mutex_unlock(&sim->death_mutex);
	usleep(config->eat_time_us);
	if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	go_sleep(t_philo_data *philo, t_sim_data *sim, t_config *config)
{
	printf("%05ld %d is sleeping\n", get_time_ms(sim), philo->id);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	usleep(config->sleep_time_us);
	if (is_philo_dead(sim, philo, false) || is_quota_met(sim, philo, false))
		return (-1);
	else
		return (0);
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
		if (is_philo_dead(sim, philo, false) || is_quota_met(sim, philo, false))
			return (NULL);
		if (grab_forks(philo, config, sim) == -1)
			return (NULL);
		if (eat(philo, sim, config) == -1)
			return (NULL);
		if (go_sleep(philo, sim, config) == -1)
			return (NULL);
		printf("%05ld %d is thinking\n", get_time_ms(sim), philo->id);
		if (philo->id % 2 != 0)
			usleep(1000);
	}
	return (NULL);
}
