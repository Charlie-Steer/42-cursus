/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:39 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/20 15:03:28 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "MLX42.h"
#include "libft/libft.h"
#include "fcntl.h"
#include "stdio.h"
#include <assert.h>
#include <stdbool.h>

typedef struct s_two_ints {
	int a;
	int b;
} t_two_ints;

typedef struct s_map_data {
	int width;
	int height;

	int player_x_pos;
	int player_y_pos;
	int player_amount;
	int exit_amount;
	int collectible_amount;
} t_map_data;

void print_error(char *error_message);
void print_error_and_exit(char *error_message);
void print_error_free_map_and_exit(char *error_message, char **map, int height);

int check_if_valid_arguments(int argc, char *argv[]);

t_map_data record_map_character(char c, t_map_data map_data, char **map, t_two_ints coords);
t_map_data validate_map_and_store_map_data(char **map, int width, int height);
t_two_ints get_map_len(char *map_file_path);
char **save_map(char *map_file_path, int width, int height);

void DEBUG_print_map(char **map, int width, int height);

#endif
