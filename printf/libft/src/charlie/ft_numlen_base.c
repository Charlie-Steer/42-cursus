/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:57:28 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/10 20:55:54 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// Returns the length of the string to write the given number in the given base.
int ft_numlen_base(long num, char *base, int account_sign)
{
	int len;
	int base_len;

	if (num == 0)
		return (1);
	else if (num < 0)
		return (-1);
	len = 0;
	base_len = ft_strlen(base);
	if (account_sign && num < 0)
		len++;
	while (num)
	{
		num /= base_len;
		len++;
	}
	return (len);
}
