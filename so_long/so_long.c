/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2025/01/30 12:19:40 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/src/printf/ft_printf.h"
#include "so_long.h"
#include <limits.h>

void	my_key_hook(mlx_key_data_t key_data, void *param);
void	pick_up_collectible(void *param);
void	check_and_pick_up_collectibles(void *param);
void	draw_player_and_collectible_tiles(mlx_t *mlx, t_images *images,
			char **map, t_game_data map_data);
void	draw_terrain_and_wall_tiles(mlx_t *mlx, t_images *images, char **map,
			t_game_data map_data);
void	terminate_game(t_game_data *heap_map_data, char *termination_message);

int	main(int argc, char *argv[])
{
	t_game_data	game_data;
	mlx_t		*mlx;
	char		**map;
	t_images	*images;
	t_game_data	*heap_map_data;

	if (check_if_valid_arguments(argc, argv))
	{
		game_data = create_game_data(argv[1]);
		// MLX
		//! MAKE SURE YOU HANDLE ERRORS EVERY TIME YOU GET A POINTER FROM MLX.
		mlx = init_mlx(game_data);
		game_data.mlx = mlx;
		map = game_data.map;
		ft_printf("test alpha\n");
		create_background(game_data);
		ft_printf("test beta\n");
		game_data = create_images(game_data);
		// ISSUE: cannot access terrain image once outside of create_images().
		ft_printf("terrain_image %d\n",
			game_data.images->terrain_image->enabled);
		ft_printf("test gamma\n");
		resize_images(game_data);
		ft_printf("test delta\n");
		images = game_data.images;
		draw_terrain_and_wall_tiles(mlx, images, map, game_data);
		draw_player_and_collectible_tiles(mlx, images, map, game_data);
		game_data.images = images;
		game_data.mlx = mlx;
		heap_map_data = malloc(sizeof(t_game_data));
		//! MUST BE HANDLED
		*heap_map_data = game_data;
		mlx_loop_hook(mlx, *check_and_pick_up_collectibles,
			(void *)(heap_map_data));
		mlx_key_hook(mlx, *my_key_hook, (void *)(heap_map_data));
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free(images); //? Does it work as intended?
						//! Free_map and map_data.
	}
}

void	check_and_pick_up_collectibles(void *param)
{
	t_game_data	*heap_map_data;
	t_images	*images;
	mlx_image_t	*player_image;
	mlx_image_t	*collectible_image;
	int			i;

	heap_map_data = (t_game_data *)param;
	images = heap_map_data->images;
	player_image = images->player_image;
	collectible_image = images->collectible_image;
	i = 0;
	while (i < collectible_image->count)
	{
		if (collectible_image->instances != NULL
			&& collectible_image->instances[i].enabled
			&& player_image->instances[0].x == collectible_image->instances[i].x
			&& player_image->instances[0].y == collectible_image->instances[i].y)
		{
			collectible_image->instances[i].enabled = false;
			heap_map_data->collectible_amount -= 1;
			ft_printf("collectibles remaining: %d\n",
				heap_map_data->collectible_amount);
		}
		i++;
	}
}

void	move_player(t_game_data *heap_map_data, enum direction direction)
{
	mlx_instance_t	*player;

	player = heap_map_data->images->player_image->instances;
	if (direction == UP)
	{
		player->y -= TILE_WIDTH;
		heap_map_data->player_y_pos -= 1;
	}
	else if (direction == DOWN)
	{
		player->y += TILE_WIDTH;
		heap_map_data->player_y_pos += 1;
	}
	else if (direction == LEFT)
	{
		player->x -= TILE_WIDTH;
		heap_map_data->player_x_pos -= 1;
	}
	else if (direction == RIGHT)
	{
		player->x += TILE_WIDTH;
		heap_map_data->player_x_pos += 1;
	}
}

void	my_key_hook(mlx_key_data_t key_data, void *param)
{
	t_game_data		*heap_map_data;
	mlx_instance_t	*player;

	heap_map_data = (t_game_data *)param;
	player = heap_map_data->images->player_image->instances;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos
		- 1][heap_map_data->player_x_pos] != '1')
		move_player(heap_map_data, UP);
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos
		- 1] != '1')
		move_player(heap_map_data, LEFT);
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos
		+ 1][heap_map_data->player_x_pos] != '1')
		move_player(heap_map_data, DOWN);
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS
		&& heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos
		+ 1] != '1')
		move_player(heap_map_data, RIGHT);
	if ((heap_map_data->map[heap_map_data->player_y_pos][heap_map_data->player_x_pos] == 'E'
			&& heap_map_data->collectible_amount == 0))
		terminate_game(heap_map_data, "YOU WIN!!!");
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		terminate_game(heap_map_data, "Exiting...");
}

void	draw_terrain_and_wall_tiles(mlx_t *mlx, t_images *images, char **map,
		t_game_data map_data)
{
	int		player_x;
	int		player_y;
	int		i;
	int		j;
	char	tile_char;

	player_x = 0;
	player_y = 0;
	i = 0;
	while (i < map_data.height)
	{
		j = 0;
		while (j < map_data.width)
		{
			tile_char = map[i][j];
			if (tile_char == '0' || tile_char == 'C' || tile_char == 'P')
				mlx_image_to_window(mlx, images->terrain_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			else if (tile_char == '1')
				mlx_image_to_window(mlx, images->wall_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			else if (tile_char == 'E')
				mlx_image_to_window(mlx, images->exit_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			j++;
		}
		i++;
	}
}

void	draw_player_and_collectible_tiles(mlx_t *mlx, t_images *images,
		char **map, t_game_data map_data)
{
	int		player_x;
	int		player_y;
	int		i;
	int		j;
	char	tile_char;

	player_x = 0;
	player_y = 0;
	i = 0;
	while (i < map_data.height)
	{
		j = 0;
		while (j < map_data.width)
		{
			tile_char = map[i][j];
			if (tile_char == 'C')
				mlx_image_to_window(mlx, images->collectible_image, TILE_WIDTH
					* j, TILE_WIDTH * i);
			else if (tile_char == 'P')
				mlx_image_to_window(mlx, images->player_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			j++;
		}
		i++;
	}
}

void	terminate_game(t_game_data *heap_map_data, char *termination_message)
{
	ft_printf("%s\n", termination_message);
	mlx_terminate(heap_map_data->mlx);
	//! KEY POINT TO HANDLE FREES.
	free_map(heap_map_data->map, heap_map_data->height);
	free(heap_map_data);
	exit(0);
}
