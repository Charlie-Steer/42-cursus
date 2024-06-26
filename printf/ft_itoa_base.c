#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

// Get power of base^exp.
// Negative bases allowed. Negative exponents NOT allowed.
long ft_pow(long base, long exp)
{
	long result;
	if (exp == 0)
		return 1;
	return (base * ft_pow(base, exp - 1));
}

// Returns the length of the string to write the given decimal number.
int ft_numlen(long num, int account_sign)
{
	int len;

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

// Returns a newly allocated string with the given number in the given base.
// NO NEGATIVE NUMBERS SHOULD BE PASSED.
// The returned string's memory has to be handled by the user.
char *ft_itoa_base(unsigned long n, char *base)
{
	int base_len;
	char *str;
	int i;
	int str_len;

	base_len = ft_strlen(base);
	str_len = ft_numlen_base(n, base, 0);
	if (str_len == -1)
		return (NULL);
	str = malloc(str_len + 1);
	i = 0;
	if (!str)
		return (NULL);
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
