/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/04 21:08:20 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "create_game_data.h"
#include "drawing.h"
#include "hooks.h"
#include "libft/src/printf/ft_printf.h" // WARNING: DELETE?
#include "setup.h"
#include "so_long.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	t_game_data	gd;
	t_game_data	*heap_map_data;

	if (check_if_valid_arguments(argc, argv))
	{
		gd = create_game_data(argv[1]);
		// WARNING: MAKE SURE YOU HANDLE ERRORS EVERY TIME YOU GET A POINTER FROM MLX.
		gd.mlx = init_mlx(gd);
		create_background(gd);
		gd.images = create_images(gd.mlx);
		resize_images(gd);
		draw_terrain_and_wall_tiles(gd.images, gd);
		draw_player_and_collectible_tiles(gd.images, gd);
		heap_map_data = malloc(sizeof(t_game_data));
		// WARNING: MUST BE HANDLED
		*heap_map_data = gd;
		mlx_loop_hook(gd.mlx, *check_and_pick_up_collectibles,
			(void *)(heap_map_data));
		mlx_key_hook(gd.mlx, *my_key_hook, (void *)(heap_map_data));
		mlx_loop(gd.mlx);
		mlx_terminate(gd.mlx);
		// TODO: Free_map and map_data.
	}
}
