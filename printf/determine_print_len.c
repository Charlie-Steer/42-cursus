/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_print_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:26:56 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/29 21:22:59 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_print_len_d(t_conv_spec cs, int print_len, char *n_str)
{
	if ((cs.has_blank || cs.has_sign) && n_str[0] != '-')
		print_len += 1;
	if (cs.point_width > print_len)
	{
		print_len = cs.point_width;
		if ((cs.has_blank || cs.has_sign) || n_str[0] == '-')
			print_len += 1;
	}
	if (cs.min_width > print_len)
		print_len = cs.min_width;
	return (print_len);
}

static int	get_print_len_u(t_conv_spec cs, int print_len)
{
	if (cs.point_width > print_len)
		print_len = cs.point_width;
	if (cs.min_width > print_len)
		print_len = cs.min_width;
	return (print_len);
}

static int	get_print_len_x(t_conv_spec cs, int print_len)
{
	if (cs.point_width > print_len)
		print_len = cs.point_width;
	if (cs.has_alternate)
		print_len += 2;
	if (cs.min_width > print_len)
		print_len = cs.min_width;
	return (print_len);
}

static int	get_print_len_p(t_conv_spec cs, int print_len, char *n_str)
{
	if (!ft_strncmp("(nil)", n_str, 6))
		return (print_len);
	if (cs.point_width > print_len)
		print_len = cs.point_width;
	print_len += 2;
	if (cs.has_blank || cs.has_sign)
		print_len += 1;
	if (cs.min_width > print_len)
		print_len = cs.min_width;
	return (print_len);
}

int	determine_cs_print_len(char *n_str, t_conv_spec cs)
{
	int	print_len;
	int	arg_len;

	arg_len = ft_strlen(n_str);
	print_len = arg_len;
	if (cs.conv_specifier == 'd' || cs.conv_specifier == 'i')
		print_len = get_print_len_d(cs, print_len, n_str);
	else if (cs.conv_specifier == 'u')
		print_len = get_print_len_u(cs, print_len);
	else if (cs.conv_specifier == 'x' || cs.conv_specifier == 'X')
		print_len = get_print_len_x(cs, print_len);
	else if (cs.conv_specifier == 'p')
		print_len = get_print_len_p(cs, print_len, n_str);
	return (print_len);
}
