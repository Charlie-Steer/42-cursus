/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:28:50 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/03 22:09:28 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
