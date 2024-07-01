/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/01 17:36:31 by cargonz2         ###   ########.fr       */
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

void print_format_specifier(char c, va_list args)
{
	if (c == 'c')
	{
		printf("pollita de vegetita");
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 's')
	{
		//printf("pollita de ibai: %s\n", va_arg(args, char *));
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

	conv_spec_data.has_blank_prepended = 0;
	conv_spec_data.has_sign = 0;
	conv_spec_data.has_zero_padding = 0;
	conv_spec_data.has_right_padding = 0;
	conv_spec_data.has_alternate_form = 0;
	conv_spec_data.has_radix_point = 0;
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
			conv_spec_data.has_blank_prepended = 1;
		else if (ft_memcmp((void *)str, (void *)"+", 1) == 0)
			conv_spec_data.has_sign = 1;
		else if (ft_memcmp((void *)str, (void *)"0", 1) == 0)
			conv_spec_data.has_zero_padding = 1;
		else if (ft_memcmp((void *)str, (void *)"-", 1) == 0)
			conv_spec_data.has_right_padding = 1;
		else if (ft_memcmp((void *)str, (void *)"#", 1) == 0)
			conv_spec_data.has_alternate_form = 1;
		else if (ft_memcmp((void *)str, (void *)".", 1) == 0)
			conv_spec_data.has_radix_point = 1;
		else if (ft_isdigit(*str) && !conv_spec_data.has_radix_point)
			conv_spec_data.minimum_width = ft_atoi(str);
		else if (ft_isdigit(*str) && conv_spec_data.has_radix_point)
			conv_spec_data.radix_width = ft_atoi(str);
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
