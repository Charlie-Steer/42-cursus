/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft_numlen_base_unsigned.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:23:05 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/24 15:17:23 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// NUM IS UNSIGNED!
// Returns the length of the string to write the given number in the given base.
int	pf_numlen_base_unsigned(unsigned long num, char *base)
{
	int	len;
	int	base_len;

	if (num == 0)
		return (1);
	len = 0;
	base_len = pf_strlen(base);
	while (num)
	{
		num /= base_len;
		len++;
	}
	return (len);
}
