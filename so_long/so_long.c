/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/19 17:31:29 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "libft/src/get_next_line/get_next_line.h"
#include "libft/src/printf/ft_printf.h"
#include <unistd.h>

void print_error_and_exit(char *error_message) {
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}

void print_error(char *error_message) {
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

t_map_data record_map_character(char c, t_map_data map_data) {
	if (c == '0' || c == '1') {
		return (map_data);
	} else if (c == 'C') {
		map_data.collectible_amount += 1;
		return (map_data);
	} else if (c == 'P') {
		map_data.player_amount += 1;
		return (map_data);
	} else if (c == 'E') {
		map_data.exit_amount += 1;
		return (map_data);
	} else {
		print_error("Invalid character found in map.");
		exit(1);
	}
}

t_map_data parse_map(char *map_path)
{
	t_map_data map_data;
	ft_memset(&map_data, '\0', sizeof(t_map_data));

	int map_fd = open(map_path, O_RDONLY);

	char *line = get_next_line(map_fd);
	int line_width;
	while (line) {
		map_data.height++;
		line_width = 0;
		while (line[line_width]) {
			map_data = record_map_character(line[line_width], map_data);
			line_width++;
		}
		if (map_data.height == 1)
			map_data.width = line_width;
		else if (line_width != map_data.width)
			print_error_and_exit("Inconsistent map width. Map must be rectangular.");
		line = get_next_line(map_fd);
	}
	if (map_data.player_amount != 1 && map_data.exit_amount != 1 && !(map_data.collectible_amount >= 1)) {
		print_error_and_exit("Map doesn't meet the requirements of one player, one exit and one or more collectibles.");
	}
	return (map_data);
}

int check_if_valid_arguments(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			return (1);
		else
		 	ft_putstr_fd("Error\nInvalid map file extension. Please provide a \".ber\" file.\n", STDERR_FILENO);
	}
	else if (argc < 2)
	{
		ft_putstr_fd("Error\nPlease provide a valid path for a map file as an argument.\n", STDERR_FILENO);
		exit(1);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments!\n", STDERR_FILENO);
		exit(1);
	}
	else
		assert(0);
	return (0);
}

t_two_ints get_map_len(char *map_file_path) {
	t_two_ints width_and_height;
	int map_fd = open(map_file_path, O_RDONLY);

	// get map size for later allocation.
	int width = 0;
	int height = 0;
	int i;
	char *line = get_next_line(map_fd);
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
			print_error_and_exit("Failed to allocate memory.");
		ft_memset(map[i], '7', width);
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
		line = get_next_line(map_fd);
	}
	return (map);
}

int main(int argc, char *argv[])
{
	if (check_if_valid_arguments(argc, argv))
	{
		t_two_ints width_and_height = get_map_len(argv[1]);
		ft_printf("%d, %d\n", width_and_height.a, width_and_height.b);
		
		char **map = save_map(argv[1], width_and_height.a, width_and_height.b);
		for (int i = 0; i < width_and_height.b; i++) {
			for (int j = 0; j < width_and_height.a; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}

		// parse_map(argv[1]);
	}
}