/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:24:15 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/08 22:24:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_with_right_pad(int offset, char *str, int str_len,
									t_conv_spec cs)
{
	if (print_point_str(str, str_len, cs) < 0)
		return (-1);
	while (offset < calc_min_width_comp(str_len, cs, str))
	{
		if (ft_putchar_fd(' ', 1) < 0)
			return (-1);
		offset++;
	}
	return (offset);
}

static int	print_str_with_left_pad(int offset, char *str, int str_len,
									t_conv_spec cs)
{
	while (offset < calc_min_width_comp(str_len, cs, str))
	{
		if (ft_putchar_fd(' ', 1) < 0)
			return (-1);
		offset++;
	}
	if (print_point_str(str, str_len, cs) < 0)
		return (-1);
	return (offset);
}

static int	get_print_str_len(char *str, t_conv_spec cs, int str_len)
{
	if (!str && cs.has_point && cs.point_width < 6)
		return (cs.min_width);
	else if (!str && cs.has_point && cs.point_width >= 6)
		return (ft_max(cs.min_width, 6));
	else if (cs.has_point)
	{
		if (cs.point_width >= str_len)
			return (ft_max(cs.min_width, str_len));
		else
			return (ft_max(cs.min_width, cs.point_width));
	}
	else
		return (ft_max(cs.min_width, str_len));
}

int	print_str(char *str, t_conv_spec cs)
{
	int	offset;
	int	str_len;

	offset = 0;
	str_len = get_strlen(str, cs);
	if (str_len == 0)
		return (str_len);
	if (cs.has_right_pad)
	{
		if (print_str_with_right_pad(offset, str, str_len, cs) == -1)
			return (-1);
	}
	else
	{
		if (print_str_with_left_pad(offset, str, str_len, cs) == -1)
			return (-1);
	}
	return (get_print_str_len(str, cs, str_len));
}
