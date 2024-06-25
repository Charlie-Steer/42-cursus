#include "libftprintf.h"

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
	printf("%4.4i\n", 10);
	printf("%8.4i\n", 10);
	printf("%012.8i\n", 10);
	printf("%012.8i\n", 10);
	printf("%012.8x\n", 0XAF);
	printf("%#012.8x\n", 0XAF);
	printf("%#012.12x\n", 0XAF);
	printf("%#08.12x\n", 0XAF);
	printf("%#8.12x\n", 0XAF);
	printf("%12.8s\n", "Hello!");
	printf("%12s\n", "Hello!");
	printf("%.8s World\n", "Hello!");
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
	// original_printf_tests_1();
	// original_printf_tests_2();
	// original_printf_tests_3();
	// original_printf_tests_4();
	// original_printf_tests_5();
	//printf("%s\n", ft_itoa((unsigned int)1234567890));
	//printf("%s\n", ft_itoa((int)1234567890));
	//printf("%s\n", ft_itoa((unsigned int)2234567890));
	//printf("%s\n", ft_itoa((int)2234567890));
	char *str;
	char **strstr;
	printf("%p\n", str);
	printf("%p\n", strstr);
	printf("%d\n", (int)str);
	printf("%d\n", (int)strstr);
	printf("%08d\n", (int)str);
	printf("%08p\n", str);
	printf("%8p\n", str);

	return (0);
}
