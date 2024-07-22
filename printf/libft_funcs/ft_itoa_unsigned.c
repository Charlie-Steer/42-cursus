/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:02:25 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/22 16:11:24 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		len;
	char	*str;
	int		digit;

	len = uintlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		digit = n % 10;
		str[len] = digit + '0';
		n /= 10;
		len--;
	}
	return (str);
}
