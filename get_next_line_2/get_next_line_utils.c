/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:28:50 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/05 15:55:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Get the index of the first newline char found in block.
// Returns -1 if a newline wasn't found.
int	get_newline_index(char *block, int n)
{
	int	newline_index;
	int i;

	newline_index = 0;
	i = 0;
	while (block[i] != '\n' && i < n)
	{
		newline_index++;
		i++;
	}
	if (block[i] == '\n')
		return (newline_index);
	else
		return (-1);
}

void	ft_bzero(char *block, int n)
{
	int	i = 0;
	while (i < n)
	{
		block[i] = '\0';
		i++;
	}
}

int		ft_strlen(char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;

	if (!s)
		return (-1);

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
