/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:56:44 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/05 13:34:12 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Get power of base^exp.
// Negative bases allowed. Negative exponents NOT allowed.
long ft_pow(long base, long exp)
{
	if (exp == 0)
		return 1;
	return (base * ft_pow(base, exp - 1));
}
