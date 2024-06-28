/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:56:44 by cargonz2          #+#    #+#             */
/*   Updated: 2024/06/28 16:44:07 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charlie.h"

// Get power of base^exp.
// Negative bases allowed. Negative exponents NOT allowed.
long ft_pow(long base, long exp)
{
	if (exp == 0)
		return 1;
	return (base * ft_pow(base, exp - 1));
}
