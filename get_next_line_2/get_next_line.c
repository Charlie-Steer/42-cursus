/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:17 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/03 22:37:11 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

#define BUFFER_SIZE 15

// Get the index of the first newline char found in block.
// Returns -1 if a newline wasn't found.
int	get_newline_index(char *block, int n)
{
	int	newline_index;
	int	i;

	newline_index = 0;
	i = 0;
	while (block[i] != '\n' && i < n)
	{
		newline_index++;
		i++;
	}
	if (block[i] == '\n')
		return (newline_index);
	else
		return (-1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*temp_line;
	static char	*remainder;
	int			line_len;

	buffer = malloc(BUFFER_SIZE);
	ft_bzero(buffer, BUFFER_SIZE);

	line = NULL;

	//! NOW TO ADD REMAINDER HANDLING
	int	newline_index = -1;
	while (newline_index == -1)
	{
		int n_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes_read == -1)
			return (NULL);

		newline_index = get_newline_index(buffer, BUFFER_SIZE);

		if (line != NULL)
		{
			line_len = ft_strlen(line);
			temp_line = malloc(line_len + 1);
			ft_memcpy(temp_line, line, line_len);
			temp_line[line_len] = '\0';
			free(line);
		}
		else
			line_len = 0;
		line = malloc(line_len + BUFFER_SIZE + 1);
		ft_bzero(line, line_len + BUFFER_SIZE + 1);

		ft_memcpy(line, temp_line, line_len);

		if (newline_index == -1)
			ft_memcpy(&line[line_len], buffer, BUFFER_SIZE);
		else
			ft_memcpy(&line[line_len], buffer, newline_index + 1);
		printf("stuck here\n");
	}

	if (newline_index != -1)
	{
		//? UNCLEAR ABOUT WHEN TO FREE REMAINDER
		remainder = malloc(BUFFER_SIZE);
		ft_bzero(remainder, BUFFER_SIZE);

		ft_memcpy(remainder, &buffer[newline_index], BUFFER_SIZE - newline_index);
	}

	printf("%s\n", remainder);
	free(buffer);
	
	return (line);
}
