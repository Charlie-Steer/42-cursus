/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:06:04 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/23 19:29:51 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_min_width(char *print_str, t_conv_spec cs, char *n_str, int arg_len)
{
	int		offset;
	char	pad_char;
	int		min_width_comp;

	offset = 0;
	pad_char = ' ';
	if (cs.has_point && cs.point_width == 0 && n_str[0] == '0')
		arg_len -= 1;
	min_width_comp = ft_max(arg_len, cs.point_width);
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

static int	add_point_width(char *print_str, t_conv_spec cs, int arg_len)
{
	int	offset;
	int	point_width_comp;

	offset = 0;
	point_width_comp = arg_len;
	while (cs.point_width > point_width_comp++)
	{
		*print_str = '0';
		print_str++;
		offset++;
	}
	return (offset);
}

static int	add_arg(char *print_str, t_conv_spec cs, char *n_str, int arg_len)
{
	int	offset;

	if (cs.has_point && cs.point_width == 0 && n_str[0] == '0')
	{
		return (0);
	}
	else
	{
		ft_memmove(print_str, n_str, arg_len);
		offset = arg_len;
		return (offset);
	}
}

static int	add_right_pad(char *print_str, t_conv_spec cs, char *n_str, int arg_len)
{
	int	offset;
	int	right_pad_comp;

	offset = 0;
	if (cs.has_point && cs.point_width == 0 && n_str[0] == '0')
		arg_len -= 1;
	right_pad_comp = ft_max(cs.point_width, arg_len);
	if (cs.has_right_pad && cs.min_width > right_pad_comp)
	{
		while (cs.min_width > right_pad_comp++)
		{
			*print_str = ' ';
			print_str++;
			offset++;
		}
	}
	return (offset);
}

int	print_unsigned_int(unsigned int n, t_conv_spec cs)
{
	char	*n_str;
	int		print_len;
	char	*print_str;
	char	*print_str_orig;
	int		arg_len;

	n_str = ft_itoa_unsigned(n);
	print_len = determine_cs_print_len(n_str, cs);
	print_str = malloc(print_len + 1);
	if (!print_str)
		return (-1);
	ft_bzero(print_str, print_len + 1);
	print_str[print_len] = '\0';
	print_str_orig = print_str;
	arg_len = ft_strlen(n_str);
	print_str += add_min_width(print_str, cs, n_str, arg_len);
	print_str += add_point_width(print_str, cs, arg_len);
	print_str += add_arg(print_str, cs, n_str, arg_len);
	add_right_pad(print_str, cs, n_str, arg_len);
	free(n_str);
	ft_putstr_fd(print_str_orig, 1);
	free(print_str_orig);
	return (print_len);
}
