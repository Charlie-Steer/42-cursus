/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:21:08 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:25:23 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "pthread.h"
# include "stdbool.h"
# include "sys/time.h"

typedef struct s_sim_data
{
	struct timeval	simulation_start_timeval;
	long			simulation_time;
	pthread_mutex_t	*forks;
	bool			some_philo_is_dead;
	bool			quota_has_been_met;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	quota_mutex;
	int				*meals_had;
	pthread_mutex_t	*meals_had_mutexes;
}					t_sim_data;

typedef struct s_philo_data
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time_us;
	pthread_mutex_t	*last_meal_time_mutex;
}					t_philo_data;

typedef struct s_config
{
	int				n_philo;
	int				death_time_us;
	int				eat_time_us;
	int				sleep_time_us;
	int				n_meals;
}					t_config;

typedef struct s_data
{
	t_config		*config;
	t_sim_data		*sim;
	t_philo_data	*philo;
}					t_data;

typedef struct s_threads_and_data
{
	pthread_t		*philo_threads;
	t_data			*data;
}					t_threads_and_data;

#endif
