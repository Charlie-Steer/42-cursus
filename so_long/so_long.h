/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:39 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/03 19:47:31 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Add include protection.

#define TILE_WIDTH 32

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <assert.h>
# include <fcntl.h>
# include <stdbool.h>

/* typedef struct s_two_ints
{
	int			a;
	int			b;
}				t_two_ints; */

typedef struct
{
	int			x;
	int			y;
}				t_position;

typedef struct
{
	int			rows;
	int			cols;
}				t_rows_and_cols;

typedef struct
{
	mlx_image_t	*terrain_image;
	mlx_image_t	*wall_image;
	mlx_image_t	*exit_image;
	mlx_image_t	*collectible_image;
	mlx_image_t	*player_image;
}				t_images;

typedef struct
{
	int			rows;
	int			cols;

	int			player_x_pos;
	int			player_y_pos;
	int			player_amount;
	int			exit_amount;
	int			collectible_amount;

	char		**map;

	// WARN: Has been changed to non-pointer type.
	t_images	images;
	mlx_t		*mlx;
}				t_game_data;

typedef struct
{
	char		**map;
	t_game_data	data;
}				t_map_and_data;

enum			direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

void			print_error(char *error_message);
void			print_error_and_exit(char *error_message);
void			print_error_free_map_and_exit(char *error_message, char **map,
					int rows);
void			print_error_free_maps_and_exit(char *error_message, char **map1,
					char **map2, int rows);
void			free_map(char **map, int rows);

int				check_if_valid_arguments(int argc, char *argv[]);

void			DEBUG_print_map(char **map, int cols, int rows);
void			DEBUG_print_maps(char **map1, char **map2, int cols, int rows);

#endif
