/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:15:33 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/21 10:10:27 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_data record_map_character(char c, t_map_data map_data, char **map, t_two_ints coords) {
	if (c == '0' || c == '1') {
		return (map_data);
	} else if (c == 'C') {
		map_data.collectible_amount += 1;
		return (map_data);
	} else if (c == 'P') {
		map_data.player_amount += 1;
		map_data.player_x_pos = coords.a;
		map_data.player_y_pos = coords.b;
		return (map_data);
	} else if (c == 'E') {
		map_data.exit_amount += 1;
		return (map_data);
	} else {
		print_error_free_map_and_exit("Invalid character found in map.",
			map, map_data.height);
		return (map_data);
	}
}

void ensure_surrounded_by_walls(char **map, t_map_data map_data) {
	int i;
	int j;

	i = 0;
	while(i < map_data.height) {
		j = 0;
		if (i == 0 || i == map_data.height - 1) {
			while (j < map_data.width) {
				if (map[i][j] == '1') {
					j++;
				}
				else {
					print_error_free_map_and_exit("Perimeter of map is not "
					"surrounded by walls.", map, map_data.height);
				}
			}
		}
		else if (map[i][0] != '1' || map[i][map_data.width - 1] != '1') {
			print_error_free_map_and_exit("Perimeter of map is not "
			"surrounded by walls.", map, map_data.height);
		}
		i++;
	}
}

void flood_fill(char **map, int x_pos, int y_pos) {
	map[y_pos][x_pos] = '1';

	// LEFT
	if (map[y_pos][x_pos - 1] != '1') {
		flood_fill(map, x_pos - 1, y_pos);
	}
	// RIGHT
	if (map[y_pos][x_pos + 1] != '1') {
		flood_fill(map, x_pos + 1, y_pos);
	}
	// UP
	if (map[y_pos - 1][x_pos] != '1') {
		flood_fill(map, x_pos, y_pos - 1);
	}
	// DOWN
	if (map[y_pos + 1][x_pos] != '1') {
		flood_fill(map, x_pos, y_pos + 1);
	}
}

void check_if_valid_path(char **map, int width, int height, char **other_map) {
	int i;
	int j;

	i = 0;
	while (i < height) {
		j = 0;
		while (j < width) {
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P') {
				print_error_free_maps_and_exit("There is no valid path "
					"through the map.", other_map, map, height);
			}
			j++;
		}
		i++;
	}
}

char **clone_map(char **map, int width, int height) {
	char **new_map;
	int i;
	int j;

	new_map = malloc(height * sizeof(char *));
	if (!new_map) {
		print_error_free_map_and_exit("Failed to allocate memory.",
			map, height);
	}
	i = 0;
	while (i < height) {
		new_map[i] = malloc(width);
		if (!new_map[i]) {
			print_error_free_maps_and_exit("Failed to allocate memory.", map, new_map, height);
		}
		i++;
	}

	i = 0;
	while (i < height) {
		j = 0;
		while (j < width) {
			new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}

t_map_data validate_map_and_store_map_data(char **map, int width, int height)
{
	int i;
	int j;
	t_map_data map_data;
	t_two_ints coords;

	ft_memset(&map_data, '\0', sizeof(t_map_data));
	map_data.width = width;
	map_data.height = height;
	i = 0;
	while (i < height) {
		j = 0;
		while (j < width) {
			coords.a = j;
			coords.b = i;
			map_data = record_map_character(map[i][j], map_data, map, coords);
			j++;
		}
		i++;
	}
	ensure_surrounded_by_walls(map, map_data);
	#if DEBUG >= 1 //! DELETE
		printf("P: %d\nE: %d\nC: %d\n\n", map_data.player_amount, map_data.exit_amount, map_data.collectible_amount);
	#endif
	if (map_data.player_amount != 1 || map_data.exit_amount != 1
		|| !(map_data.collectible_amount >= 1)) {
		print_error_free_map_and_exit("Map doesn't meet the requirements of one player, "
			"one exit and one or more collectibles.", map, height);
	}
	char **new_map = clone_map(map, width, height);
	flood_fill(new_map, map_data.player_x_pos, map_data.player_y_pos);
	#if DEBUG >= 1 //! DELETE
		DEBUG_print_maps(map, new_map, width, height);
	#endif
	check_if_valid_path(new_map, width, height, map);
	return (map_data);
}

t_two_ints get_map_len(char *map_file_path) {
	t_two_ints width_and_height;
	int map_fd = open(map_file_path, O_RDONLY);

	// get map size for later allocation.
	int width = 0;
	int height = 0;
	int i;
	char *line = get_next_line(map_fd);
	if (!line) {
		print_error_and_exit("File doesn't exist.");
	}
	while (line) {
		height++;
		i = 0;
		while (line[i] != '\0' && line[i] != '\n') {
			i++;
		}
		if (height == 1) {
			width = i;
		}
		else if (i != width) {
			print_error_and_exit("Inconsistent map width. Map must be rectangular.");
		}
		free(line);
		line = get_next_line(map_fd);
	}
	width_and_height.a = width;
	width_and_height.b = height;
	return (width_and_height);
}

char **save_map(char *map_file_path, int width, int height) {
	// allocate map array.
	char **map = malloc(height * sizeof(char *));
	if (!map)
		print_error_and_exit("Failed to allocate memory.");
	int i = 0;
	while (i < height) {
		map[i] = malloc(width);
		if (!map[i])
			print_error_free_map_and_exit("Failed to allocate memory.", map, height);
		ft_memset(map[i], '\0', width);
		i++;
	}

	// copy map to malloc'd block.
	int map_fd = open(map_file_path, O_RDONLY);
	char *line = get_next_line(map_fd);
	int height_iterator = 0;
	int width_iterator;
	while(line) {
		width_iterator = 0;
		while (width_iterator < width) {
			map[height_iterator][width_iterator] = line[width_iterator];
			width_iterator++;
		}
		height_iterator++;
		free(line);
		line = get_next_line(map_fd);
	}
	return (map);
}