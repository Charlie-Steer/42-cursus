/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:22:20 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 18:58:21 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "parsing.h"
#include "philosophers.h"
#include "setup.h"
#include "time_management.h"
#include "utils.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

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
	pthread_mutex_lock(&(philo->last_meal_time_mutex[0]));
	philo->last_meal_time_us = get_time_us(sim);
	pthread_mutex_unlock(&(philo->last_meal_time_mutex[0]));
	pthread_mutex_lock(&(sim->meals_had_mutexes[philo->id - 1]));
	sim->meals_had[philo->id - 1] += 1;
	pthread_mutex_unlock(&(sim->meals_had_mutexes[philo->id - 1]));
	printf("%05ld %d is eating\n", get_time_ms(sim), philo->id);
	usleep(config->eat_time_us);
	if (is_philo_dead(sim, philo, true) || is_quota_met(sim, philo, true))
		return (-1);
	else
		return (0);
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
		// if (philo->id % 2 != 0)
		usleep(200);
	}
	return (NULL);
}

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
			}
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
	infinite_check_for_death(sim_data, config, philo_data_array);
	join_threads(config, philo_threads);
	destroy_mutexes(sim_data, philo_data_array, config);
	free_stuff(data_array, philo_threads);
	return (EXIT_SUCCESS);
}
// TODO: Check LEAKS!
