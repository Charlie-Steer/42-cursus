/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/12 19:21:54 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT_STR_LEN 11 //?: Useless?
#define CONVERSION_SPECIFIERS "cspdiuxX%"
#define FLAGS "-0# +."

#include "ft_printf.h"

// void	test_print_parsed_cs(t_conv_spec_data cs)
// {
// 	printf("cs:		%c\n", cs.conv_specifier);
// 	printf("min_width:	%d\n", cs.min_width);
// 	printf("pt_width:	%d\n", cs.point_width);
// 	printf("alt?:		%d\n", cs.has_alternate);
// 	printf("blank?:		%d\n", cs.has_blank);
// 	printf("point?:		%d\n", cs.has_point);
// 	printf("right_pad?:	%d\n", cs.has_right_pad);
// 	printf("sign?:		%d\n", cs.has_sign);
// 	printf("zero_pad?:	%d\n", cs.has_zero_pad);
// }

int	print_format_specifier(const char c, va_list args, t_conv_spec_data cs)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len = print_char(va_arg(args, int));
	else if (c == 's')
		print_len = print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		print_len = print_int(va_arg(args, int), cs);
	else if (c == 'u')
		print_len = print_unsigned_int(va_arg(args, unsigned int), cs);
	else if (c == 'x' || c == 'X')
		print_len = print_hex(va_arg(args, unsigned int), cs);
	else if (c == 'p')
		print_len = print_pointer(va_arg(args, unsigned long), cs);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (print_len);
}

t_conv_spec_data	inst_conv_spec_data_struct(void)
{
	t_conv_spec_data	cs;

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
	while (!ft_strchr(CONVERSION_SPECIFIERS, *str) && *str != '\0')
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

int	ft_printf(char const *str, ...)
{
	va_list				args;
	t_conv_spec_data	cs;
	int					cs_str_len;
	int					print_len;

	print_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
			print_len++;
		}
		else
		{
			cs = inst_conv_spec_data_struct();
			cs = parse_conversion_specification(cs, str);
			cs_str_len = get_conv_spec_str_len(str);
			print_len += print_format_specifier(cs.conversion_specifier, args, cs);
			str += cs_str_len;
		}
	}
	return (print_len);
}
