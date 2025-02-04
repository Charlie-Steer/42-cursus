/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:31:27 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/04 20:33:49 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_terrain_and_wall_tiles(t_images images, t_game_data gd)
{
	int		i;
	int		j;
	char	tile_char;

	i = 0;
	while (i < gd.rows)
	{
		j = 0;
		while (j < gd.cols)
		{
			tile_char = gd.map[i][j];
			if (tile_char == '0' || tile_char == 'C' || tile_char == 'P')
				mlx_image_to_window(gd.mlx, images.terrain_image, TILE_WIDTH
					* j, TILE_WIDTH * i);
			else if (tile_char == '1')
				mlx_image_to_window(gd.mlx, images.wall_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			else if (tile_char == 'E')
				mlx_image_to_window(gd.mlx, images.exit_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			j++;
		}
		i++;
	}
}

void	draw_player_and_collectible_tiles(t_images images, t_game_data gd)
{
	int		i;
	int		j;
	char	tile_char;

	i = 0;
	while (i < gd.rows)
	{
		j = 0;
		while (j < gd.cols)
		{
			tile_char = gd.map[i][j];
			if (tile_char == 'C')
				mlx_image_to_window(gd.mlx, images.collectible_image, TILE_WIDTH
					* j, TILE_WIDTH * i);
			else if (tile_char == 'P')
				mlx_image_to_window(gd.mlx, images.player_image, TILE_WIDTH * j,
					TILE_WIDTH * i);
			j++;
		}
		i++;
	}
}
