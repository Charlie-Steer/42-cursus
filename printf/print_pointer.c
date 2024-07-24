/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:43:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/24 18:00:16 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_point_width(char *print_str, t_conv_spec cs, int arg_len)
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

static char	*allocate_print_str(int print_len)
{
	char	*print_str;

	print_str = malloc(print_len + 1);
	if (!print_str)
		return (NULL);
	print_str[print_len] = '\0';
	return (print_str);
}

static int	add_right_pad(char *print_str, t_conv_spec cs, char *n_str, int arg_len)
{
	int	offset;
	int	right_pad_comp;

	offset = 0;
	right_pad_comp = cs.point_width + arg_len
		+ (cs.has_blank || cs.has_sign);
	if (ft_memcmp(n_str, "(nil)", ft_strlen(n_str)))
		right_pad_comp += 2;
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

static int	add_arg(char *print_str, char *n_str, int arg_len)
{
	int	offset;

	ft_memmove(print_str, n_str, arg_len);
	offset = arg_len;
	return (offset);
}

int	print_pointer(void *p, t_conv_spec cs)
{
	int		print_len;
	char	*n_str;
	int		arg_len;
	char	*print_str;
	char	*print_str_orig;

	//if (!p)
	//{
		//ft_putstr_fd("(nil)", 1); //? Error?
		//return (5);
	//}
	if (!p)
	{
		n_str = malloc(6);
		memcpy(n_str, "(nil)", 6);
	}
	else
		n_str = ft_itoa_base((unsigned long)p, "0123456789abcdef");
	arg_len = ft_strlen(n_str);
	print_len = determine_cs_print_len(n_str, cs);
	print_str = allocate_print_str(print_len);
	print_str_orig = print_str;
	print_str += pointer_add_prefix(print_str, cs, n_str, arg_len);
	print_str += print_point_width(print_str, cs, arg_len);
	print_str += add_arg(print_str, n_str, arg_len);
	add_right_pad(print_str, cs, n_str, arg_len);
	ft_putstr_fd(print_str_orig, 1);
	free(n_str);
	free(print_str_orig);
	return (print_len);
}
