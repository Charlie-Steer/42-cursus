/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:54:46 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/17 16:12:03 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the length of the string to write the given decimal number.
int	ft_numlen(long num, int account_sign)
{
	int	len;

	if (num == 0)
		return (1);
	else if (num < 0)
		return (-1);
	len = 0;
	if (account_sign && num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
