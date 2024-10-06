/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_str_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:21:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/25 14:14:24 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_calc_min_width_comp(int str_len, t_conv_spec cs, char *str)
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

int	pf_print_point_str(char *str, int str_len, t_conv_spec cs)
{
	int	bytes_written;

	bytes_written = 0;
	if (cs.has_point && cs.point_width < str_len)
	{
		bytes_written = write(1, str, cs.point_width);
		if (!str)
			bytes_written = 0;
	}
	else
	{
		if (str != NULL)
		{
			if (pf_putstr_fd(str, 1) < 0)
				return (-1);
		}
		else if (!cs.has_point || (cs.has_point && cs.point_width >= 6))
			bytes_written = write(1, "(null)", 6);
	}
	if (bytes_written < 0)
		return (-1);
	else
		return (bytes_written);
}

int	pf_get_strlen(char *str, t_conv_spec cs)
{
	int	str_len;

	if (cs.min_width == 0 && cs.has_point && cs.point_width == 0)
		str_len = 0;
	else if (str)
		str_len = pf_strlen(str);
	else
		str_len = 6;
	return (str_len);
}
