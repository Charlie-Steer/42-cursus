/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination_checks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:25:03 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 19:34:57 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINATION_CHECKS_H
# define TERMINATION_CHECKS_H

# include "philosophers.h"

bool	is_philo_dead(t_sim_data *sim_data, t_philo_data *philo,
			bool is_during_meal);
bool	is_quota_met(t_sim_data *sim_data, t_philo_data *philo,
			bool is_during_meal);

#endif
