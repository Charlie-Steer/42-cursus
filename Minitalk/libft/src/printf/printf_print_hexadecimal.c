/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:26:51 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/08 22:39:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	add_hex_arg(char *print_str, t_conv_spec cs, char *n_str,
						int arg_len)
{
	int	offset;

	if (cs.has_point && cs.point_width == 0 && n_str[0] == '0')
	{
		offset = 0;
		return (offset);
	}
	if (*n_str == '-')
		n_str++;
	ft_memmove(print_str, n_str, arg_len);
	offset = arg_len;
	return (offset);
}

static int	add_right_pad(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len)
{
	int	offset;
	int	right_pad_comp;

	offset = 0;
	if (cs.has_point && cs.point_width == 0 && n_str[0] == '0')
		right_pad_comp = 0;
	else
		right_pad_comp = ft_max(arg_len, cs.point_width);
	if (cs.has_alternate)
		right_pad_comp += 2;
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

// Type-independent function.
static char	*allocate_print_str(int print_len)
{
	char	*print_str;

	print_str = malloc(print_len + 1);
	if (!print_str)
		return (NULL);
	ft_bzero(print_str, print_len + 1);
	print_str[print_len] = '\0';
	return (print_str);
}

int	print_hexadecimal(unsigned int n, t_conv_spec cs)
{
	char	*print_str_orig;
	char	*n_str;
	int		arg_len;
	int		print_len;
	char	*print_str;

	n_str = ft_itoa_base(n, get_hex_base(cs.conv_specifier));
	arg_len = ft_strlen(n_str);
	print_len = determine_cs_print_len(n_str, cs);
	print_str = allocate_print_str(print_len);
	print_str_orig = print_str;
	if (!print_str)
		return (-1);
	print_str += hexa_add_prefix(print_str, cs, n_str, arg_len);
	print_str += add_point_width(print_str, cs, arg_len);
	print_str += add_hex_arg(print_str, cs, n_str, arg_len);
	add_right_pad(print_str, cs, n_str, arg_len);
	if (ft_putstr_fd(print_str_orig, 1) < 0)
		return (-1);
	free (print_str_orig);
	free (n_str);
	return (print_len);
}
