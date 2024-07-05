/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/05 17:20:19 by cargonz2         ###   ########.fr       */
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

//! Remove on delivery!
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

int print_int(int n, t_conv_spec_data cs)
{
	int i;
	int n_len;
	int print_len;

	//test_print_parsed_cs(cs);
	i = 0;
	n_len = ft_numlen(n, 1);
	print_len = n_len;
	if (cs.has_sign && n >= 0)
		ft_putchar_fd('+', 1);
	else if (cs.has_blank && (n_len >= cs.min_width || cs.has_right_pad))
		ft_putchar_fd(' ', 1);
	if (cs.has_right_pad)
	{
		ft_putnbr_fd(n, 1);
		while (i < cs.min_width - n_len - cs.has_blank) //! -cs.point_width?
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		return (print_len);
	}
	else if (cs.min_width > 0)
	{
		char pad_char = ' ';
		if (cs.has_zero_pad)
			pad_char = '0';
		i = 0;
		while (i < cs.min_width - n_len - cs.point_width - (cs.has_blank || cs.has_sign))
		{
			ft_putchar_fd(pad_char, 1);
			i++;
		}
		i = 0;
	}

	if (cs.point_width > 0)
	{
		while (i < cs.point_width - n_len - cs.min_width - (cs.has_blank || cs.has_sign))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		i = 0; //! Probably unnecessary.
	}

	//! RETURN UNTESTED
	int left_pad_subtractors = (cs.has_sign || cs.has_blank) + cs.point_width;
	print_len = n_len + left_pad_subtractors;
	int left_pad_len = (cs.min_width - left_pad_subtractors);
	if (left_pad_len > 0)
		print_len += left_pad_len;

	ft_putnbr_fd(n, 1);
	return (print_len);
}

int determine_cs_print_len(char *n_str, t_conv_spec_data cs)
{
	int	print_len;
	int	arg_len;

	arg_len = ft_strlen(n_str);
	print_len = arg_len;
	if (cs.conversion_specifier == 'd') //! THIS IS A TYPE CHECK. MIGHT NOT BE NEEDED.
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
	//printf("PRINT_LEN: %d\n", print_len);
	return (print_len);
}

int print_blank_or_sign(char *print_str, char *n_str, t_conv_spec_data cs)
{
	int progress = 0;
	if (cs.has_sign && *n_str != '-')
	{
		*print_str = '+';
		progress++;
	}
	else if (cs.has_blank && *n_str != '-')
	{
		*print_str = ' ';
		progress++;
	}
	else if (*n_str == '-')
	{
		*print_str = '-';
		progress++;
	}
	return (progress);
}

int print_min_width(char *print_str, char *n_str, t_conv_spec_data cs, int arg_len)
{
	int		progress;
	char	pad_char;

	progress = 0;
	pad_char = ' ';
	int min_width_comp = ft_max(arg_len, cs.point_width) + ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
	if (cs.min_width > min_width_comp && !cs.has_right_pad)
	{
		if (cs.has_zero_pad)
			pad_char = '0';
		while (cs.min_width > min_width_comp++)
		{
			*print_str = pad_char;
			progress++;
			print_str++;
		}
	}
	return (progress);
}

void print_int_logic(char *print_str, int n, char *n_str, t_conv_spec_data cs)
{
	int		arg_len = ft_strlen(n_str);
	char	*saved_pointer;
	char	pad_char = ' ';

	saved_pointer = print_str;
	if (cs.has_zero_pad)
	{
		print_str += print_blank_or_sign(print_str, n_str, cs);
		print_str += print_min_width(print_str, n_str, cs, arg_len);
	}
	else
	{
		print_str += print_min_width(print_str, n_str, cs, arg_len);
		print_str += print_blank_or_sign(print_str, n_str, cs);
	}
	//int point_width_comp = arg_len + ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
	int point_width_comp = arg_len;
	if (cs.point_width > point_width_comp) //! This if statement migth be combined with while loop.
	{
		while(cs.point_width > point_width_comp++)
		{
			*print_str = '0';
			print_str++;
		}
	}
	if (*n_str == '-')
		n_str++;
	ft_memmove(print_str, n_str, arg_len);
	print_str += arg_len;
	int right_pad_comp = cs.point_width + arg_len + ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
	if (cs.has_right_pad && cs.min_width > right_pad_comp)
	{
		while (cs.min_width > right_pad_comp++)
		{
			*print_str = ' ';
			print_str++;
		}
	}
	ft_putstr_fd(saved_pointer, 1);
}

int new_print_int(int n, t_conv_spec_data cs)
{
	char *n_str = ft_itoa(n); //! I HAVE TO FREE THIS
	int print_len = determine_cs_print_len(n_str, cs);
	char *print_str = malloc(print_len + 1);
	if (!print_str)
		return (-1);
	print_str[print_len] = '\0';
	print_int_logic(print_str, n, n_str, cs);
	free(n_str);
	return (print_len);
}

int print_format_specifier(char c, va_list args, t_conv_spec_data conv_spec)
{
	int print_len;

	print_len = 0; //! May be unnecessary to initialize.
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (c == 'd' || c == 'i')
	{
		//ft_putnbr_fd(va_arg(args, int), 1);
		//print_len = print_int(va_arg(args, int), conv_spec);
		print_len = new_print_int(va_arg(args, int), conv_spec);
	}
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

//? Check if Null char?
//? Add conversion specifier length to struct?
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
	int					arg_len;
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
			//! VA_ARG USE INSIDE GET_ARG_LEN() IS PROBLEMATIC.
			//arg_len = get_arg_len(conv_spec.conversion_specifier, args);
			int cs_str_len = get_conv_spec_str_len(str);
			//printf("%d\n", cs_str_len);
			print_len += print_format_specifier(conv_spec.conversion_specifier, args, conv_spec);
			str += cs_str_len; //! Temp
		}
	}
	return(print_len);
}