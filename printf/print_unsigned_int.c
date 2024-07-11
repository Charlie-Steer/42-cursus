/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:06:04 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/11 21:48:23 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_min_width(char *print_str, t_conv_spec_data cs, int arg_len)
{
	int		progress;
	char	pad_char;

	progress = 0;
	pad_char = ' ';
	int min_width_comp = ft_max(arg_len, cs.point_width);
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

static void print_uint_logic(char *print_str, char *n_str, t_conv_spec_data cs)
{
	int		arg_len = ft_strlen(n_str);
	char	*saved_pointer;

	saved_pointer = print_str;
	print_str += print_min_width(print_str, cs, arg_len);
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
	int right_pad_comp = cs.point_width + arg_len; //!: TEST arglen
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

int print_unsigned_int(unsigned int n, t_conv_spec_data cs)
{
	char *n_str = ft_itoa_unsigned(n);
	//printf("itoa returns:%s\n", n_str);
	int print_len = determine_cs_print_len(n_str, cs);
	char *print_str = malloc(print_len + 1);
	if (!print_str)
		return (-1);
	print_str[print_len] = '\0';
	print_uint_logic(print_str, n_str, cs);
	free(n_str);
	return (print_len);
}
