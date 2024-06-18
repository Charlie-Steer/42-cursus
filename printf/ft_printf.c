/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/06/18 15:49:03 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CHAR_ARRAY_SIZE_FOR_INT 11

#include "libftprintf.h"

static void print_format_specifier(const char *str, va_list args)
{
	if (*str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == 'p')
	{
	}
	else if (*str == 'u')
	{
	}
	else if (*str == 'x')
	{
	}
	else if (*str == 'X')
	{
	}
	else if (*str == '%')
		ft_putchar_fd('%', 1);
}

static int has_right_padding(char c)
{
	if (c == '-')
		return (1);
	else
		return (0);
}

static int has_zero_padding(char c)
{
	if (c == '0')
		return (1);
	else
		return (0);
}

static int has_alternate_form(char c)
{
	if (c == '#')
		return (1);
	else
		return (0);
}

static int has_blank_prepended(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

static int has_sign(char c)
{
	if (c == '+')
		return (1);
	else
		return (0);
}

// Returned pointer needs to be freed.
static int *get_conv_spec_parts_lens(const char *str)
{
	char *flags;
	char *conversion_specifiers;
	int *conv_spec_parts_lens;
	int mem_block_len;

	flags = "-0# +.";
	conversion_specifiers = "cspdiuxX%";
	mem_block_len = sizeof(int) * 5;
	conv_spec_parts_lens = malloc(mem_block_len);

	ft_bzero(conv_spec_parts_lens, mem_block_len);

	while (ft_strchr(flags, *str))
	{
		conv_spec_parts_lens[0]++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		conv_spec_parts_lens[1]++;
		str++;
	}
	if (*str == '.')
	{
		conv_spec_parts_lens[2] = 1;
		str++;
		while (ft_isdigit(*str))
		{
			conv_spec_parts_lens[3]++;
			str++;
		}
	}
	if (ft_strchr(conversion_specifiers, *str))
		conv_spec_parts_lens[4] = 1;
	return (conv_spec_parts_lens);
}

int ft_printf(char const *str, ...)
{
	char *flags;
	char *conversion_specifiers;
	va_list args;
	void *arg;
	int str_len;
	int i;

	int has_right_padding = 0;
	int has_zero_padding = 0;
	int has_alternate_form = 0;
	int has_blank_prepended = 0;
	int has_sign = 0;

	int has_minimum_width = 0;
	int has_radix_point = 0;
	char str_minimum_width[CHAR_ARRAY_SIZE_FOR_INT];
	int minimum_width = 0;
	int radix_width = 0;
	int str_radix_width[CHAR_ARRAY_SIZE_FOR_INT];


	flags = "-0# +.";
	conversion_specifiers = "cspdiuxX%";
	str_len = strlen(str);
	
	va_start(args, str);

	while (i < str_len)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
			i++;
			continue;
		}
		else
		{
			int *conv_spec_parts_lens = get_conv_spec_parts_lens(str);
			char conversion_specifier = *(str + conv_spec_parts_lens[0]
			+ conv_spec_parts_lens[1] + conv_spec_parts_lens[2]
			+ conv_spec_parts_lens[3]);
			printf("conversion specifier: %c\n", conversion_specifier);

			while (ft_strchr(flags, *str))
			{
				if (*str == '-')
					has_right_padding = 1;
				else if (*str == '0')
					has_zero_padding = 1;
				else if (*str == '#')
					has_alternate_form = 1;
				else if (*str == ' ')
					has_blank_prepended = 1;
				else if (*str == '+')
					has_sign = 1;
				str++;
			}
			int j = 0;
			if (ft_isdigit(*str))
			{
				while (ft_isdigit(*str))
				{
					str_minimum_width[(CHAR_ARRAY_SIZE_FOR_INT - 1) - j] = *str;
					j++;
					str++;
				}
				minimum_width = ft_atoi(str_minimum_width);
			}
			j = 0;
			if (*str == '.')
			{
				str++;
				while (ft_isdigit(*str))
				{
					str_radix_width[(CHAR_ARRAY_SIZE_FOR_INT - 1) - j] = *str;
					j++;
					str++;
				}
			}
			// Enact flags pre and post
			print_format_specifier(str, args);
			str++;
			i++;
		}
	}
	va_end(args);
	return (1234);
}

/*
int main()
{
	ft_printf("hello %c world", 'y');
	return (0);
}
*/
