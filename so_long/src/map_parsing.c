/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:15:33 by cargonz2          #+#    #+#             */
/*   Updated: 2025/01/31 14:47:01 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "so_long.h"

t_game_data	record_map_character(char c, t_game_data game_data, char **map,
		t_position coords)
{
	if (c == '0' || c == '1')
	{
		return (game_data);
	}
	else if (c == 'C')
	{
		game_data.collectible_amount += 1;
		return (game_data);
	}
	else if (c == 'P')
	{
		game_data.player_amount += 1;
		game_data.player_x_pos = coords.x;
		game_data.player_y_pos = coords.y;
		return (game_data);
	}
	else if (c == 'E')
	{
		game_data.exit_amount += 1;
		return (game_data);
	}
	else
	{
		print_error_free_map_and_exit("Invalid character found in map.", map,
			game_data.rows);
		return (game_data);
	}
}

void	ensure_surrounded_by_walls(t_game_data game_data)
{
	int		i;
	int		j;
	char	**map;

	map = game_data.map;
	i = 0;
	while (i < game_data.rows)
	{
		j = 0;
		if (i == 0 || i == game_data.rows - 1)
		{
			while (j < game_data.cols)
			{
				if (map[i][j] == '1')
					j++;
				else
					print_error_free_map_and_exit("Perimeter of map is not "
													"surrounded by walls.",
													map,
													game_data.rows);
			}
		}
		else if (map[i][0] != '1' || map[i][game_data.cols - 1] != '1')
		{
			print_error_free_map_and_exit("Perimeter of map is not "
											"surrounded by walls.",
											map,
											game_data.rows);
		}
		i++;
	}
}

void	flood_fill(char **map, int x_pos, int y_pos)
{
	map[y_pos][x_pos] = '1';
	if (map[y_pos][x_pos - 1] != '1')
	{
		flood_fill(map, x_pos - 1, y_pos);
	}
	if (map[y_pos][x_pos + 1] != '1')
	{
		flood_fill(map, x_pos + 1, y_pos);
	}
	if (map[y_pos - 1][x_pos] != '1')
	{
		flood_fill(map, x_pos, y_pos - 1);
	}
	if (map[y_pos + 1][x_pos] != '1')
	{
		flood_fill(map, x_pos, y_pos + 1);
	}
}

void	check_if_valid_path(char **map, int cols, int rows, char **other_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
			{
				print_error_free_maps_and_exit("There is no valid path "
												"through the map.",
												other_map,
												map,
												rows);
			}
			j++;
		}
		i++;
	}
}

char	**clone_map(char **map, int cols, int rows)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = malloc(rows * sizeof(char *));
	if (!new_map)
	{
		print_error_free_map_and_exit("Failed to allocate memory.", map, rows);
	}
	i = 0;
	while (i < rows)
	{
		new_map[i] = malloc(cols);
		if (!new_map[i])
		{
			print_error_free_maps_and_exit("Failed to allocate memory.", map,
				new_map, rows);
		}
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}
