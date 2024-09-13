/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:32:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/13 17:05:21 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! ENSURE NO ILLEGAL NON-FT FUNCTIONS ARE USED.

//! DO THE BONUS!!!

#include "get_next_line.h"

//! THIS NUMBER IS RANDOM. REMOVE BEFORE DELIVERY?
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 11
#endif

char	*write_file_to_buffer_until_contains_newline(int fd, char *static_buffer)
{
	char	*temp_buffer;
	int		n_bytes_read;

	temp_buffer = NULL;

	if (!static_buffer)
	{
		static_buffer = ft_malloc_zero(BUFFER_SIZE + 1);
		if (!static_buffer)
			return (NULL);
	}

	while (!contains_newline(static_buffer))
	{
		if (temp_buffer)
			free_and_null(temp_buffer);
		temp_buffer = ft_malloc_zero(BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (free(static_buffer), NULL);

		n_bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (n_bytes_read == 0 && static_buffer && static_buffer[0] != '\0')
			return (free(temp_buffer), static_buffer);
		else if (n_bytes_read == 0 || n_bytes_read == -1)
			return (free(temp_buffer), free_and_null(static_buffer), NULL);

		static_buffer = ft_strjoin(static_buffer, temp_buffer);
	}
	if (temp_buffer)
		free(temp_buffer);
	return (static_buffer);
}

char	*copy_static_buffer_until_newline_or_zero_to_line(char *line, char *static_buffer)
{
	int	i;

	line = ft_malloc_zero(ft_strlen(static_buffer) + 1);
	if (!line)
		return (free_and_null(static_buffer), NULL);
	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
		line[i] = static_buffer[i];

	return (line);
}

char	*get_remainder_after_newline(char *static_buffer)
{
	int		old_line_len;
	char	*temp_buffer;
	int		static_buffer_len;
	int		i;

	old_line_len = 0;
	while (static_buffer[old_line_len] != '\n' && static_buffer[old_line_len] != '\0')
		old_line_len++;
	if (static_buffer[old_line_len] == '\n')
		old_line_len += 1;

	static_buffer_len = ft_strlen(static_buffer);
	temp_buffer = ft_malloc_zero(static_buffer_len + 1 - old_line_len);
	if (!temp_buffer)
		return (free_and_null(static_buffer), NULL);

	ft_memcpy(temp_buffer, &(static_buffer)[old_line_len], static_buffer_len - old_line_len);

	// zero-out static buffer before new values.
	i = 0;
	while (static_buffer[i])
	{
		static_buffer[i] = '\0';
		i++;
	}

	ft_memcpy(static_buffer, temp_buffer, static_buffer_len - old_line_len);

	free(temp_buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = NULL;

	static_buffer = write_file_to_buffer_until_contains_newline(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = copy_static_buffer_until_newline_or_zero_to_line(line, static_buffer);
	if (!line)
		return (free(static_buffer), NULL);
	static_buffer = get_remainder_after_newline(static_buffer); //! free something if NULL?

	return (line);
}
