/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:32:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/13 21:11:55 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_newline(char *s)
{
	int	i;
	int	s_len;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	while (s[i] && s[i] != '\n' && i < s_len)
		i++;
	if (s[i] == '\n')
		return (1);
	else
		return (0);
}

char	*read_file_until_newline_found(
	int fd, char *static_buffer)
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
	free_and_null(temp_buffer);
	return (static_buffer);
}

char	*extract_line(
	char *line, char *static_buffer)
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

char	*get_remainder(char *static_buffer)
{
	int		old_line_len;
	char	*temp_buffer;
	int		static_buffer_len;
	int		i;

	old_line_len = 0;
	while (static_buffer[old_line_len] != '\n'
		&& static_buffer[old_line_len] != '\0')
		old_line_len++;
	if (static_buffer[old_line_len] == '\n')
		old_line_len += 1;
	static_buffer_len = ft_strlen(static_buffer);
	temp_buffer = ft_malloc_zero(static_buffer_len + 1 - old_line_len);
	if (!temp_buffer)
		return (free_and_null(static_buffer), NULL);
	ft_memcpy(temp_buffer, &(static_buffer)[old_line_len],
		static_buffer_len - old_line_len);
	i = 0;
	while (static_buffer[i])
		static_buffer[i++] = '\0';
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
	static_buffer = read_file_until_newline_found(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = extract_line(line, static_buffer);
	if (!line)
		return (free(static_buffer), NULL);
	static_buffer = get_remainder(static_buffer);
	return (line);
}
