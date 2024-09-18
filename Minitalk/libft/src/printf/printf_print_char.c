/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:23:57 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/08 22:24:29 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_conv_spec cs)
{
	int	offset;

	offset = 0;
	if (cs.has_right_pad)
	{
		if (ft_putchar_fd(c, 1) < 0)
			return (-1);
		while (offset < (cs.min_width - 1))
		{
			if (ft_putchar_fd(' ', 1) < 0)
				return (-1);
			offset++;
		}
		return (offset + 1);
	}
	while (offset < (cs.min_width - 1))
	{
		if (ft_putchar_fd(' ', 1) < 0)
			return (-1);
		offset++;
	}
	if (ft_putchar_fd(c, 1) < 0)
		return (-1);
	return (offset + 1);
}
