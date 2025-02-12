/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:15:33 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/12 16:02:01 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "so_long.h"

t_game_data	record_map_character(char c, t_game_data game_data, char **map,
		t_position coords)
{
	if (c == '0' || c == '1')
		;
	else if (c == 'C')
		game_data.collectible_amount += 1;
	else if (c == 'P')
	{
		game_data.player_amount += 1;
		game_data.player_x_pos = coords.x;
		game_data.player_y_pos = coords.y;
	}
	else if (c == 'E')
		game_data.exit_amount += 1;
	else
		print_error_free_map_and_exit("Invalid character found in map.", map,
			game_data.rows);
	return (game_data);
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
				print_error_free_maps_and_exit(
					"There is no valid path "
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

static char	**malloc_new_map(int rows, int cols, char **old_map)
{
	char	**new_map;
	int		i;

	new_map = malloc(rows * sizeof(char *));
	if (!new_map)
		print_error_free_map_and_exit("Failed to allocate memory.",
			old_map, rows);
	i = 0;
	while (i < rows)
	{
		new_map[i] = malloc(cols);
		if (!new_map[i])
			print_error_free_maps_and_exit("Failed to allocate memory.",
				old_map, new_map, rows);
		i++;
	}
	return (new_map);
}

char	**clone_map(char **map, int cols, int rows)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = malloc_new_map(rows, cols, map);
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
