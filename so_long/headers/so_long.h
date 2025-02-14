/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:39 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/14 13:39:36 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_WIDTH 64

# include "MLX42.h"
# include "libft.h"
# include <assert.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_rows_and_cols
{
	int				rows;
	int				cols;
}					t_rows_and_cols;

typedef struct s_textures
{
	mlx_texture_t	*terrain;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
}					t_textures;

typedef struct s_images
{
	mlx_image_t		*terrain;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
}					t_images;

typedef struct s_game_data
{
	int				rows;
	int				cols;

	int				player_x_pos;
	int				player_y_pos;
	int				player_amount;
	int				exit_amount;
	int				collectible_amount;

	int				n_moves;

	char			**map;

	t_textures		textures;
	t_images		images;
	mlx_t			*mlx;
}					t_game_data;

enum				e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

#endif