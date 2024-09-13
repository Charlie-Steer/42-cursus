/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:28:50 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/12 12:57:02 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	ft_bzero(char *block, int n)
// {
// 	int	i = 0;
// 	while (i < n)
// 	{
// 		block[i] = '\0';
// 		i++;
// 	}
// }

int		ft_strlen(char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;

	if (!s)
		return (0);

	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t n;
	size_t i;

	n = count *size;

	void *block = malloc(n);
	if (!block)
		return (NULL);
	// ft_bzero(block, count * size);

	i = 0;
	while (i < n)
	{
		((char *)block)[i] = '\0';
		i++;
	}

	return (block);
}

//frees "a" to assign a the new address to it.
char	*ft_strcat_n_max_of_b(char *a, char *b, int n)
{
	int		a_len;
	int 	b_len;
	char	*c;

	if (a == NULL || b == NULL)
		return (NULL);

	a_len = ft_strlen(a);
	b_len = ft_strlen(b);
	c = ft_calloc(a_len + b_len + 1, 1);
	if (!c)
		return (NULL);
	
	ft_memcpy(c, a, a_len);
	free(a);
	if (b_len <= n)
		n = b_len;
	ft_memcpy(&(c[a_len]), b, n);

	return (c);
}

// Get the index of the first newline char found in block.
// Returns -1 if a newline wasn't found.
int	get_char_index(char c, char *block, int n)
{
	int	newline_index;
	int i;

	newline_index = 0;
	i = 0;
	while (i < n && block[i] != c)
	{
		newline_index++;
		i++;
	}
	if (i < n && block[i] == c)
		return (newline_index);
	else
		return (-1);
}

