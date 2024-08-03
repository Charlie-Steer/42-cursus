/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:46:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/04 00:18:01 by cargonz2         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int		line_len;
	char	*backup_line;
	int		newline_index;
	int		n_read;

	buffer = malloc(BUF_SIZE);
	//! Returns 0 for EOF. Case not handled.
	n_read = read(1, buffer, BUF_SIZE);
	if (n_read == -1)
		return (NULL);
		
	//! Need while loop to read until it finds a newline or EOF.
	newline_index = index_of_char(buffer, (unsigned char)'\n', BUF_SIZE);
	if (newline_index != -1)
	{
		line_len = ft_strlen(line);
		backup_line = malloc(line_len + 1);
		free(line);
		line = malloc(line_len + newline_index + 1);
		ft_memcpy(line, backup_line, line_len);
	}
	else
	{
		line_len = ft_strlen(line);
		backup_line = malloc(line_len + 1);
		ft_memcpy(line, buffer, BUF_SIZE);
	}

	return (line);
}


