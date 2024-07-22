/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:10:50 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/22 16:11:57 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		digit;

	len = intlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		str[len] = digit + '0';
		n /= 10;
		len--;
	}
	return (str);
}
