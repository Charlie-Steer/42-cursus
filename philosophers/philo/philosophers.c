/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:22:20 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/25 11:13:56 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "monitoring.h"
#include "parsing.h"
#include "philosophers.h"
#include "setup.h"
#include "simulation.h"
#include "utils.h"
#include <stdlib.h>

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

int	main(int argc, char *argv[])
{
	t_config		*config;
	t_sim_data		*sim_data;
	pthread_t		*philo_threads;
	t_philo_data	*philo_data_array;
	t_data			*data_array;

	// TODO: Check SUBJECT!
	// TODO: Check NORMINETTE!
	// TODO: Check LEAKS!
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
