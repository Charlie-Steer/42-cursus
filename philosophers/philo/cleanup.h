/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:43:57 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 19:53:31 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "philosophers.h"
# include <pthread.h>

void	free_stuff(t_data *data_array, pthread_t *philo_threads);
void	destroy_mutexes(t_sim_data *sim_data, t_philo_data *philo_data_array,
			t_config *config);
void	join_threads(t_config *config, pthread_t *philo_threads);
int		end_simulation(t_data *data_array, t_philo_data *philo_data_array,
			pthread_t *philo_threads);

#endif
