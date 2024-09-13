/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:32:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/12 22:31:04 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
//! THIS NUMBER IS RANDOM. REMOVE BEFORE DELIVERY?
#define BUFFER_SIZE 12
#endif

//! ENSURE NO ILLEGAL NON-FT FUNCTIONS ARE USED.
t_two_strings	handle_remainder(char *line, char *remainder)
{
	int				remainder_len;
	int				newline_index;
	t_two_strings	line_and_remainder;

	remainder_len = ft_strlen(remainder);
	newline_index = get_char_index('\n', remainder, remainder_len);
	line_and_remainder.line = NULL;
	line_and_remainder.remainder = NULL;

	line = ft_calloc(remainder_len + 1, 1);
	if (!line)
		return (line_and_remainder);

	if (newline_index == -1)
	{
		ft_memcpy(line, remainder, remainder_len);
		free(remainder);
		remainder = NULL;
	}
	else
	{
		ft_memcpy(line, remainder, newline_index + 1);
		ft_memcpy(remainder, &(remainder[newline_index + 1]), remainder_len - newline_index);
	}

	line_and_remainder.line = line;
	line_and_remainder.remainder = remainder;
	return (line_and_remainder);
}

char	*cat_whole_buffer_until_newline_found(int fd, char *line, char *buffer, int newline_index)
{
	int	number_of_bytes_read;

	if (!line)
	{
		line = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!line)
			return (NULL);
	}

	while (newline_index == -1)
	{
		line = ft_strcat_n_max_of_b(line, buffer, BUFFER_SIZE);

		int i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
		number_of_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (number_of_bytes_read == 0)
			return (line);
		else if (number_of_bytes_read == -1)
			return (NULL);
		else if (number_of_bytes_read < BUFFER_SIZE)
			buffer[number_of_bytes_read] = '\0';

		newline_index = get_char_index('\n', buffer, BUFFER_SIZE);
	}

	return (line);
}

t_two_strings cat_buffer_until_newline(char *line, char *buffer, int newline_index)
{
	char 			*remainder;
	t_two_strings	line_and_remainder;

	line_and_remainder.line = NULL;
	line_and_remainder.remainder = NULL;

	line = ft_strcat_n_max_of_b(line, buffer, newline_index + 1);

	remainder = ft_calloc(ft_strlen(buffer) + 1, 1);
	if (!remainder)
		return (line_and_remainder);

	ft_memcpy(remainder, &(buffer[newline_index + 1]),
		   ft_strlen(buffer) - (newline_index + 1));

	line_and_remainder.line = line;
	if (remainder[0] == '\0')
		line_and_remainder.remainder = NULL;
	else
		line_and_remainder.remainder = remainder;
	return (line_and_remainder);
}


t_two_strings	write_to_line(int fd, char *buffer, char *remainder, t_two_strings line_and_remainder)
{
	char			*line;
	int				newline_index;
	int				number_of_bytes_read;

	line = NULL;
	if (remainder)
	{
		line_and_remainder = handle_remainder(line, remainder);
		if (!line_and_remainder.line || line_and_remainder.remainder)
		{
			free(buffer);
			return (line_and_remainder);
		}
		line = line_and_remainder.line;
	}

	number_of_bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (number_of_bytes_read == 0 || number_of_bytes_read == -1)
	{
		free(buffer);
		return (line_and_remainder);
	}

	newline_index = get_char_index('\n', buffer, BUFFER_SIZE);
	if (newline_index == -1)
		line = cat_whole_buffer_until_newline_found(fd, line, buffer, newline_index);

	newline_index = get_char_index('\n', buffer, BUFFER_SIZE);
	line_and_remainder = cat_buffer_until_newline(line, buffer, newline_index);

	free(buffer);
	return (line_and_remainder);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*remainder;
	t_two_strings	line_and_remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);

	line = NULL;
	line_and_remainder.line = NULL;
	line_and_remainder.remainder = NULL;
	line_and_remainder = write_to_line(fd, buffer, remainder, line_and_remainder);
	if (remainder)
		free(remainder);
	line = line_and_remainder.line;
	remainder = line_and_remainder.remainder;
	if (remainder && remainder[0] == '\0')
		free(remainder);

	return (line);
}
