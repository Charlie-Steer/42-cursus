/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:02:25 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/05 13:33:55 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
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

char	*ft_itoa_signless(int n)
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