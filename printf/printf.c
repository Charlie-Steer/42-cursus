/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/06/17 17:32:18 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

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

int ft_printf(char const *str, ...)
{
	char *flags;
	char *conversion_specifiers;
	va_list args;
	void *arg;
	int str_len;
	int i;


	flags = "-0.# +";
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
			while (ft_strchr(flags, *str))
			{
			}
			while (ft_isdigit(*(str)++)) // I'm not sure how this behaves or if it's possible in one line.
			{
			}
			str++;
			i++;
			print_format_specifier(str, args);
			str++;
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
