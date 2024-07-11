/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/11 22:55:37 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT_STR_LEN 11 //?: Useless?
#define CONVERSION_SPECIFIERS "cspdiuxX%"
#define FLAGS "-0# +."

#include "ft_printf.h"

void test_print_parsed_cs(t_conv_spec_data cs)
{
	printf("cs:		%c\n", cs.conversion_specifier);
	printf("min_width:	%d\n", cs.min_width);
	printf("pt_width:	%d\n", cs.point_width);
	printf("alt?:		%d\n", cs.has_alternate);
	printf("blank?:		%d\n", cs.has_blank);
	printf("point?:		%d\n", cs.has_point);
	printf("right_pad?:	%d\n", cs.has_right_pad);
	printf("sign?:		%d\n", cs.has_sign);
	printf("zero_pad?:	%d\n", cs.has_zero_pad);
}


int determine_cs_print_len(char *n_str, t_conv_spec_data cs)
{
	int	print_len;
	int	arg_len;

	arg_len = ft_strlen(n_str);
	print_len = arg_len;
	if (cs.conversion_specifier == 'd')
	{
		if ((cs.has_blank || cs.has_sign) && n_str[0] != '-')
			print_len += 1;
		if (cs.point_width > print_len)
		{
			print_len = cs.point_width;
			if ((cs.has_blank || cs.has_sign) && n_str[0] != '-')
				print_len += 1;
		}
		if (cs.min_width > print_len)
			print_len = cs.min_width;
	}
	else if (cs.conversion_specifier == 'u')
	{
		if (cs.point_width > print_len)
			print_len = cs.point_width;
		if (cs.min_width > print_len)
			print_len = cs.min_width;
	}
	else if (cs.conversion_specifier == 'x' || cs.conversion_specifier == 'X')
	{
		if (cs.point_width > print_len)
			print_len = cs.point_width;
		if (cs.has_alternate)
			print_len += 2;
		if (cs.min_width > print_len)
			print_len = cs.min_width;
	}
	else if (cs.conversion_specifier == 'p')
	{
		if (cs.point_width > print_len)
			print_len = cs.point_width;
		print_len += 2;
		if ((cs.has_blank || cs.has_sign))
			print_len += 1;
		if (cs.min_width > print_len)
			print_len = cs.min_width;
	}
	return (print_len);
}

int print_format_specifier(char c, va_list args, t_conv_spec_data conv_spec)
{
	int print_len;

	print_len = 0; //! May be unnecessary to initialize.
	if (c == 'c')
		print_len = print_char(va_arg(args, int));
	else if (c == 's')
		print_len = print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		print_len = print_int(va_arg(args, int), conv_spec);
	else if (c == 'u')
		print_len = print_unsigned_int(va_arg(args, unsigned int), conv_spec);
	else if (c == 'x' || c == 'X')
		print_len = print_hex(va_arg(args, unsigned int), conv_spec);
	else if (c == 'p')
		print_len = print_pointer(va_arg(args, unsigned int), conv_spec);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (print_len);
}

t_conv_spec_data inst_conv_spec_data_struct()
{
	t_conv_spec_data conv_spec;

	conv_spec.has_blank = 0;
	conv_spec.has_sign = 0;
	conv_spec.has_zero_pad = 0;
	conv_spec.has_right_pad = 0;
	conv_spec.has_alternate = 0;
	conv_spec.has_point = 0;
	conv_spec.min_width = 0;
	conv_spec.point_width = 0;
	return (conv_spec);
}

//?: Check if Null char?
//?: Add conversion specifier length to struct?
t_conv_spec_data parse_conversion_specification(
	t_conv_spec_data conv_spec, const char *str)
{
	str++;
	while (!ft_strchr(CONVERSION_SPECIFIERS, *str))
	{
		if (ft_memcmp((void *)str, (void *)" ", 1) == 0)
			conv_spec.has_blank = 1;
		else if (ft_memcmp((void *)str, (void *)"+", 1) == 0)
			conv_spec.has_sign = 1;
		else if (ft_memcmp((void *)str, (void *)"0", 1) == 0)
			conv_spec.has_zero_pad = 1;
		else if (ft_memcmp((void *)str, (void *)"-", 1) == 0)
			conv_spec.has_right_pad = 1;
		else if (ft_memcmp((void *)str, (void *)"#", 1) == 0)
			conv_spec.has_alternate = 1;
		else if (ft_memcmp((void *)str, (void *)".", 1) == 0)
			conv_spec.has_point = 1;
		else if (ft_isdigit(*str) && !conv_spec.has_point)
		{
			conv_spec.min_width = ft_atoi(str);
			//printf("min_width: %d\n", conv_spec.min_width);
			str += ft_numlen((long)conv_spec.min_width, 0);
			continue ;
		}
		else if (ft_isdigit(*str) && conv_spec.has_point)
		{
			conv_spec.point_width = ft_atoi(str);
			str += ft_numlen((long)conv_spec.point_width, 0);
			continue ;
		}
		str++;
	}
	conv_spec.conversion_specifier = *str;
	return (conv_spec);
}

int get_conv_spec_str_len(const char *str)
{
	int len;

	len = 1;
	str++;
	//printf("char: %d\n", (int)*str);
	while (!ft_strchr(CONVERSION_SPECIFIERS, *str) && *str != '\0')
	{
		len++;
		str++;
		//printf("char: %d\n", (int)*str);
	}
	if (*str == '\0')
		return (-1);
	else
	{
		len++;
		return (len);
	}
}

int ft_printf(char const *str, ...)
{
	int					print_len;
	va_list				args;
	t_conv_spec_data	conv_spec;

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
			conv_spec = inst_conv_spec_data_struct();
			conv_spec = parse_conversion_specification(conv_spec, str);
			int cs_str_len = get_conv_spec_str_len(str);
			print_len += print_format_specifier(conv_spec.conversion_specifier, args, conv_spec);
			str += cs_str_len;
		}
	}
	return(print_len);
}
