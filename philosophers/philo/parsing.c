/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:06 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:47:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdbool.h"
#include "stdio.h"

bool	check_if_positive_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '\0')
		return (true);
	else
		return (false);
}

bool	check_if_arguments_are_valid(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_if_positive_number(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	are_arguments_valid(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Format: philo number_of_philosophers time_to_die time_to_eat "
				"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (false);
	}
	else if (!check_if_arguments_are_valid(argc, argv))
	{
		printf("ERROR: All arguments must be positive numbers.\n");
		return (false);
	}
	else
		return (true);
}
