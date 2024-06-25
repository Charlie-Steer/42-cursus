#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

long ft_pow(long base, long exp)
{
	long result;
	if (exp == 0)
		return 1;
	return (base * ft_pow(base, exp - 1));
}

int ft_numlen(long num, int account_sign)
{
	int len;

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

//! THIS ISN'T WORKING
char *ft_numlen_base(long num, char *base, int account_sign)
{
	int len;

	len = 0;
	if (account_sign && num < 0)
		len++;
	while (num)
	{
		num /= ft_strlen(num);
		len++;
	}
	return (len);

}

// Returns a newly allocated string with the given number in the given base.
// No negative numbers, input should be unsigned.
// The returned string's memory has to be handled by the user.
//! THIS ISN'T WORKING
char *ft_itoa_base(unsigned long n, char *base)
{
	int base_len;
	char *str;
	int i;
	int str_len;

	base_len = ft_strlen(base);
	str_len = 20;
	str = malloc(str_len + 1);
	i = 0;
	if (!str)
		return (NULL);

	ft_memset(str, 1, str_len);
	while (n)
	{
		printf("n: %3d	str: %s\n", n, str);
		str[str_len - i] = base[n % base_len];
		n /= 10;
		i++;
	}
	return (str);
}

int main(void)
{
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(long));
	//printf("%d\n", sizeof(long long));
	//printf("%d\n", 7/10);
	//printf("%d\n", 27/10);

	char *s1 = ft_itoa_base(26, "0123456789ABCDEF");
	printf("%s\n", s1);

	//printf("%ld\n", ft_pow(-2, 7));
	//printf("%ld\n", ft_pow(2, 32));
	//printf("%ld\n", ft_pow(-2, 32));
}