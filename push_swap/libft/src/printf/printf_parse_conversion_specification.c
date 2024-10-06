/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parse_conversion_specification.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:45:43 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/25 14:16:25 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_flag(const char *str, t_conv_spec *cs)
{
	if (pf_strchr("-0# +.", *str))
	{
		if (pf_memcmp((void *)str, (void *)" ", 1) == 0)
			(*cs).has_blank = 1;
		else if (pf_memcmp((void *)str, (void *)"+", 1) == 0)
			(*cs).has_sign = 1;
		else if (pf_memcmp((void *)str, (void *)"0", 1) == 0)
			(*cs).has_zero_pad = 1;
		else if (pf_memcmp((void *)str, (void *)"-", 1) == 0)
			(*cs).has_right_pad = 1;
		else if (pf_memcmp((void *)str, (void *)"#", 1) == 0)
			(*cs).has_alternate = 1;
		else if (pf_memcmp((void *)str, (void *)".", 1) == 0)
			(*cs).has_point = 1;
		return (1);
	}
	else
		return (0);
}

static int	parse_min_width(const char *str, t_conv_spec *cs)
{
	int	numlen;

	(*cs).min_width = pf_atoi(str);
	numlen = pf_numlen((long)(*cs).min_width, 0);
	return (numlen);
}

static int	parse_point_width(const char *str, t_conv_spec *cs)
{
	int	numlen;

	(*cs).point_width = pf_atoi(str);
	numlen = pf_numlen((long)(*cs).point_width, 0);
	return (numlen);
}

t_conv_spec	pf_parse_conversion_specification(
	t_conv_spec cs, const char *str)
{
	str++;
	while (!pf_strchr("cspdiuxX%\0", *str))
	{
		if (pf_strchr("-0# +.", *str))
			str += parse_flag(str, &cs);
		else if (pf_isdigit(*str) && !cs.has_point)
			str += parse_min_width(str, &cs);
		else if (pf_isdigit(*str) && cs.has_point)
			str += parse_point_width(str, &cs);
	}
	cs.conv_specifier = *str;
	return (cs);
}
