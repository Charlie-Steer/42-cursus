/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:46:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/13 00:06:19 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

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

// Returns the index of the first ocurrence of char c in the first n_bytes of mem_block.
// If no character is found, returns -1.
int	index_of_char_block(const char *mem_block, char c, int n_bytes)
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
	char	*back_line;
	char	*leftover;

	back_line = NULL;
	if (line)
	{
		line_len = ft_strlen(line);
		back_line = malloc(line_len + 1);
		back_line[line_len] = '\0';
		ft_memcpy(back_line, line, line_len);
		free(line);
	}
	else
		line_len = 0;
	line = malloc(line_len + (newline_index + 1) + 1);
	line[line_len + newline_index + 1] = '\0';
	if (back_line)
	{
		ft_memcpy(line, back_line, line_len);
		free(back_line);
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
	printf("leftover: %s\n", leftover);
	while (leftover && leftover[0] != '\0') //? Is the NULL char check necessary?
	{
		printf("Entered leftover condition\n");
		newline_index = index_of_char_block(leftover, '\n', ft_strlen(leftover));
		if (newline_index >= 0)
		{
			line = copy_buffer_until_newline(line, leftover, ft_strlen(leftover), newline_index);
			//! WORKING ON THIS PART HERE.
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
			printf("Entered where it should\n");
			line = copy_full_buffer(line, leftover);
			printf("Before free\n");
			free(leftover);
			printf("After free\n");
		}
		printf("leftover: %s\n", leftover);
	}
	buf = malloc(BUF_SIZE);
	newline_index = -1;
	while (newline_index == -1)
	{
		n_chars_read = read(fd, buf, BUF_SIZE); //! Returns 0 for EOF. Case not handled.
		if (n_chars_read == -1)
			return (NULL);

		newline_index = index_of_char_block(buf, '\n', BUF_SIZE);
		if (newline_index >= 0)
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

static void string_null_test(void)
{
	char *s;

	s = NULL;
	printf("%p\n", s);
	if (s == NULL)
		printf("s is NULL\n");
	else
		printf("s is NOT NULL\n");
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
		printf("%s", get_next_line(fd));
	return (0);
}
