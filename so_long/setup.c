/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:15:08 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/04 21:08:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_t	*init_mlx(t_game_data game_data)
{
	mlx_t	*mlx;

	// WARNING: MAKE SURE YOU HANDLE ERRORS EVERY TIME YOU GET A POINTER FROM MLX.
	mlx = mlx_init(TILE_WIDTH * game_data.cols, TILE_WIDTH * game_data.rows,
			"So Long", 0);
	if (!mlx)
		print_error_free_map_and_exit("mlx_init() error.", game_data.map,
			game_data.rows);
	return (mlx);
}

void	create_background(t_game_data gd)
{
	int			window_width;
	int			window_height;
	mlx_image_t	*background;

	window_width = gd.mlx->width;
	window_height = gd.mlx->height;
	background = mlx_new_image(gd.mlx, window_width, window_height);
	if (!background || (mlx_image_to_window(gd.mlx, background, 0, 0) < 0))
		print_error_free_map_and_exit("Background creation error.", gd.map,
			window_height);
	for (int x = 0; x < window_width; x++)
	{
		for (int y = 0; y < window_height; y++)
		{
			mlx_put_pixel(background, x, y, 0x000000FF);
		}
	}
}

t_images	create_images(mlx_t *mlx)
{
	mlx_texture_t	*terrain_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*exit_texture;
	t_images		images;

	// WARNING: PROBABLY NEED TO HANDLE ERRORS.
	terrain_texture = mlx_load_png("textures/grass.png");
	wall_texture = mlx_load_png("textures/wall.png");
	player_texture = mlx_load_png("textures/blocky_right.png");
	collectible_texture = mlx_load_png("textures/chest.png");
	exit_texture = mlx_load_png("textures/door.png");
	// WARNING: This is not handled properly.
	if (!(terrain_texture && wall_texture && player_texture
			&& collectible_texture && exit_texture))
		ft_printf("WUT?\n");
	images.terrain_image = mlx_texture_to_image(mlx, terrain_texture);
	images.wall_image = mlx_texture_to_image(mlx, wall_texture);
	images.player_image = mlx_texture_to_image(mlx, player_texture);
	images.collectible_image = mlx_texture_to_image(mlx, collectible_texture);
	images.exit_image = mlx_texture_to_image(mlx, exit_texture);
	return (images);
}

void	resize_images(t_game_data game_data)
{
	char		**map;
	char		*error_message;
	t_images	images;

	map = game_data.map;
	images = game_data.images;
	error_message = "Couldn't resize image.";
	if (!mlx_resize_image(images.terrain_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.wall_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.player_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.collectible_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.exit_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
}
