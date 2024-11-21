/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:14:32 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/21 10:01:22 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void DEBUG_print_map(char **map, int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ft_printf("%c", map[i][j]);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void DEBUG_print_maps(char **map1, char** map2, int width, int height) {
	ft_printf("map1:\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ft_printf("%c", map1[i][j]);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
	ft_printf("map2:\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ft_printf("%c", map2[i][j]);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}