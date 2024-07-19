/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:28:34 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/19 18:33:12 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_add_blank_or_sign(char *print_str, char *n_str, t_conv_spec cs)
{
	int	offset;

	offset = 0;
	if (cs.has_sign && *n_str != '-')
	{
		*print_str = '+';
		offset++;
	}
	else if (cs.has_blank && *n_str != '-')
	{
		*print_str = ' ';
		offset++;
	}
	else if (*n_str == '-')
	{
		*print_str = '-';
		offset++;
	}
	return (offset);
}

static int	int_add_min_width(
	char *print_str, char *n_str, t_conv_spec cs, int arg_len)
{
	int		offset;
	char	pad_char;
	int		min_width_comp;

	offset = 0;
	pad_char = ' ';
	min_width_comp = ft_max(arg_len, cs.point_width)
		+ ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
	if (cs.min_width > min_width_comp && !cs.has_right_pad)
	{
		if (cs.has_zero_pad)
			pad_char = '0';
		while (cs.min_width > min_width_comp++)
		{
			*print_str = pad_char;
			offset++;
			print_str++;
		}
	}
	return (offset);
}

int	int_add_prefix(char *print_str, char *n_str, t_conv_spec cs,
						int arg_len)
{
	int	offset;
	int	temp_offset;

	offset = 0;
	if (cs.has_zero_pad)
	{
		temp_offset = int_add_blank_or_sign(print_str, n_str, cs);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = int_add_min_width(print_str, n_str, cs, arg_len);
		print_str += temp_offset;
		offset += temp_offset;
	}
	else
	{
		temp_offset = int_add_min_width(print_str, n_str, cs, arg_len);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = int_add_blank_or_sign(print_str, n_str, cs);
		print_str += temp_offset;
		offset += temp_offset;
	}
	return (offset);
}
