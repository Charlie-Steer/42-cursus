/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:36:32 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 16:46:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "error_handling_2.h"
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
	player_image = images.player;
	collectible_image = images.collectible;
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
			ft_printf("Collectibles Remaining: %d\n", p_gd->collectible_amount);
		}
		i++;
	}
}

static void	move_player(t_game_data *gd, enum direction direction);

bool	is_direction_wall(enum direction direction, t_game_data *p_gd)
{
	char	tile;

	if (direction == UP)
		tile = p_gd->map[p_gd->player_y_pos - 1][p_gd->player_x_pos];
	else if (direction == RIGHT)
		tile = p_gd->map[p_gd->player_y_pos][p_gd->player_x_pos + 1];
	else if (direction == DOWN)
		tile = p_gd->map[p_gd->player_y_pos + 1][p_gd->player_x_pos];
	else
		tile = p_gd->map[p_gd->player_y_pos][p_gd->player_x_pos - 1];
	return (tile == '1' || (tile == 'E' && p_gd->collectible_amount != 0));
}

bool	is_in_exit(t_game_data *p_gd)
{
	char	tile;

	tile = p_gd->map[p_gd->player_y_pos][p_gd->player_x_pos];
	return (tile == 'E' && p_gd->collectible_amount == 0);
}

void	my_key_hook(mlx_key_data_t key_data, void *param)
{
	t_game_data	*p_gd;

	p_gd = (t_game_data *)param;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS
		&& !is_direction_wall(UP, p_gd))
		move_player(p_gd, UP);
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS
		&& !is_direction_wall(LEFT, p_gd))
		move_player(p_gd, LEFT);
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS
		&& !is_direction_wall(DOWN, p_gd))
		move_player(p_gd, DOWN);
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS
		&& !is_direction_wall(RIGHT, p_gd))
		move_player(p_gd, RIGHT);
	if (is_in_exit(p_gd))
	{
		ft_printf("YOU WIN!!!");
		terminate_program_heap_gd(p_gd, NULL);
	}
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
	{
		ft_printf("Exiting...");
		terminate_program_heap_gd(p_gd, NULL);
	}
}

static void	move_player(t_game_data *gd, enum direction direction)
{
	mlx_instance_t	*player;

	player = gd->images.player->instances;
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
	gd->n_moves += 1;
	ft_printf("Number of moves: %d\n", gd->n_moves);
}
