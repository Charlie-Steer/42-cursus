/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:46:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/03 17:59:02 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the index of the first ocurrence of char c in the first n_bytes of mem_block.
// If no character is found, returns -1.
int	get_index_of_char_in_block(const char *mem_block, char c, int n_bytes)
{
	int	i;

	i = 0;
	if (!mem_block)
		return (-1);
	while (i < n_bytes)
	{
		if (mem_block[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// Returns the index of the first occurrence of char in the first n chars of the provided block.
int	index_of_char_str(const char *s, char c, int n)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != c && i < n && s[i])
		i++;
	if (i == n)
		return (-2);
	else
		return (i);
}

//! I think this function should only copy the full buffer in when buf==buf.
//! When buf==leftover, it should only copy up to strlen(leftover).
//! Differences between a mem block and a null-terminated string.

//! leftover got here with the same value "Th" twice.
static char	*copy_full_buffer(char *line, char *buf)
{
	int		line_len;
	char	*back_line;

	if (line != NULL)
	{
		line_len = ft_strlen(line);
	}
	else
		line_len = 0;
	back_line = malloc(line_len + 1);
	back_line[line_len] = '\0';
	ft_memcpy(back_line, line, line_len);
	free(line);
	line = malloc(line_len + BUF_SIZE + 1);
	line[line_len + BUF_SIZE] = '\0';
	ft_memcpy(line, back_line, line_len);
	ft_memcpy(&(line[line_len]), buf, BUF_SIZE);

	return (line);
}

static char	*update_line_with_buffer_with_newline(char *line, char *buf, int newline_index)
{
	int		line_len;
	char	*back_line;

	if (line)
		line_len = ft_strlen(line);
	else
		line_len = 0;
	back_line = malloc(line_len + 1);
	back_line[line_len] = '\0';
	ft_memcpy(back_line, line, line_len);
	free(line);
	line = malloc(line_len + (newline_index + 1) + 1);
	line[line_len + (newline_index + 1)] = '\0';
	ft_memcpy(line, back_line, line_len);
	ft_memcpy(&(line[line_len]), buf, newline_index + 1);

	return (line);
}

static char	*copy_buffer_until_newline(char *line, char *buffer,
									   int buffer_size, int newline_index)
{
	int		line_len;
	char	*temp_line;
	char	*leftover;

	temp_line = NULL;
	if (line)
	{
		line_len = ft_strlen(line);
		temp_line = malloc(line_len + 1);
		temp_line[line_len] = '\0';
		ft_memcpy(temp_line, line, line_len);
		free(line);
	}
	else
		line_len = 0;
	line = malloc(line_len + (newline_index + 1) + 1);
	line[line_len + newline_index + 1] = '\0';
	if (temp_line)
	{
		ft_memcpy(line, temp_line, line_len);
		free(temp_line);
	}
	ft_memcpy(&(line[line_len]), buffer, newline_index + 1);
	return (line);
}


//? What should happen on BUF_SIZE == 0?
//? How should it behave when multiple newlines in the buffer?
char	*get_next_line(int fd)
{
	char			*line;
	char			*buf;
	char			*back_buf;
	int				line_len;
	char			*back_line;
	int				newline_index;
	int				second_newline_index;
	int				n_chars_read;
	static char		*leftover;
	char			*back_leftover;

	line = NULL;
	while (leftover && leftover[0] != '\0') //? Is the NULL char check necessary?
	{
		newline_index = get_index_of_char_in_block(leftover, '\n', ft_strlen(leftover));
		if (newline_index >= 0)
		{
			line = copy_buffer_until_newline(line, leftover, ft_strlen(leftover), newline_index);
			int leftover_len = ft_strlen(leftover);
			back_leftover = NULL;
			if (leftover)
			{
				back_leftover = malloc(leftover_len + 1);
				back_leftover[leftover_len] = '\0';
				ft_memcpy(back_leftover, leftover, leftover_len);
				free(leftover);
			}
			leftover = malloc((leftover_len + 1) - (newline_index + 1));
			leftover[leftover_len - (newline_index + 1)] = '\0';
			ft_memcpy(leftover, &(back_leftover[newline_index + 1]), leftover_len - (newline_index + 1));
			if (back_leftover)
				free(back_leftover);
			return (line);
		}
		else
		{
			line = copy_full_buffer(line, leftover);
			free(leftover);
			leftover = NULL;
		}
	}
	buf = malloc(BUF_SIZE);
	newline_index = -1;
	while (newline_index == -1)
	{
		n_chars_read = read(fd, buf, BUF_SIZE); //! Returns 0 for EOF. Case not handled.
		if (n_chars_read == -1)
			return (NULL);

		newline_index = get_index_of_char_in_block(buf, '\n', BUF_SIZE);
		if (newline_index != -1)
		{
			line = copy_buffer_until_newline(line, buf, BUF_SIZE, newline_index);
			leftover = malloc(BUF_SIZE + 1 - (newline_index + 1));
			leftover[BUF_SIZE - (newline_index + 1)] = '\0';
			ft_memcpy(leftover, &(buf[newline_index + 1]), BUF_SIZE - (newline_index + 1));
		}
		else
		{
			line = copy_full_buffer(line, buf);
		}
	}
	free(buf);
	//! If EOF free leftover.
	//? Should the line not be NULL-terminated?
	return (line);
}
