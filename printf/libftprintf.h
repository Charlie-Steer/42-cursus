/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:53:10 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/01 13:26:25 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_conv_spec_data
{
	int	has_blank_prepended;
	int	has_sign;
	int	has_zero_padding;
	int	has_right_padding;
	int	has_alternate_form;
	int has_radix_point;

	int minimum_width;
	int radix_width;

	char conversion_specifier;
} t_conv_spec_data;

int	ft_printf(char const *str, ...);
