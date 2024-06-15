/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:05:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/06/15 12:01:29 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

static void print_format_specifier(char *str, va_list args)
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
    va_list args;
    void    *arg;
    int     str_len;
    int     i;

    va_start(args, str);

    str_len = strlen(str);
    
    while (i < str_len)
    {
        if (*str != '%')
        {
            ft_putchar_fd(*str, 1);
            i++;
            continue ;
        }
        i++;
        if (*str == '%')
            ft_putchar_fd(*str, 1);
        else
        {
            void *test = (void *)7;
            print_format_specifier(str, args);
        }
    }
    va_end(args);
}

int main()
{
    ft_printf("hello %c world", 'y');
    return (0);
}
