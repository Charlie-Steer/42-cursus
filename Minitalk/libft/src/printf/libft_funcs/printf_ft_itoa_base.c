/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:54:43 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/24 15:16:08 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Returns a newly allocated string with the given number in the given base.
// NO NEGATIVE NUMBERS SHOULD BE PASSED.
// The returned string's memory has to be handled by the user.
char	*pf_itoa_base(unsigned long n, char *base)
{
	int		base_len;
	char	*str;
	int		i;
	int		str_len;

	base_len = pf_strlen(base);
	str_len = pf_numlen_base_unsigned(n, base);
	if (str_len == -1)
		return (NULL);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	i = 0;
	if (n == 0)
		str[0] = base[0];
	while (n)
	{
		str[str_len - 1 - i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	return (str);
}
