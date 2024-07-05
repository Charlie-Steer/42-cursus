/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:53:10 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/05 13:37:37 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_conv_spec_data
{
	int	has_blank;
	int	has_sign;
	int	has_zero_pad;
	int	has_right_pad;
	int	has_alternate;
	int has_point;

	int min_width;
	int point_width;

	char conversion_specifier;
} t_conv_spec_data;

int	ft_printf(char const *str, ...);
