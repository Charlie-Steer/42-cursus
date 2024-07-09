/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:06:04 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/09 19:53:55 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int print_blank_or_sign(char *print_str, char *n_str, t_conv_spec_data cs)
{
	int progress = 0;
	if (cs.has_sign && *n_str != '-')
	{
		*print_str = '+';
		progress++;
	}
	else if (cs.has_blank && *n_str != '-')
	{
		*print_str = ' ';
		progress++;
	}
	else if (*n_str == '-')
	{
		*print_str = '-';
		progress++;
	}
	return (progress);
}

static int print_min_width(char *print_str, char *n_str, t_conv_spec_data cs, int arg_len)
{
	int		progress;
	char	pad_char;

	progress = 0;
	pad_char = ' ';
	int min_width_comp = ft_max(arg_len, cs.point_width) + ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
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

static void print_int_logic(char *print_str, int n, char *n_str, t_conv_spec_data cs)
{
	int		arg_len = ft_strlen(n_str);
	char	*saved_pointer;
	char	pad_char = ' ';

	saved_pointer = print_str;
	if (cs.has_zero_pad)
	{
		print_str += print_blank_or_sign(print_str, n_str, cs);
		print_str += print_min_width(print_str, n_str, cs, arg_len);
	}
	else
	{
		print_str += print_min_width(print_str, n_str, cs, arg_len);
		print_str += print_blank_or_sign(print_str, n_str, cs);
	}
	//int point_width_comp = arg_len + ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
	int point_width_comp = arg_len;
	if (cs.point_width > point_width_comp) //!: This if statement migth be combined with while loop.
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
	int right_pad_comp = cs.point_width + arg_len + ((cs.has_sign || cs.has_blank) && n_str[0] != '-');
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

int print_int(int n, t_conv_spec_data cs)
{
	char *n_str = ft_itoa(n); //!: I HAVE TO FREE THIS
	int print_len = determine_cs_print_len(n_str, cs);
	char *print_str = malloc(print_len + 1);
	if (!print_str)
		return (-1);
	print_str[print_len] = '\0';
	print_int_logic(print_str, n, n_str, cs);
	free(n_str);
	return (print_len);
}
