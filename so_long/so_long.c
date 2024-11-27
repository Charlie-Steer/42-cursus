/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/27 18:25:18 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define TILE_WIDTH 64

#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"

void move_player(void *player);

int main(int argc, char *argv[])
{
	if (check_if_valid_arguments(argc, argv))
	{
		t_two_ints width_and_height;
		t_map_data map_data;

		width_and_height = get_map_len(argv[1]);
		#if DEBUG >= 1 //! DELETE
			ft_printf("width: %d\nheight: %d\n\n", width_and_height.a, width_and_height.b);
		#endif
		char **map = save_map(argv[1], width_and_height.a, width_and_height.b);

		#if DEBUG >= 1 //! DELETE
			DEBUG_print_map(map, width_and_height.a, width_and_height.b);
		#endif

		map_data = validate_map_and_store_map_data(map, width_and_height.a, width_and_height.b);

		// MLX
		//! MAKE SURE YOU HANDLE ERRORS EVERY TIME YOU GET A POINTER FROM MLX.
		mlx_t *mlx = mlx_init(TILE_WIDTH * map_data.width, TILE_WIDTH * map_data.height, "So Long", 0);
		if (!mlx)
			print_error_free_map_and_exit("mlx_init() error.", map, map_data.height);

		int window_width = mlx->width;
		int window_height = mlx->height;

		#if DEBUG >= 1 //! DELETE
			ft_printf("Window w: %d, h: %d.\n", window_width, window_height);
		#endif

		mlx_image_t* background = mlx_new_image(mlx, mlx->width, mlx->height);
		if (!background || (mlx_image_to_window(mlx, background, 0, 0) < 0))
			print_error_free_map_and_exit("Background creation error.", map, window_height);
		for (int x = 0; x < window_width; x++) {
			for (int y = 0; y < window_height; y++) {
				mlx_put_pixel(background, x, y, 0x000000FF);
			}
		}

		mlx_texture_t *terrain_texture = mlx_load_png("textures/grass.png");
		mlx_texture_t *wall_texture = mlx_load_png("textures/wall.png");
		mlx_texture_t *player_texture = mlx_load_png("textures/blocky_right.png");
		if (!player_texture) {
			ft_printf("WUT?\n");
		}
		mlx_texture_t *collectible_texture = mlx_load_png("textures/chest.png");
		mlx_texture_t *exit_texture = mlx_load_png("textures/door.png");

		mlx_image_t *terrain_image = mlx_texture_to_image(mlx, terrain_texture);
		mlx_image_t *wall_image = mlx_texture_to_image(mlx, wall_texture);
		mlx_image_t *player_image = mlx_texture_to_image(mlx, player_texture);
		mlx_image_t *collectible_image = mlx_texture_to_image(mlx, collectible_texture);
		mlx_image_t *exit_image = mlx_texture_to_image(mlx, exit_texture);

		char *error_message = "Couldn't resize image.";
		if (!mlx_resize_image(terrain_image, TILE_WIDTH, TILE_WIDTH))
			print_error_free_map_and_exit(error_message, map, map_data.height);
		if (!mlx_resize_image(wall_image, TILE_WIDTH, TILE_WIDTH))
			print_error_free_map_and_exit(error_message, map, map_data.height);
		if (!mlx_resize_image(player_image, TILE_WIDTH, TILE_WIDTH))
			print_error_free_map_and_exit(error_message, map, map_data.height);
		if (!mlx_resize_image(collectible_image, TILE_WIDTH, TILE_WIDTH))
			print_error_free_map_and_exit(error_message, map, map_data.height);
		if (!mlx_resize_image(exit_image, TILE_WIDTH, TILE_WIDTH))
			print_error_free_map_and_exit(error_message, map, map_data.height);

		// Draw tiles
		int i = 0;
		while (i < map_data.height) {
			int j = 0;
			while (j < map_data.width) {
				char tile_char = map[i][j];
				if (tile_char == '0')
					mlx_image_to_window(mlx, terrain_image, TILE_WIDTH * j, TILE_WIDTH * i);
				else if (tile_char == '1')
					mlx_image_to_window(mlx, wall_image, TILE_WIDTH * j, TILE_WIDTH * i);
				else if (tile_char == 'E')
					mlx_image_to_window(mlx, exit_image, TILE_WIDTH * j, TILE_WIDTH * i);
				else if (tile_char == 'C') {
					mlx_image_to_window(mlx, terrain_image, TILE_WIDTH * j, TILE_WIDTH * i);
					mlx_image_to_window(mlx, collectible_image, TILE_WIDTH * j, TILE_WIDTH * i);
				}
				else if (tile_char == 'P') {
					mlx_image_to_window(mlx, terrain_image, TILE_WIDTH * j, TILE_WIDTH * i);
					mlx_image_to_window(mlx, player_image, TILE_WIDTH * j, TILE_WIDTH * i);
				}
				j++;
			}
			i++;
		}
		
		// mlx_resize_image(terrain_image, window_width, window_height);

		mlx_image_to_window(mlx, terrain_image, 0, 0);
		mlx_set_instance_depth(player_image->instances, 100);

		mlx_loop_hook(mlx, *move_player, (void *)(player_image->instances));

		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
}

void move_player(void *player_param) {
	mlx_instance_t *player = (mlx_instance_t *)player_param;
	sleep(1);
	player->x += TILE_WIDTH;
}