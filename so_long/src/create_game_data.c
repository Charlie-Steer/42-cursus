/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:32:46 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 14:13:39 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "map_parsing.h"
#include "read_map.h"
#include "so_long.h"

static t_game_data	validate_map_and_store_map_data(t_game_data gd);
static t_game_data	tally_special_tiles(t_game_data gd, char **map, int rows,
						int cols);

t_game_data	create_game_data(char *map_path)
{
	t_game_data	game_data;

	ft_memset(&game_data, '\0', sizeof(t_game_data));
	game_data = get_map_dimensions_and_map(game_data, map_path);
	game_data = validate_map_and_store_map_data(game_data);
	return (game_data);
}

static t_game_data	validate_map_and_store_map_data(t_game_data gd)
{
	char	**floodfill_map;

	ensure_surrounded_by_walls(gd);
	gd = tally_special_tiles(gd, gd.map, gd.rows, gd.cols);
#if DEBUG >= 1 //! DELETE
	ft_printf("P: %d\nE: %d\nC: %d\n\n", gd.player_amount, gd.exit_amount,
		gd.collectible_amount);
#endif
	if (gd.player_amount != 1 || gd.exit_amount != 1
		|| !(gd.collectible_amount >= 1))
		print_error_free_map_and_exit("Map doesn't meet the requirements"
										"of one player,"
										"one exit"
										"and one or more collectibles.",
										gd.map,
										gd.rows);
	// Check if valid path.
	floodfill_map = clone_map(gd.map, gd.cols, gd.rows);
	flood_fill(floodfill_map, gd.player_x_pos, gd.player_y_pos);
#if DEBUG >= 1 //! DELETE
	DEBUG_print_maps(gd.map, floodfill_map, gd.cols, gd.rows);
#endif
	check_if_valid_path(floodfill_map, gd.cols, gd.rows, gd.map);
	free_map(floodfill_map, gd.rows);
	return (gd);
}

static t_game_data	tally_special_tiles(t_game_data gd, char **map, int rows,
		int cols)
{
	int			i;
	int			j;
	t_position	coords;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			coords.x = j;
			coords.y = i;
			gd = record_map_character(map[i][j], gd, map, coords);
			j++;
		}
		i++;
	}
	return (gd);
}
