/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:39 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 16:27:09 by cargonz2         ###   ########.fr       */
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
	int				x;
	int				y;
}					t_position;

typedef struct
{
	int				rows;
	int				cols;
}					t_rows_and_cols;

typedef struct
{
	mlx_texture_t	*terrain;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
}					t_textures;

typedef struct
{
	mlx_image_t		*terrain;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
}					t_images;

typedef struct
{
	int				rows;
	int				cols;

	int				player_x_pos;
	int				player_y_pos;
	int				player_amount;
	int				exit_amount;
	int				collectible_amount;

	char			**map;

	t_images		images;
	mlx_t			*mlx;
}					t_game_data;

/* typedef struct
{
	char		**map;
	t_game_data	data;
}				t_map_and_data; */

enum				direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

#endif
