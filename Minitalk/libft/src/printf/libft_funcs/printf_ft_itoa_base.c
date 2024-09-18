/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:54:43 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/22 16:10:59 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Returns a newly allocated string with the given number in the given base.
// NO NEGATIVE NUMBERS SHOULD BE PASSED.
// The returned string's memory has to be handled by the user.
char	*ft_itoa_base(unsigned long n, char *base)
{
	int		base_len;
	char	*str;
	int		i;
	int		str_len;

	base_len = ft_strlen(base);
	str_len = ft_numlen_base_unsigned(n, base);
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

/*
int main(void)
{
	char *base = "0123456789ABCDEF";
	char *s1 = ft_itoa_base(26, base);
	char *s2 = ft_itoa_base(365, base);
	char *s3 = ft_itoa_base(5000, base);
	char *s4 = ft_itoa_base(4095, base);
	char *s51 = ft_itoa_base(1, base);
	char *s5 = ft_itoa_base(0, base);
	char *s6 = ft_itoa_base(-365, base);
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s\n", s4);
	printf("%s\n", s51);
	printf("%s\n", s5);
	// printf("%s\n", s6);
	// printf("%d\n", ft_numlen_base(0, base, 0));
	// printf("%d\n", ft_numlen_base(0, base, 1));
	// printf("%d\n", ft_numlen_base(1, base, 0));
	// printf("%d\n", ft_numlen_base(-1, base, 0));
	// printf("%d\n", ft_numlen_base(-27, base, 1));
	// printf("%d\n", ft_numlen_base(-365, base, 0));
	// printf("%d\n", ft_numlen_base(-365, base, 1));
}
*/
