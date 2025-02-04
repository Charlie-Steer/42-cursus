/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:36:32 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/04 20:53:12 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_and_pick_up_collectibles(void *param)
{
	t_game_data	*p_gd;
	t_images	images;
	mlx_image_t	*player_image;
	mlx_image_t	*collectible_image;
	size_t		i;

	p_gd = (t_game_data *)param;
	images = p_gd->images;
	player_image = images.player_image;
	collectible_image = images.collectible_image;
	i = 0;
	while (i < collectible_image->count)
	{
		if (collectible_image->instances != NULL
			&& collectible_image->instances[i].enabled
			&& player_image->instances[0].x == collectible_image->instances[i].x
			&& player_image->instances[0].y == collectible_image->instances[i].y)
		{
			collectible_image->instances[i].enabled = false;
			p_gd->collectible_amount -= 1;
			ft_printf("collectibles remaining: %d\n", p_gd->collectible_amount);
		}
		i++;
	}
}

static void	move_player(t_game_data *gd, enum direction direction);
static void	terminate_game(t_game_data *heap_map_data,
				char *termination_message);

void	my_key_hook(mlx_key_data_t key_data, void *param)
{
	t_game_data		*p_gd;
	mlx_instance_t	*player;

	p_gd = (t_game_data *)param;
	player = p_gd->images.player_image->instances;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS
		&& p_gd->map[p_gd->player_y_pos - 1][p_gd->player_x_pos] != '1')
		move_player(p_gd, UP);
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS
		&& p_gd->map[p_gd->player_y_pos][p_gd->player_x_pos - 1] != '1')
		move_player(p_gd, LEFT);
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS
		&& p_gd->map[p_gd->player_y_pos + 1][p_gd->player_x_pos] != '1')
		move_player(p_gd, DOWN);
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS
		&& p_gd->map[p_gd->player_y_pos][p_gd->player_x_pos + 1] != '1')
		move_player(p_gd, RIGHT);
	if ((p_gd->map[p_gd->player_y_pos][p_gd->player_x_pos] == 'E'
			&& p_gd->collectible_amount == 0))
		terminate_game(p_gd, "YOU WIN!!!");
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		terminate_game(p_gd, "Exiting...");
}

static void	move_player(t_game_data *gd, enum direction direction)
{
	mlx_instance_t	*player;

	player = gd->images.player_image->instances;
	if (direction == UP)
	{
		player->y -= TILE_WIDTH;
		gd->player_y_pos -= 1;
	}
	else if (direction == DOWN)
	{
		player->y += TILE_WIDTH;
		gd->player_y_pos += 1;
	}
	else if (direction == LEFT)
	{
		player->x -= TILE_WIDTH;
		gd->player_x_pos -= 1;
	}
	else if (direction == RIGHT)
	{
		player->x += TILE_WIDTH;
		gd->player_x_pos += 1;
	}
}

static void	terminate_game(t_game_data *heap_map_data,
		char *termination_message)
{
	ft_printf("%s\n", termination_message);
	mlx_terminate(heap_map_data->mlx);
	// WARNING: KEY POINT TO HANDLE FREES.
	free_map(heap_map_data->map, heap_map_data->rows);
	free(heap_map_data);
	exit(0);
}
