/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:24:15 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/06 22:27:23 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_conv_spec cs)
{
	int	offset;

	offset = 0;
	if (cs.has_right_pad)
	{
		ft_putchar_fd(c, 1);
		while (offset < (cs.min_width - 1))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
	}
	else
	{
		while (offset < (cs.min_width - 1))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
		ft_putchar_fd(c, 1);
	}
	return (offset + 1);
}

static int	calc_min_width_comp(int str_len, t_conv_spec cs, char *str)
{
	int	min_width_comp;

	if (!str && cs.has_point)
	{
		if (!str && cs.has_point && cs.point_width < 6)
			min_width_comp = cs.min_width;
		else if (str_len > cs.point_width)
			min_width_comp = cs.min_width - cs.point_width;
		else
			min_width_comp = cs.min_width - str_len;
	}
	else if (cs.has_point && cs.point_width < str_len)
		min_width_comp = cs.min_width - cs.point_width;
	else
		min_width_comp = cs.min_width - str_len;
	return (min_width_comp);
}

static void	print_point_str(char *str, int str_len, t_conv_spec cs)
{
	if (cs.has_point && cs.point_width < str_len)
		write(1, str, cs.point_width);
	else
	{
		if (str != NULL)
			ft_putstr_fd(str, 1);
		else if (!cs.has_point || (cs.has_point && cs.point_width >= 6))
		{
			write(1, "(null)", 6);
		}
	}
}

static int	get_strlen(char *str, t_conv_spec cs)
{
	int	str_len;

	if (cs.min_width == 0 && cs.has_point && cs.point_width == 0)
		str_len = 0;
	else if (str)
		str_len = ft_strlen(str);
	else
		str_len = 6;
	return (str_len);
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
		print_point_str(str, str_len, cs);
		while (offset < calc_min_width_comp(str_len, cs, str))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
	}
	else
	{
		while (offset < calc_min_width_comp(str_len, cs, str))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
		print_point_str(str, str_len, cs);
	}
	return (str_len);
}
