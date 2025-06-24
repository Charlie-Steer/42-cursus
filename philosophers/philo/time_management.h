/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:50:33 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:52:52 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_MANAGEMENT_H
# define TIME_MANAGEMENT_H

# include "philosophers.h"

long			get_time_ms(t_sim_data *sim_data);
long			get_time_us(t_sim_data *sim_data);
struct timeval	get_timeval(void);

#endif
