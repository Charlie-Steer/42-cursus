/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:17 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/04 14:21:19 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

#define BUFFER_SIZE 15

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

	//? When does remainder get malloc'd

	// HANDLE REMAINDER
	if (remainder)
	{
		int remainder_len = ft_strlen(remainder);
		int remainder_newline_index = get_newline_index(remainder, remainder_len);
		if (remainder_newline_index == -1)
		{
			line = malloc(remainder_len + 1);
			ft_bzero(line, remainder_len + 1);
			ft_memcpy(line, remainder, remainder_len);
			free(remainder);
			remainder = NULL;
		}
		else // remainder_newline_index != -1
		{
			line_len = remainder_newline_index + 1;
			line = malloc(line_len + 1);
			ft_bzero(line, line_len + 1);
			ft_memcpy(line, remainder, line_len);

			char *temp_remainder = malloc(remainder_len + 1);
			ft_bzero(temp_remainder, remainder_len + 1);

			//? Could memmove() be used instead of using a temp_remainder?
			ft_memcpy(temp_remainder, &remainder[remainder_newline_index + 1], remainder_len - (remainder_newline_index + 1));
			ft_bzero(remainder, remainder_len);
			ft_memcpy(remainder, temp_remainder, remainder_len);
			free(temp_remainder);

			return (line);
		}
	}

	// CORE LOOP
	int	newline_index = -1;
	while (newline_index == -1)
	{
		int n_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes_read == -1 || n_bytes_read == 0) // Error or EOF.
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

		//! Check whether every relevant heap allocation is freed on every branch of the program
		//! Valgrind could help.
	}

	if (newline_index != -1)
	{
		//? UNCLEAR ABOUT WHEN TO FREE REMAINDER
		remainder = malloc(BUFFER_SIZE);
		ft_bzero(remainder, BUFFER_SIZE);

		ft_memcpy(remainder, &buffer[newline_index + 1], BUFFER_SIZE - newline_index);
	}

	// printf("remainder == %s\n", remainder);
	free(buffer);
	
	return (line);
}
