/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:06:04 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/17 17:32:24 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_blank_or_sign(char *print_str, char *n_str, t_conv_spec cs)
{
	int	offset;

	offset = 0;
	if (cs.has_sign && *n_str != '-')
	{
		*print_str = '+';
		offset++;
	}
	else if (cs.has_blank && *n_str != '-')
	{
		*print_str = ' ';
		offset++;
	}
	else if (*n_str == '-')
	{
		*print_str = '-';
		offset++;
	}
	return (offset);
}

static int	add_min_width(
	char *print_str, char *n_str, t_conv_spec cs, int arg_len)
{
	int		offset;
	char	pad_char;
	int		min_width_comp;

	offset = 0;
	pad_char = ' ';
	min_width_comp = ft_max(arg_len, cs.point_width)
		+ ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
	if (cs.min_width > min_width_comp && !cs.has_right_pad)
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

static int	add_prefix(char *print_str, char *n_str, t_conv_spec cs,
						int arg_len)
{
	int	offset;

	offset = 0;
	if (cs.has_zero_pad)
	{
		offset += add_blank_or_sign(print_str, n_str, cs);
		print_str += offset;
		offset += add_min_width(print_str, n_str, cs, arg_len);
		print_str += offset;
	}
	else
	{
		offset += add_min_width(print_str, n_str, cs, arg_len);
		print_str += offset;
		offset += add_blank_or_sign(print_str, n_str, cs);
		print_str += offset;
	}
	return (offset);
}

static int	add_point_width(char *print_str, t_conv_spec cs, int arg_len)
{
	int	offset;
	int	point_width_comp;

	offset = 0;
	point_width_comp = arg_len;
	while (cs.point_width > point_width_comp++)
	{
		*print_str = '0';
		print_str++;
		offset++;
	}
	return (offset);
}

static int	add_arg(char *print_str, char *n_str, int arg_len)
{
	int	offset;

	if (*n_str == '-')
		n_str++;
	ft_memmove(print_str, n_str, arg_len);
	offset = arg_len;
	return (offset);
}

static int	add_right_pad(char *print_str, char *n_str, t_conv_spec cs,
							int arg_len)
{
	int	offset;
	int	right_pad_comp;

	offset = 0;
	right_pad_comp = cs.point_width + arg_len + ((cs.has_sign || cs.has_blank)
			&& n_str[0] != '-');
	if (cs.has_right_pad && cs.min_width > right_pad_comp)
	{
		while (cs.min_width > right_pad_comp++)
		{
			*print_str = ' ';
			print_str++;
			offset++;
		}
	}
	return (offset);
}

// ! Might be best merged to the main function.
// Type-independent function.
static char	*allocate_print_str(int print_len)
{
	char	*print_str;

	print_str = malloc(print_len + 1);
	if (!print_str)
		return (NULL);
	print_str[print_len] = '\0';
	return (print_str);
}

int	print_int(int n, t_conv_spec cs)
{
	char	*print_str_orig;
	char	*n_str;
	int		print_len;
	int		arg_len;
	char	*print_str;

	n_str = ft_itoa(n);
	print_len = determine_cs_print_len(n_str, cs);
	print_str = allocate_print_str(print_len);
	print_str_orig = print_str;
	if (!print_str)
		return (-1);
	arg_len = ft_strlen(n_str);
	print_str += add_prefix(print_str, n_str, cs, arg_len);
	print_str += add_point_width(print_str, cs, arg_len);
	print_str += add_arg(print_str, n_str, arg_len);
	add_right_pad(print_str, n_str, cs, arg_len);
	ft_putstr_fd(print_str_orig, 1);
	free(n_str);
	free(print_str_orig);
	return (print_len);
}
