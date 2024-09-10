/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:17 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/10 15:23:08 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

//? DO I HAVE TO REMOVE THIS ON DELIVERY?
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

void free_and_zero_if_not_null(char *block)
{
	if (block)
	{
		free(block);
		block = NULL;
	}
}

void safe_cleanup(char *block1, char *block2, char *block3, char *block4)
{
	if (block1)
		free(block1);
	if (block2)
		free(block2);
	if (block3)
		free(block3);
	if (block4)
		free(block4);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static char	*remainder;

	char *buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE);

	char *line = NULL;
	int line_len;

	// HANDLE REMAINDER
	if (remainder)
	{
		int remainder_len = ft_strlen(remainder);
		int remainder_newline_index = get_char_index('\n', remainder, remainder_len);
		if (remainder_newline_index == -1)
		{
			line = malloc(remainder_len + 1);
			if (!line)
			{
				free_and_zero_if_not_null(buffer);
				return (NULL);
			}
			ft_bzero(line, remainder_len + 1);
			ft_memcpy(line, remainder, remainder_len);
			free_and_zero_if_not_null(remainder);
			remainder = NULL;
		}
		else // remainder_newline_index != -1
		{
			line_len = remainder_newline_index + 1;
			line = malloc(line_len + 1);
			if (!line)
			{
				free_and_zero_if_not_null(buffer);
				return (NULL);
			}
			ft_bzero(line, line_len + 1);
			ft_memcpy(line, remainder, line_len);

			char *temp_remainder = malloc(remainder_len + 1);
			if (!temp_remainder)
			{
				free_and_zero_if_not_null(buffer);
				free_and_zero_if_not_null(line);
				return (NULL);
			}
			ft_bzero(temp_remainder, remainder_len + 1);

			//? Could memmove() be used instead of using a temp_remainder?
			int temp_remainder_len = remainder_len - (remainder_newline_index + 1);
			ft_memcpy(temp_remainder, &remainder[remainder_newline_index + 1], temp_remainder_len);
			free_and_zero_if_not_null(remainder);
			remainder = temp_remainder;

			free_and_zero_if_not_null(buffer);
			return (line);
		}
	}

	// CORE LOOP
	int	buffer_newline_index = -1;
	while (buffer_newline_index == -1)
	{
		int n_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes_read == -1) // Error or EOF.
		{
			free_and_zero_if_not_null(buffer);
			free_and_zero_if_not_null(line);
			free_and_zero_if_not_null(remainder);
			return (NULL);
		}
		else if (n_bytes_read == 0)
		{
			free_and_zero_if_not_null(buffer);
			free_and_zero_if_not_null(line);
			free_and_zero_if_not_null(remainder);
			return (NULL); //? RETURN "LINE" INSTEAD OF REMAINDER
		}

		buffer_newline_index = get_char_index('\n', buffer, BUFFER_SIZE);

		char *temp_line = NULL;
		if (line != NULL)
		{
			line_len = ft_strlen(line);

			temp_line = malloc(line_len + 1);
			if (!temp_line)
			{
				free_and_zero_if_not_null(buffer);
				free_and_zero_if_not_null(line);
				return (NULL);
			}
			
			temp_line[line_len] = '\0';
			ft_memcpy(temp_line, line, line_len);
			free(line);
		}
		else
			line_len = 0;

		line = malloc(line_len + BUFFER_SIZE + 1);
		if (!line)
		{
			free_and_zero_if_not_null(buffer);
			free_and_zero_if_not_null(temp_line);
			return (NULL);
		}

		ft_bzero(line, line_len + BUFFER_SIZE + 1);

		if (temp_line)
		{
			ft_memcpy(line, temp_line, line_len);
			free_and_zero_if_not_null(temp_line);
		}

		int buffer_null_index = get_char_index('\0', buffer, BUFFER_SIZE);

		if (buffer_newline_index == -1 && buffer_null_index == -1)
			ft_memcpy(&line[line_len], buffer, BUFFER_SIZE);
		else if (buffer_newline_index != -1)
			ft_memcpy(&line[line_len], buffer, buffer_newline_index + 1);
		else if (buffer_null_index != -1)
			ft_memcpy(&line[line_len], buffer, buffer_null_index);
	}

	free_and_zero_if_not_null(remainder);

	if (buffer_newline_index != -1)
	{
		remainder = malloc(BUFFER_SIZE);
		if (!remainder)
		{
			free_and_zero_if_not_null(buffer);
			free_and_zero_if_not_null(line);
			return (NULL);
		}
		ft_bzero(remainder, BUFFER_SIZE);
		ft_memcpy(remainder, &buffer[buffer_newline_index + 1], BUFFER_SIZE - (buffer_newline_index + 1));
	}

	free_and_zero_if_not_null(buffer);
	return (line);
}
