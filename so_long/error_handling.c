/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:12:36 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/21 09:59:19 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_error(char *error_message) {
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void print_error_and_exit(char *error_message) {
	print_error(error_message);
	exit(1);
}

void print_error_free_map_and_exit(char *error_message, char **map, int height) {
	print_error(error_message);
	int i = 0;
	while (i < height) {
		if (map[i]) {
			free(map[i]);
		}
		i++;
	}
	if (map)
		free(map);
	exit(1);
}

void print_error_free_maps_and_exit(char *error_message, char **map1,
	char **map2, int height) {
	int i;

	print_error(error_message);
	if (map1) {
		i = 0;
		while (i < height) {
			if (map1[i]) {
				free(map1[i]);
			}
			i++;
		}
		free(map1);
	}

	if (map2) {
		i = 0;
		while (i < height) {
			if (map2[i]) {
				free(map2[i]);
			}
			i++;
		}
		free(map2);
	}
	exit(1);
}