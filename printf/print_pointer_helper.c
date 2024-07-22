/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:43:45 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:41 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_blank_or_sign(char *print_str, t_conv_spec cs)
{
	int	offset;

	offset = 0;
	if (cs.has_sign)
	{
		*print_str = '+';
		offset = 1;
	}
	else if (cs.has_blank)
	{
		*print_str = ' ';
		offset = 1;
	}
	return (offset);
}

static int	add_hex(char *print_str)
{
	int	offset;

	offset = 0;
	ft_memcpy(print_str, "0x", 2);
	offset = 2;
	return (offset);
}

static int	add_min_width(char *print_str, t_conv_spec cs, int arg_len)
{
	int		offset;
	char	pad_char;
	int		min_width_comp;

	offset = 0;
	pad_char = ' ';
	min_width_comp = ft_max(arg_len, cs.point_width)
		+ (cs.has_sign || cs.has_blank) + 2;
	if (cs.min_width > min_width_comp && !cs.has_right_pad)
	{
		if (cs.has_zero_pad)
			pad_char = '0';
		while (cs.min_width > min_width_comp++)
		{
			*print_str = pad_char;
			print_str++;
			offset++;
		}
	}
	return (offset);
}

int	pointer_add_prefix(char *print_str, t_conv_spec cs, int arg_len)
{
	int	offset;
	int	temp_offset;

	offset = 0;
	if (cs.has_zero_pad)
	{
		temp_offset = add_blank_or_sign(print_str, cs);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = add_hex(print_str);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = add_min_width(print_str, cs, arg_len);
	}
	else
	{
		temp_offset = add_min_width(print_str, cs, arg_len);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = add_blank_or_sign(print_str, cs);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = add_hex(print_str);
	}
	return (offset + temp_offset);
}
