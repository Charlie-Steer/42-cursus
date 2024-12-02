/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2024/12/02 21:08:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/src/printf/ft_printf.h"
# define TILE_WIDTH 64

#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <limits.h>

void move_player(void *param);
void my_key_hook(mlx_key_data_t key_data, void *param);
void pick_up_collectible(void *param);
void check_and_pick_up_collectibles(void *param);
void draw_player_and_collectible_tiles(mlx_t *mlx, t_images *images, char **map, t_map_data map_data);
void draw_terrain_and_wall_tiles(mlx_t *mlx, t_images *images, char **map, t_map_data map_data);

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
		map_data.map = map;

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

		t_images *images = malloc(sizeof(t_images));
		images->terrain_image = terrain_image;
		images->wall_image = wall_image;
		images->player_image = player_image;
		images->exit_image = exit_image;
		images->collectible_image = collectible_image;
		draw_terrain_and_wall_tiles(mlx, images, map, map_data);
		draw_player_and_collectible_tiles(mlx, images, map, map_data);

		
		// mlx_resize_image(terrain_image, window_width, window_height);

		// mlx_set_instance_depth(player_image->instances, 100);

		// mlx_loop_hook(mlx, *move_player, (void *)(player_image->instances));

		map_data.images = images;
		t_map_data *heap_map_data = malloc(sizeof(t_map_data)); //! MUST BE HANDLED
		*heap_map_data = map_data;
		ft_printf("%p\n", map_data.images);
		ft_printf("%p\n", heap_map_data->images);
		mlx_loop_hook(mlx, *check_and_pick_up_collectibles, (void *)(heap_map_data));
		mlx_key_hook(mlx, *my_key_hook, (void *)(heap_map_data));

		mlx_loop(mlx);
		mlx_terminate(mlx);
		free(images); //? Does it work as intended?
		//! Free_map and map_data.
	}
}

void check_and_pick_up_collectibles(void *param) {
	t_map_data *heap_map_data = (t_map_data *)param;
	// ft_printf("x: %d, y: %d\n", heap_map_data->player_x_pos, heap_map_data->player_y_pos);
	t_images *images = heap_map_data->images;

	mlx_image_t *player_image = images->player_image;
	mlx_image_t *collectible_image = images->collectible_image;
	int	i;

	i = 0;
	// ft_printf("count: %d\n", collectible_image->count);
	// ft_printf("player: %d, %d\n", player_image->instances[0].x, player_image->instances[0].y);
	while (i < collectible_image->count) {
		// ft_printf("collectible[%d]: %d, %d\n", i, collectible_image->instances[i].x, collectible_image->instances[i].y);
		if (collectible_image->instances != NULL
			&& collectible_image->instances[i].enabled
			&& player_image->instances[0].x == collectible_image->instances[i].x
			&& player_image->instances[0].y == collectible_image->instances[i].y) {
			collectible_image->instances[i].enabled = false;
			heap_map_data->collectible_amount -= 1;
			ft_printf("collectibles remaining: %d\n", heap_map_data->collectible_amount);
		}
		i++;
	}
}

// void pick_up_collectible() {
// 	mlx_image_t *collectible_image = param;
// 	mlx_instance_t *collectibles = collectible_image->instances;

// 	// collectible_image->instances[0].enabled = !(collectible_image->instances[0].enabled);
// 	int i = 0;
// 	// ft_printf("count: %d\n", collectible_image->count);
// 	while (i < collectible_image->count) {
// 		// ft_printf("%d\n", i);
// 		// collectibles[i].enabled = false;
// 		i++;
// 	}
// }

void my_key_hook(mlx_key_data_t key_data, void *param) {
	t_map_data *heap_map_data = (t_map_data *)param;
	mlx_instance_t *player = heap_map_data->images->player_image->instances;

	// ft_printf("x: %d, y: %d\n", heap_map_data->map[1][5], 0);
	// ft_printf(" %c \n", heap_map_data->map[heap_map_data->player_y_pos-1][heap_map_data->player_x_pos]);
	// ft_printf("%c %c\n", heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos-1],
	// 	heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos+1]);
	// ft_printf(" %c \n", heap_map_data->map[heap_map_data->player_y_pos+1][heap_map_data->player_x_pos]);
	// ft_printf("%c\n", heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos]);
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos - 1][heap_map_data->player_x_pos] != '1') {
		player->y -= TILE_WIDTH;
		heap_map_data->player_y_pos -= 1;
	}
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos - 1] != '1') {
		player->x -= TILE_WIDTH;
		heap_map_data->player_x_pos -= 1;
	}
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos + 1][heap_map_data->player_x_pos] != '1') {
		player->y += TILE_WIDTH;
		heap_map_data->player_y_pos += 1;
	}
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos + 1] != '1') {
		player->x += TILE_WIDTH;
		heap_map_data->player_x_pos += 1;
	}
}

void draw_terrain_and_wall_tiles(mlx_t *mlx, t_images *images, char **map, t_map_data map_data) {
	// char **map = map_and_data.map;
	// t_map_data map_data = map_and_data.data;
	// Draw tiles
	int i = 0;
	int player_x = 0;
	int player_y = 0;
	while (i < map_data.height) {
		int j = 0;
		while (j < map_data.width) {
			char tile_char = map[i][j];
			if (tile_char == '0' || tile_char == 'C' || tile_char == 'P')
				mlx_image_to_window(mlx, images->terrain_image, TILE_WIDTH * j, TILE_WIDTH * i);
			else if (tile_char == '1')
				mlx_image_to_window(mlx, images->wall_image, TILE_WIDTH * j, TILE_WIDTH * i);
			else if (tile_char == 'E')
				mlx_image_to_window(mlx, images->exit_image, TILE_WIDTH * j, TILE_WIDTH * i);
			j++;
		}
		i++;
	}
	// mlx_image_to_window(mlx, images.terrain_image, TILE_WIDTH * player_x, TILE_WIDTH * player_y);
	// mlx_image_to_window(mlx, images.player_image, TILE_WIDTH * player_x, TILE_WIDTH * player_y);
}

void draw_player_and_collectible_tiles(mlx_t *mlx, t_images *images, char **map, t_map_data map_data) {
	int i = 0;
	int player_x = 0;
	int player_y = 0;
	while (i < map_data.height) {
		int j = 0;
		while (j < map_data.width) {
			char tile_char = map[i][j];
			if (tile_char == 'C')
				mlx_image_to_window(mlx, images->collectible_image, TILE_WIDTH * j, TILE_WIDTH * i);
			else if (tile_char == 'P')
				mlx_image_to_window(mlx, images->player_image, TILE_WIDTH * j, TILE_WIDTH * i);
			j++;
		}
		i++;
	}
}