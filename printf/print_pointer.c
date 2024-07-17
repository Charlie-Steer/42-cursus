/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:43:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/17 19:02:13 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int add_blank_or_sign(char *print_str, t_conv_spec cs)
{
	int offset;

	offset = 0;
	if (cs.has_sign)
	{
		*print_str = '+';
		offset = 1;
	}
	else if (cs.has_blank)
	{
		*print_str = ' ';
		offset = 1;
	}
	return (offset);
}

static int add_hex_of(char *print_str)
{
	int offset;

	offset = 0;
	ft_memcpy(print_str, "0x", 2);
	offset = 2;
	return (offset);
}

static int add_min_width(char *print_str, t_conv_spec cs, int arg_len)
{
	int		offset;
	char	pad_char;
	int		min_width_comp;

	offset = 0;
	pad_char = ' ';
	min_width_comp = ft_max(arg_len, cs.point_width) + (cs.has_sign || cs.has_blank) + 2;
	if (cs.min_width > min_width_comp)
	{
		if (cs.has_zero_pad)
			pad_char = '0';
		while (cs.min_width > min_width_comp++)
		{
			*print_str = pad_char;
			offset++;
			print_str++;
		}
	}
	return (offset);
}

static int	add_prefix(char *print_str, t_conv_spec cs, int arg_len)
{
	int offset;

	offset = 0;
	if (cs.has_zero_pad)
	{
		offset = add_blank_or_sign(print_str, cs);
		print_str += offset;
		offset += add_hex_of(print_str);
		print_str += offset;
		offset += add_min_width(print_str, cs, arg_len);
	}
	else
	{
		offset += add_min_width(print_str, cs, arg_len);
		print_str += offset;
		offset += add_blank_or_sign(print_str, cs);
		print_str += offset;
		offset += add_hex_of(print_str);
	}
	return (offset);
}

static int	print_point_width(char *print_str,  t_conv_spec cs, int arg_len)
{
	int offset;

	offset = 0;
	int point_width_comp = arg_len;
	while(cs.point_width > point_width_comp++)
	{
		*print_str = '0';
		print_str++;
		offset++;
	}
	return (offset);
}

static char	*allocate_print_str(int print_len)
{
	char	*print_str;

	print_str = malloc(print_len + 1);
	if (!print_str)
		return (NULL);
	print_str[print_len] = '\0';
	return (print_str);
}

//! TESTS #20, #24, #45, #49, #70 FAILED!
int print_pointer(unsigned long n, t_conv_spec cs)
{
	int		print_len;
	char	*n_str;
	int		arg_len;
	char	*print_str;
	char	*print_str_orig;
	
	n_str = ft_itoa_base(n, "0123456789abcdef");
	arg_len = ft_strlen(n_str);
	print_len = determine_cs_print_len(n_str, cs);
	print_str = allocate_print_str(print_len);
	print_str_orig = print_str;
	print_str += add_prefix(print_str, cs, arg_len);
	print_str += print_point_width(print_str, cs, arg_len);
	ft_memmove(print_str, n_str, arg_len);
	ft_putstr_fd(print_str_orig, 1);
	free(n_str);
	free(print_str_orig);
	return (print_len);
}
