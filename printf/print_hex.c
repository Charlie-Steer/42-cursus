/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:26:51 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/11 21:47:40 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//! DO TESTS FIRST TO SEE IF YOU CAN REPURPOSE INT LOGIC.

static char *print_alternate(char *print_str, t_conv_spec_data cs)
{
	char *hex_string;

	if (cs.has_alternate) //! WOULD BE CLEANER TO HAVE THIS CHECK ON THE MAIN FUNCTION. SEE IF IT FITS.
	{
		hex_string = malloc(3);
		if (hex_string == NULL)
			return (NULL);
		ft_memcpy(hex_string, "0x", 3);
		if (cs.conversion_specifier == 'X')
			hex_string[1] = 'X';
		ft_memmove(print_str, hex_string, 2);
		free(hex_string);
		print_str += 2;
	}
	return (print_str);
}

static int print_min_width(char *print_str, t_conv_spec_data cs, int arg_len)
{
	int		progress;
	char	pad_char;
	int		min_width_comp;

	progress = 0;
	pad_char = ' ';
	min_width_comp = ft_max(arg_len, cs.point_width);
	if (cs.has_alternate)
		min_width_comp += 2;
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

static void print_int_logic(char *print_str, char *n_str, t_conv_spec_data cs)
{
	int		arg_len = ft_strlen(n_str);
	char	*saved_pointer;

	saved_pointer = print_str;
	if (cs.has_zero_pad)
	{
		print_str = print_alternate(print_str, cs);
		print_str += print_min_width(print_str, cs, arg_len);
	}
	else
	{
		print_str += print_min_width(print_str, cs, arg_len);
		print_str = print_alternate(print_str, cs);
	}
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
	int right_pad_comp = cs.point_width + arg_len; //! TEST arglen
	if (cs.has_alternate)
		right_pad_comp += 2;
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

int print_hex(unsigned int n, t_conv_spec_data cs)
{
	char *base = "0123456789abcdef";
	if (cs.conversion_specifier == 'X')
		base = "0123456789ABCDEF";
	char *n_str = ft_itoa_base(n, base);
	int print_len = determine_cs_print_len(n_str, cs);
	char *print_str = malloc(print_len + 1);
	if (!print_str)
		return (-1);
	print_str[print_len] = '\0';
	print_int_logic(print_str, n_str, cs);
	free(n_str);
	return (print_len);
}
