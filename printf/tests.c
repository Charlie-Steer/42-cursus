#include "libft/libft.h"
#include <stdio.h>

void original_printf_tests_1()
{
	printf("%4i\n", 10);
	printf("%-4ihello\n", 10);
	printf("%012i\n", 4312531);
	printf("%-04i'0'gets ignored with '-'\n", 10);
}

void original_printf_tests_2()
{
	printf("\nminimum width and '.'\n");
	printf("%4i\n", 10);
	printf("%4x\n", 0xda);
	printf("%#4X\n", 0xda);
	printf("%4u\n", 84);
	printf("%.4i\n", 10);
	printf("%.4x\n", 0xda);
	printf("%#.4X\n", 0xda);
	printf("%.4u\n", 84);
}

void original_printf_tests_3()
{
	printf("\nformat specifier 'u'\n");
	printf("%u\n", -42);
}

void original_printf_tests_4()
{
	printf("\n' ' & '+':\n");
	printf("%    i\n", 10);
	printf("%    +i\n", 10);
	printf("%    +i\n", -10);
}

void original_printf_tests_5()
{
	printf("\n'#':\n");
	printf("%x\n", 0xff);
	printf("%X\n", 0x3f);
	printf("%#x\n", 0xff);
	printf("%#X\n", 0x3f);
}

int main()
{
	char *p_char = "h2llo";


	printf("%s\n", p_char);
	printf("%d, %p\n", ft_isdigit(*p_char), p_char);
	p_char++;
	printf("%d\n, %p\n", ft_isdigit((*p_char)++), p_char);
	printf("%d\n %p\n", ft_isdigit((*(p_char))), p_char);
	p_char++;
	printf("%s\n", p_char);


	return (0);
}
