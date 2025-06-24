/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:22:25 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 19:23:57 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philosophers.h"

int		manage_single_philo(t_philo_data *philo, t_sim_data *sim);
int		grab_forks(t_philo_data *philo, t_config *config, t_sim_data *sim);
int		eat(t_philo_data *philo, t_sim_data *sim, t_config *config);
int		go_sleep(t_philo_data *philo, t_sim_data *sim, t_config *config);
void	*simulate_philo(void *args);

#endif
