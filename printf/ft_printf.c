/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/02 18:15:58 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT_STR_LEN 11 //? Useless?
#define CONVERSION_SPECIFIERS "cspdiuxX%"
#define FLAGS "-0# +."

#include "libftprintf.h"

//void print_format_specifier(const char *str, va_list args)
//{
	//if (*str == 'c')
		//ft_putchar_fd(va_arg(args, int), 1);
	//else if (*str == 's')
		//ft_putstr_fd(va_arg(args, char *), 1);
	//else if (*str == 'd' || *str == 'i')
		//ft_putnbr_fd(va_arg(args, int), 1);
	//else if (*str == 'p')
	//{
	//}
	//else if (*str == 'u')
	//{
	//}
	//else if (*str == 'x')
	//{
	//}
	//else if (*str == 'X')
	//{
	//}
	//else if (*str == '%')
		//ft_putchar_fd('%', 1);
//}

int print_conv_spec(t_conv_spec_data conv_specification, va_list args, int arg_len)
{
	int print_len;
	char conv_specifier = conv_specification.conversion_specifier;

	print_len = arg_len;
	if (conv_specification.has_alternate && (conv_specifier == 'x' ||
		conv_specifier == 'X'))
	{
		if (va_arg(args, unsigned int) != 0)
		{
			print_len += 2;
			ft_putstr_fd("0x", 1);
		}
	}
	if (conv_specification.has_blank && (conv_specifier = 'i' ||
		conv_specifier == 'd' || conv_specifier == 'u' ||
		conv_specifier == 'x' || conv_specifier == 'X' ||
		conv_specifier == 's'))
	{
		if (conv_specifier == 's')
		{
			char *str = va_arg(args, char *);
			if (arg_len == 0) //! Are empty strings really counted as 0 length?
			{
				print_len += 1;
				ft_putchar_fd(' ', 1);
			}
			if (1)
			{
				;
			}
		}

	}
	return (print_len);
}

//! TEST IF ANY FLAGS INTERACT WITH EACH TYPE

int print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int print_str(char *str, t_conv_spec_data conv_specification)
{
	int print_len = strlen(str);
	if (conv_specification.has_blank && ft_strlen(str) == 0)
	{
		ft_putchar_fd(' ', 1);
		print_len += 1;
	}
	ft_putstr_fd(str, 1);
	return (print_len);
}

//! UNTESTED
int print_int(int n, t_conv_spec_data cs)
{
	int i;
	int n_len;
	int print_len;

	n_len = ft_numlen(n, 1);
	print_len = n_len;
	i = 0;
	if (cs.has_sign)
	{
		if (n < 0)
			ft_putchar_fd('-', 1);
		else
			ft_putchar_fd('+', 1);
	}
	else if (cs.has_blank && (n_len >= cs.min_width || cs.has_right_pad))
		ft_putchar_fd(' ', 1);
	if (cs.has_right_pad)
	{
		ft_putnbr_fd(n, 1);
		while (i < cs.min_width - n_len - cs.has_blank - cs.min_width)
			ft_putchar_fd(' ', 1);
		return (print_len);
	}
	else if (cs.min_width != 0)
	{
		char pad_char = ' ';
		if (cs.has_zero_pad)
			pad_char = '0';
		while (i < cs.min_width - n_len - cs.point_width -
			(cs.has_blank || cs.has_sign))
			ft_putchar_fd(pad_char, 1);
	}
	int left_pad_subtractors = (cs.has_sign || cs.has_blank) + cs.point_width;
	print_len = n_len + left_pad_subtractors;
	int left_pad_len = (cs.min_width - left_pad_subtractors);
	if (left_pad_len > 0)
		print_len += left_pad_len;

	ft_putnbr_fd(n, 1);
	return (print_len);
}

void print_format_specifier(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'p')
	{
	}
	else if (c == 'u')
	{
	}
	else if (c == 'x')
	{
	}
	else if (c == 'X')
	{
	}
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

t_conv_spec_data inst_conv_spec_data_struct()
{
	t_conv_spec_data conv_spec_data;

	conv_spec_data.has_blank = 0;
	conv_spec_data.has_sign = 0;
	conv_spec_data.has_zero_pad = 0;
	conv_spec_data.has_right_pad = 0;
	conv_spec_data.has_alternate = 0;
	conv_spec_data.has_point = 0;
	conv_spec_data.min_width = 0;
	conv_spec_data.point_width = 0;
	return (conv_spec_data);
}

//? Check if Null char?
//? Add conversion specifier length to struct?
t_conv_spec_data parse_conversion_specification(
	t_conv_spec_data conv_spec_data, const char *str)
{
	str++;
	while (!ft_strchr(CONVERSION_SPECIFIERS, *str))
	{
		if (ft_memcmp((void *)str, (void *)" ", 1) == 0)
			conv_spec_data.has_blank = 1;
		else if (ft_memcmp((void *)str, (void *)"+", 1) == 0)
			conv_spec_data.has_sign = 1;
		else if (ft_memcmp((void *)str, (void *)"0", 1) == 0)
			conv_spec_data.has_zero_pad = 1;
		else if (ft_memcmp((void *)str, (void *)"-", 1) == 0)
			conv_spec_data.has_right_pad = 1;
		else if (ft_memcmp((void *)str, (void *)"#", 1) == 0)
			conv_spec_data.has_alternate = 1;
		else if (ft_memcmp((void *)str, (void *)".", 1) == 0)
			conv_spec_data.has_point = 1;
		else if (ft_isdigit(*str) && !conv_spec_data.has_point)
			conv_spec_data.min_width = ft_atoi(str);
		else if (ft_isdigit(*str) && conv_spec_data.has_point)
			conv_spec_data.point_width = ft_atoi(str);
		str++;
	}
	conv_spec_data.conversion_specifier = *str;
	return (conv_spec_data);
}

int get_arg_len(char conv_spec, va_list args)
{
	int arg_len;
	char *hex_base = "0123456789ABCDEF";
	//! '%' missing?
	if (conv_spec == 'c')
		arg_len = 1;
	else if (conv_spec == 'd' || conv_spec == 'i')
		arg_len = ft_numlen(va_arg(args, int), 1);
	else if (conv_spec == 's')
		arg_len = ft_strlen(va_arg(args, const char *));
	//else if (conv_spec == 'p')
		//arg_len = ft_numlen_base(*(long *)(va_arg(args, void *)), hex_base, 0);
	else if (conv_spec == 'p')
		arg_len = ft_numlen_base((unsigned long)(va_arg(args, void *)), hex_base, 0);
	else if (conv_spec == 'u')
		arg_len = ft_numlen(va_arg(args, unsigned int), 0);
	else if (conv_spec == 'x' || conv_spec == 'X')
		arg_len = ft_numlen_base(va_arg(args, unsigned int), hex_base, 0);
	else
		arg_len = -1;
	return (arg_len);
}

int ft_printf(char const *str, ...)
{
	va_list args;
	int arg_len;
	t_conv_spec_data conv_spec_data;

	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
		else
		{
			conv_spec_data = inst_conv_spec_data_struct();
			conv_spec_data = parse_conversion_specification(conv_spec_data, str);
			//! VA_ARG USE INSIDE GET_ARG_LEN() IS PROBLEMATIC.
			arg_len = get_arg_len(conv_spec_data.conversion_specifier, args);
			print_format_specifier(conv_spec_data.conversion_specifier, args);
			str += 2; //! Temp
		}
	}
	return(1234);
}

/*
int main()
{
	ft_printf("hello %c world", 'y');
	return (0);
}
*/
