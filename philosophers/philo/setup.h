/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:48:02 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:49:59 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "philosophers.h"

t_config		*get_config(int argc, char *argv[]);
t_sim_data		*get_sim_data(t_config *config);
t_philo_data	*create_philo_data_array(t_config *config,
					t_sim_data *sim_data);
t_data			*create_data_array(t_config *config, t_sim_data *sim_data,
					t_philo_data *philo_data_array);

#endif
