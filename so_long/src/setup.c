/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:15:08 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/13 18:46:51 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "error_handling_2.h"
#include "so_long.h"

mlx_t	*init_mlx(t_game_data game_data)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(TILE_WIDTH * game_data.cols, TILE_WIDTH * game_data.rows,
			"So Long", true);
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
	int			x;
	int			y;

	window_width = gd.mlx->width;
	window_height = gd.mlx->height;
	background = mlx_new_image(gd.mlx, window_width, window_height);
	if (!background || (mlx_image_to_window(gd.mlx, background, 0, 0) < 0))
		terminate_program_no_heap_gd(gd, "Background creation error.");
	x = 0;
	while (x < window_width)
	{
		y = 0;
		while (y < window_height)
		{
			mlx_put_pixel(background, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
}

t_textures	create_textures(t_game_data gd)
{
	t_textures	textures;

	textures.terrain = mlx_load_png("textures/grass.png");
	textures.wall = mlx_load_png("textures/wall.png");
	textures.player = mlx_load_png("textures/blocky_right.png");
	textures.collectible = mlx_load_png("textures/chest.png");
	textures.exit = mlx_load_png("textures/door.png");
	if (!(textures.terrain && textures.wall && textures.player
			&& textures.collectible && textures.exit))
		terminate_program_no_heap_gd(gd, "Couldn't create textures.");
	return (textures);
}

t_images	create_images(t_game_data gd)
{
	t_images	images;
	t_textures	textures;

	textures = gd.textures;
	images.terrain = mlx_texture_to_image(gd.mlx, textures.terrain);
	images.wall = mlx_texture_to_image(gd.mlx, textures.wall);
	images.player = mlx_texture_to_image(gd.mlx, textures.player);
	images.collectible = mlx_texture_to_image(gd.mlx, textures.collectible);
	images.exit = mlx_texture_to_image(gd.mlx, textures.exit);
	if (!(images.terrain && images.wall && images.player && images.collectible
			&& images.exit))
		terminate_program_no_heap_gd(gd, "Couldn't create images.");
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
	if (!mlx_resize_image(images.terrain, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.wall, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.player, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.collectible, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
	if (!mlx_resize_image(images.exit, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.rows);
}
