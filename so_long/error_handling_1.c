/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:12:36 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 13:52:49 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *error_message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	free_map(char **map, int rows)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < rows)
		{
			if (map[i] != NULL)
				free(map[i]);
			i++;
		}
		free(map);
	}
}

void	print_error_and_exit(char *error_message)
{
	print_error(error_message);
	exit(1);
}

void	print_error_free_map_and_exit(char *error_message, char **map, int rows)
{
	print_error(error_message);
	free_map(map, rows);
	exit(1);
}

void	print_error_free_maps_and_exit(char *error_message, char **map1,
		char **map2, int rows)
{
	print_error(error_message);
	free_map(map1, rows);
	free_map(map2, rows);
	exit(1);
}
