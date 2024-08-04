/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:46:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/04 22:00:50 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define	BUF_SIZE 5

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (((unsigned char *)s)[i] == (unsigned char)c)
// 		{
// 			return ((void *)&((unsigned char *)s)[i]);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// Returns the index of the first ocurrence of char c in the first n_bytes of mem_block.
// If no character is found, returns -1.
int	index_of_char(const char *mem_block, char c, int n_bytes)
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
	{
		return (dst);
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dst);
	}
}

// Returns the index of the first occurrence of char in the first n chars of the provided block.
int	ft_char_in_block(const char *s, char c, int n)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

//? What should happen on BUF_SIZE == 0?
//? How should it behave when multiple newlines in the buffer?
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;
	char		*back_buf;
	int			line_len;
	char		*back_line;
	int			newline_index;
	int			second_newline_index;
	int			n_chars_read;

	buf = malloc(BUF_SIZE);
	if (ft_char_in_block(buf, '\n', BUF_SIZE))
	{
		newline_index = index_of_char(buf, '\n', BUF_SIZE);
		line = malloc(BUF_SIZE - (newline_index + 1));
		ft_memcpy(line, &(buf[newline_index + 1]), BUF_SIZE - (newline_index + 1));
		//! TEMPORARY MEASURE UNTIL I LEARN HOW MULTIPLE NEWLINES SHOULD BE HANDLED
		ft_bzero(buf, BUF_SIZE);
	}
	while (!ft_char_in_block(buf, '\n', BUF_SIZE))
	{
		//! Returns 0 for EOF. Case not handled.
		n_chars_read = read(1, buf, BUF_SIZE);
		if (n_chars_read == -1)
			return (NULL);

		newline_index = index_of_char(buf, '\n', BUF_SIZE);
		if (newline_index == -1)
		{
			line_len = ft_strlen(line);
			back_line = malloc(line_len + 1);
			ft_memcpy(back_line, line, line_len);
			free(line);
			line = malloc(line_len + BUF_SIZE + 1);
			line[line_len + BUF_SIZE] = '\0';
			ft_memcpy(line, back_line, line_len);
			ft_memcpy(&(line[line_len]), buf, BUF_SIZE);
		}
		else
		{
			line_len = ft_strlen(line);
			back_line = malloc(line_len);
			ft_memcpy(back_line, line, line_len);
			free(line);
			line = malloc(line_len + newline_index + 1);
			ft_memcpy(line, back_line, line_len);
			ft_memcpy(&(line[line_len]), buf, newline_index + 1);
		}
	}
	// TODO: If buffer reaches EOF, it should be freed.

	return (line); //? Should the line be freed by the user?
}
//? Questions:
//? How can I read the length of the line I'm constructing if I don't terminate it with '\0' every time?
//? Is it okay to terminate it with '\0'?
//? But what if the file itself contains a '\0'? Wouldn't this conflict with that system?


#include <fcntl.h>
#include <unistd.h>

static void test_read_01(void)
{
	int text_file_fd = open("text.txt", O_RDONLY);
	char *buf = malloc(BUF_SIZE);
	for (int i = 0; i < 40; i++)
	{
		read(text_file_fd, buf, BUF_SIZE);
		write(1, buf, BUF_SIZE);
	}
	free(buf);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
