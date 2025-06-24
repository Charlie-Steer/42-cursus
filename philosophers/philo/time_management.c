/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:52:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time_ms(t_sim_data *sim_data)
{
	struct timeval	tv;
	long			current_time;
	long			now_secs;
	long			now_usecs;

	gettimeofday(&tv, NULL);
	now_secs = tv.tv_sec - sim_data->simulation_start_timeval.tv_sec;
	now_usecs = tv.tv_usec - sim_data->simulation_start_timeval.tv_usec;
	if (now_usecs < 0)
	{
		now_secs--;
		now_usecs += 1000000;
	}
	current_time = now_secs * 1000000 + now_usecs;
	current_time /= 1000;
	return (current_time);
}

long	get_time_us(t_sim_data *sim_data)
{
	struct timeval	tv;
	long			now_secs;
	long			now_usecs;
	long			current_time;

	gettimeofday(&tv, NULL);
	now_secs = tv.tv_sec - sim_data->simulation_start_timeval.tv_sec;
	now_usecs = tv.tv_usec - sim_data->simulation_start_timeval.tv_usec;
	if (now_usecs < 0)
	{
		now_secs--;
		now_usecs += 1000000;
	}
	current_time = now_secs * 1000000 + now_usecs;
	return (current_time);
}

struct timeval	get_timeval(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv);
}
