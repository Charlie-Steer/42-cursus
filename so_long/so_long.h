/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:39 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/28 18:44:12 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <assert.h>
#include <stdbool.h>

typedef struct s_two_ints {
	int a;
	int b;
} t_two_ints;

typedef struct s_images {
	mlx_image_t *terrain_image;
	mlx_image_t *wall_image;
	mlx_image_t *exit_image;
	mlx_image_t *collectible_image;
	mlx_image_t *player_image;
} t_images;

typedef struct s_map_data {
	int width;
	int height;

	int player_x_pos;
	int player_y_pos;
	int player_amount;
	int exit_amount;
	int collectible_amount;

	t_images *images;
} t_map_data;

typedef struct s_map_and_data {
	char **map;
	t_map_data data;
} t_map_and_data;

void print_error(char *error_message);
void print_error_and_exit(char *error_message);
void print_error_free_map_and_exit(char *error_message, char **map, int height);
void print_error_free_maps_and_exit(char *error_message, char **map1, char**map2, int height);

int check_if_valid_arguments(int argc, char *argv[]);

t_map_data record_map_character(char c, t_map_data map_data, char **map, t_two_ints coords);
t_map_data validate_map_and_store_map_data(char **map, int width, int height);
t_two_ints get_map_len(char *map_file_path);
char **save_map(char *map_file_path, int width, int height);

void DEBUG_print_map(char **map, int width, int height);
void DEBUG_print_maps(char **map1, char** map2, int width, int height);

#endif
