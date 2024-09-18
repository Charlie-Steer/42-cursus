/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:39:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/25 19:00:39 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_add_hex(char *print_str, t_conv_spec cs)
{
	int		offset;
	char	*hex_string;

	offset = 0;
	if (cs.has_alternate)
	{
		hex_string = malloc(3);
		if (hex_string == NULL)
			return (-1);
		ft_memcpy(hex_string, "0x", 3);
		if (cs.conv_specifier == 'X')
			hex_string[1] = 'X';
		ft_memmove(print_str, hex_string, 2);
		free(hex_string);
		offset = 2;
	}
	return (offset);
}

static int	add_min_width(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len)
{
	int		offset;
	char	pad_char;
	int		min_width_comp;

	offset = 0;
	pad_char = ' ';
	if (cs.has_point && cs.point_width == 0 && n_str[0] == '0')
		min_width_comp = 0;
	else
		min_width_comp = ft_max(arg_len, cs.point_width);
	if (cs.has_alternate)
		min_width_comp += 2;
	if (cs.min_width > min_width_comp && !cs.has_right_pad)
	{
		if (cs.has_zero_pad && !cs.has_point)
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

int	hexa_add_prefix(char *print_str, t_conv_spec cs, char *n_str, int arg_len)
{
	int	offset;
	int	temp_offset;

	offset = 0;
	temp_offset = 0;
	if (cs.has_zero_pad)
	{
		temp_offset = hexa_add_hex(print_str, cs);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = add_min_width(print_str, cs, n_str, arg_len);
		offset += temp_offset;
	}
	else
	{
		temp_offset = add_min_width(print_str, cs, n_str, arg_len);
		print_str += temp_offset;
		offset += temp_offset;
		temp_offset = hexa_add_hex(print_str, cs);
		offset += temp_offset;
	}
	return (offset);
}

char	*get_hex_base(int conv_specifier)
{
	char	*base;

	base = "0123456789abcdef";
	if (conv_specifier == 'X')
		base = "0123456789ABCDEF";
	return (base);
}
