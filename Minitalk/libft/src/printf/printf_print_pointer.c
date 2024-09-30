/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:43:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/25 14:13:42 by cargonz2         ###   ########.fr       */
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

static int	add_right_pad(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len)
{
	int	offset;
	int	right_pad_comp;

	offset = 0;
	right_pad_comp = cs.point_width + arg_len
		+ (cs.has_blank || cs.has_sign);
	if (pf_memcmp(n_str, "(nil)", pf_strlen(n_str)))
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

static char	*create_n_str(char *p)
{
	char	*n_str;

	if (!p)
	{
		n_str = malloc(6);
		pf_memcpy(n_str, "(nil)", 6);
	}
	else
		n_str = pf_itoa_base((unsigned long)p, "0123456789abcdef");
	return (n_str);
}

int	pf_print_pointer(void *p, t_conv_spec cs)
{
	int		print_len;
	char	*n_str;
	int		arg_len;
	char	*print_str;
	char	*print_str_orig;

	n_str = create_n_str(p);
	arg_len = pf_strlen(n_str);
	print_len = pf_determine_cs_print_len(n_str, cs);
	print_str = allocate_print_str(print_len);
	print_str_orig = print_str;
	print_str += pf_pointer_add_prefix(print_str, cs, n_str, arg_len);
	print_str += print_point_width(print_str, cs, arg_len);
	print_str += pf_add_pointer_arg(print_str, n_str, arg_len);
	add_right_pad(print_str, cs, n_str, arg_len);
	if (pf_putstr_fd(print_str_orig, 1) < 0)
		return (-1);
	free(n_str);
	free(print_str_orig);
	return (print_len);
}
