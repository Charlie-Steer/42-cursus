/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:50:57 by cargonz2          #+#    #+#             */
/*   Updated: 2025/01/31 14:12:28 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "so_long.h"

static t_rows_and_cols	get_map_dimensions(int map_fd);
static char				**get_map(int map_fd, int rows, int cols);

t_game_data	get_map_dimensions_and_map(t_game_data game_data, char *map_path)
{
	t_rows_and_cols	rows_and_cols;
	int				map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		print_error_and_exit("Couldn't open file");
	rows_and_cols = get_map_dimensions(map_fd);
	game_data.rows = rows_and_cols.rows;
	game_data.cols = rows_and_cols.cols;
	close(map_fd);
	////
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		print_error_and_exit("Couldn't open file");
	game_data.map = get_map(map_fd, rows_and_cols.rows, rows_and_cols.cols);
	close(map_fd);
	return (game_data);
}

static t_rows_and_cols	get_map_dimensions(int map_fd)
{
	int		rows;
	int		cols;
	int		i;
	char	*line;

	cols = 0;
	rows = 0;
	line = get_next_line(map_fd);
	if (!line)
		print_error_and_exit("File doesn't exist.");
	while (line)
	{
		rows++;
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (rows == 1)
			cols = i;
		else if (i != cols)
			print_error_and_exit("Inconsistent map cols. Map must be rectangular.");
		free(line);
		line = get_next_line(map_fd);
	}
	return ((t_rows_and_cols){rows, cols});
}

static char				**malloc_map(int rows, int cols);

static char	**get_map(int map_fd, int rows, int cols)
{
	char	**map;
	char	*line;
	int		i;
	int		j;

	map = malloc_map(rows, cols);
	line = get_next_line(map_fd);
	i = 0;
	while (line)
	{
		j = 0;
		while (j < cols)
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
		line = get_next_line(map_fd);
	}
	return (map);
}

static char	**malloc_map(int rows, int cols)
{
	char	**map;
	int		i;

	// allocate map array.
	map = malloc(rows * sizeof(char *));
	if (!map)
		print_error_and_exit("Failed to allocate memory.");
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(cols);
		if (!map[i])
			print_error_free_map_and_exit("Failed to allocate memory.", map,
				rows);
		ft_memset(map[i], '\0', cols);
		i++;
	}
	return (map);
}
