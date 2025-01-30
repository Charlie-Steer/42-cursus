/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:15:08 by cargonz2          #+#    #+#             */
/*   Updated: 2025/01/30 12:21:19 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_data	create_game_data(char *map_path)
{
	t_two_ints	width_and_height;
	t_game_data	game_data;
	char		**map;

	width_and_height = get_map_len(map_path);
	map = save_map(map_path, width_and_height.a, width_and_height.b);
	game_data = validate_map_and_store_map_data(map, width_and_height.a,
			width_and_height.b);
	game_data.map = map;
	return (game_data);
}

mlx_t	*init_mlx(t_game_data game_data)
{
	mlx_t	*mlx;

	// WARNING: MAKE SURE YOU HANDLE ERRORS EVERY TIME YOU GET A POINTER FROM MLX.
	mlx = mlx_init(TILE_WIDTH * game_data.width, TILE_WIDTH * game_data.height,
			"So Long", 0);
	if (!mlx)
		print_error_free_map_and_exit("mlx_init() error.", game_data.map,
			game_data.height);
	return (mlx);
}

void	create_background(t_game_data game_data)
{
	mlx_t		*mlx;
	char		**map;
	int			window_width;
	int			window_height;
	mlx_image_t	*background;

	mlx = game_data.mlx;
	map = game_data.map;
	window_width = mlx->width;
	window_height = mlx->height;
	background = mlx_new_image(mlx, window_width, window_height);
	if (!background || (mlx_image_to_window(mlx, background, 0, 0) < 0))
		print_error_free_map_and_exit("Background creation error.", map,
			window_height);
	for (int x = 0; x < window_width; x++)
	{
		for (int y = 0; y < window_height; y++)
		{
			mlx_put_pixel(background, x, y, 0x000000FF);
		}
	}
}

t_game_data	create_images(t_game_data game_data)
{
	mlx_texture_t	*terrain_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*exit_texture;

	// WARNING: PROBABLY NEED TO HANDLE ERRORS.
	terrain_texture = mlx_load_png("textures/grass.png");
	wall_texture = mlx_load_png("textures/wall.png");
	player_texture = mlx_load_png("textures/blocky_right.png");
	if (!player_texture)
	{
		ft_printf("WUT?\n");
	}
	collectible_texture = mlx_load_png("textures/chest.png");
	exit_texture = mlx_load_png("textures/door.png");
	game_data.images = malloc(sizeof(t_images));
	game_data.images->terrain_image = mlx_texture_to_image(game_data.mlx,
			terrain_texture);
	game_data.images->wall_image = mlx_texture_to_image(game_data.mlx,
			wall_texture);
	game_data.images->player_image = mlx_texture_to_image(game_data.mlx,
			player_texture);
	game_data.images->collectible_image = mlx_texture_to_image(game_data.mlx,
			collectible_texture);
	game_data.images->exit_image = mlx_texture_to_image(game_data.mlx,
			exit_texture);
	ft_printf("height: %d\n", game_data.images->terrain_image->height);
	return (game_data);
}

void	resize_images(t_game_data game_data)
{
	char		**map;
	t_images	*images;
	char		*error_message;

	map = game_data.map;
	images = game_data.images;
	error_message = "Couldn't resize image.";
	ft_printf("TEST ALPHA\n");
	ft_printf("height: %d\n", game_data.images->terrain_image->height);
	if (!mlx_resize_image(images->terrain_image, TILE_WIDTH, TILE_WIDTH))
	{
		ft_printf("wut?\n");
		print_error_free_map_and_exit(error_message, map, game_data.height);
	}
	ft_printf("TEST BETA\n");
	if (!mlx_resize_image(images->wall_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.height);
	if (!mlx_resize_image(images->player_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.height);
	if (!mlx_resize_image(images->collectible_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.height);
	if (!mlx_resize_image(images->exit_image, TILE_WIDTH, TILE_WIDTH))
		print_error_free_map_and_exit(error_message, map, game_data.height);
}
