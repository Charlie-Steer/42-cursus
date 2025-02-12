/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:34:56 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/12 16:00:42 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_handling_1.h"

static void	check_first_and_last_lines(int row, t_game_data gd)
{
	int	col;

	col = 0;
	while (col < gd.cols)
	{
		if (gd.map[row][col] == '1')
			col++;
		else
			print_error_free_map_and_exit("Perimeter of map is not "
				"surrounded by walls.",
				gd.map,
				gd.rows);
	}
}

void	ensure_surrounded_by_walls(t_game_data game_data)
{
	int		row;
	char	**map;

	map = game_data.map;
	row = 0;
	while (row < game_data.rows)
	{
		if (row == 0 || row == game_data.rows - 1)
		{
			check_first_and_last_lines(row, game_data);
		}
		else if (map[row][0] != '1' || map[row][game_data.cols - 1] != '1')
		{
			print_error_free_map_and_exit("Perimeter of map is not "
				"surrounded by walls.",
				map,
				game_data.rows);
		}
		row++;
	}
}
