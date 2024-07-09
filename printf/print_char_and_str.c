/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:24:15 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/09 22:35:06 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//!: TEST IF ANY FLAGS INTERACT WITH EACH TYPE
int print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int print_str(char *str, t_conv_spec_data conv_specification)
{
	ft_putstr_fd(str, 1);
	return (strlen(str));
}
