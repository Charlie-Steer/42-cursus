/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/18 17:28:59 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <unistd.h>

t_map_data parse_map(char *map_path)
{
	t_map_data map_data;
	ft_memset(&map_data, '\0', sizeof(t_map_data));
	int map_fd = open(map_path, O_RDONLY);
	char *line;
	line = get_next_line(map_fd);
	while (line)
	{
		map_data.height++;
		line = get_next_line(map_fd);
		int i = 0;
		while (line[i]) {
			i++;
		}
		map_data.map_width = i;
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

int main(int argc, char *argv[])
{
	if (check_if_valid_arguments(argc, argv))
	{
		parse_map(argv[1]);
	}
}