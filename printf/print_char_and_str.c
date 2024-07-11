/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:24:15 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/11 21:47:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//! TEST IF ANY FLAGS INTERACT WITH EACH TYPE
int print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (strlen(str));
}
