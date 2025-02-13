/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/13 17:27:51 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "create_game_data.h"
#include "drawing.h"
#include "error_handling_2.h"
#include "hooks.h"
#include "input_validation.h"
#include "setup.h"
#include "so_long.h"

static t_game_data	*allocate_game_data(t_game_data gd)
{
	t_game_data	*heap_gd;

	heap_gd = malloc(sizeof(t_game_data));
	if (!heap_gd)
		terminate_program_no_heap_gd(gd,
			"Couldn't allocate memory for heap_gd.");
	*heap_gd = gd;
	return (heap_gd);
}

int	main(int argc, char *argv[])
{
	t_game_data	gd;
	t_game_data	*heap_gd;

	if (check_if_valid_arguments(argc, argv))
	{
		gd = create_game_data(argv[1]);
		gd.mlx = init_mlx(gd);
		create_background(gd);
		gd.textures = create_textures(gd);
		gd.images = create_images(gd);
		resize_images(gd);
		draw_terrain_and_wall_tiles(gd.images, gd);
		draw_player_and_collectible_tiles(gd.images, gd);
		heap_gd = allocate_game_data(gd);
		mlx_loop_hook(heap_gd->mlx, *check_and_pick_up_collectibles,
			(void *)(heap_gd));
		mlx_key_hook(heap_gd->mlx, *my_key_hook, (void *)(heap_gd));
		ft_printf("Collectibles Remaining: %d\n", heap_gd->collectible_amount);
		ft_printf("Number of moves: 0\n");
		mlx_loop(heap_gd->mlx);
		terminate_program_heap_gd(heap_gd, NULL);
	}
	else
		exit(1);
}
