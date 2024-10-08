/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft_memmove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:45:41 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/24 15:17:11 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*pf_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	if ((unsigned char *)dst > (unsigned char *)src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
		return (dst);
	}
	else
	{
		pf_memcpy(dst, src, len);
	}
	return (dst);
}
