/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:43:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/12 20:48:47 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *print_blank_or_sign(char *print_str, t_conv_spec cs)
{
	if (cs.has_sign)
	{
		*print_str = '+';
		print_str++;
	}
	else if (cs.has_blank)
	{
		*print_str = ' ';
		print_str++;
	}
	return (print_str);
}

static char *print_hex_of(char *print_str)
{
	ft_memcpy(print_str, "0x", 2);
	print_str += 2;
	return (print_str);
}

static int print_min_width(char *print_str, t_conv_spec cs, int arg_len)
{
	int		progress;
	char	pad_char;
	int		min_width_comp;

	progress = 0;
	pad_char = ' ';
	min_width_comp = ft_max(arg_len, cs.point_width) + (cs.has_sign || cs.has_blank) + 2;
	if (cs.min_width > min_width_comp)
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

static void print_pointer_logic(char *print_str, char *n_str, t_conv_spec cs)
{
	int		arg_len = ft_strlen(n_str);
	char	*saved_pointer;

	saved_pointer = print_str;
	if (cs.has_zero_pad)
	{
		print_str = print_blank_or_sign(print_str, cs);
		print_str = print_hex_of(print_str);
		print_str += print_min_width(print_str, cs, arg_len);
	}
	else
	{
		print_str += print_min_width(print_str, cs, arg_len);
		print_str = print_blank_or_sign(print_str, cs);
		print_str = print_hex_of(print_str);
	}
	int point_width_comp = arg_len;
	while(cs.point_width > point_width_comp++)
	{
		*print_str = '0';
		print_str++;
	}
	ft_memmove(print_str, n_str, arg_len);
	ft_putstr_fd(saved_pointer, 1);
}

int print_pointer(unsigned long n, t_conv_spec cs)
{
	char *base = "0123456789abcdef";
	char *n_str = ft_itoa_base(n, base);
	int print_len = determine_cs_print_len(n_str, cs);
	char *print_str = malloc(print_len + 1);
	if (!print_str)
		return (-1);
	print_str[print_len] = '\0';
	print_pointer_logic(print_str, n_str, cs);
	free(n_str);
	return (print_len);
}
