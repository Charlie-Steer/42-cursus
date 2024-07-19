/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:53:10 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/19 20:36:58 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
//! TEST WITHOUT THESE. IN CASE NON FT FUNCTION USED.
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_conv_spec
{
	int		has_blank;
	int		has_sign;
	int		has_zero_pad;
	int		has_right_pad;
	int		has_alternate;
	int		has_point;

	int		min_width;
	int		point_width;

	char	conv_specifier;
}	t_conv_spec;

int			ft_printf(char const *str, ...);

t_conv_spec	parse_conversion_specification(
				t_conv_spec cs, const char *str);
int			determine_cs_print_len(char *n_str, t_conv_spec cs);

int			print_char(int c, t_conv_spec cs);
int			print_str(char *str, t_conv_spec cs);
int			print_int(int n, t_conv_spec cs);
int			print_unsigned_int(unsigned int n, t_conv_spec cs);
int			print_hexadecimal(unsigned int n, t_conv_spec cs);
int			print_pointer(unsigned long n, t_conv_spec cs);

int			int_add_prefix(char *print_str, char *n_str, t_conv_spec cs,
				int arg_len);
int			hexa_add_prefix(char *print_str, t_conv_spec cs, int arg_len);
char		*get_hex_base(int conv_specifier);
int			pointer_add_prefix(char *print_str, t_conv_spec cs, int arg_len);