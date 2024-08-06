/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/06 17:34:26 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conv_spec(va_list args, t_conv_spec cs)
{
	int		print_len;
	char	c;

	print_len = 0;
	c = cs.conv_specifier;
	if (c == 'c')
		print_len = print_char(va_arg(args, int), cs);
	else if (c == 's')
		print_len = print_str(va_arg(args, char *), cs);
	else if (c == 'd' || c == 'i')
		print_len = print_int(va_arg(args, int), cs);
	else if (c == 'u')
		print_len = print_unsigned_int(va_arg(args, unsigned int), cs);
	else if (c == 'x' || c == 'X')
		print_len = print_hexadecimal(va_arg(args, unsigned int), cs);
	else if (c == 'p')
		print_len = print_pointer(va_arg(args, void *), cs);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		print_len = 1;
	}
	return (print_len);
}

t_conv_spec	init_conv_spec(void)
{
	t_conv_spec	cs;

	cs.has_blank = 0;
	cs.has_sign = 0;
	cs.has_zero_pad = 0;
	cs.has_right_pad = 0;
	cs.has_alternate = 0;
	cs.has_point = 0;
	cs.min_width = 0;
	cs.point_width = 0;
	return (cs);
}

int	get_conv_spec_str_len(const char *str)
{
	int	len;

	len = 1;
	str++;
	while (!ft_strchr("cspdiuxX%", *str) && *str != '\0')
	{
		len++;
		str++;
	}
	if (*str == '\0')
		return (-1);
	else
	{
		len++;
		return (len);
	}
}

static t_conv_spec	get_conv_spec_struct(char const *str)
{
	t_conv_spec	cs;

	cs = init_conv_spec();
	cs = parse_conversion_specification(cs, str);
	return (cs);
}

int	ft_printf(char const *str, ...)
{
	va_list		args;
	int			cs_str_len;
	int			print_len;
	int			cs_print_len;

	print_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str, 1);
		else
		{
			cs_str_len = get_conv_spec_str_len(str);
			cs_print_len = print_conv_spec(args, get_conv_spec_struct(str));
			if (cs_print_len < 0)
				return (-1);
			print_len += cs_print_len;
			str += cs_str_len;
			continue ;
		}
		str++;
		print_len++;
	}
	return (print_len);
}
