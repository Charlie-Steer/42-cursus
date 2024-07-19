/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:24:15 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/19 20:54:00 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//! TEST IF ANY FLAGS INTERACT WITH EACH TYPE
int	print_char(int c, t_conv_spec cs)
{
	int	offset;

	offset = 0;
	if (cs.has_right_pad)
	{
		ft_putchar_fd(c, 1);
		while (offset < (cs.min_width - 1))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
	}
	else
	{
		while (offset < (cs.min_width - 1))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
		ft_putchar_fd(c, 1);
	}
	return (1);
}

int	print_str(char *str, t_conv_spec cs)
{
	int	offset;
	int	str_len;

	offset = 0;
	str_len = ft_strlen(str);
	if (cs.has_right_pad)
	{
		ft_putstr_fd(str, 1);
		while (offset < (cs.min_width - str_len))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
	}
	else
	{
		while (offset < (cs.min_width - str_len))
		{
			ft_putchar_fd(' ', 1);
			offset++;
		}
		ft_putstr_fd(str, 1);
	}
	return (str_len);
}
