//#include "libftprintf.h"
#include "ft_printf.c"

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

void decimal_numbers_tests()
{
	printf("%d\n", 7);
	printf("% d\n", 7);
	printf("%3d\n", 7);
	printf("% 3d\n", 7);
	printf("% 3d\n", 777);
	printf("% -3dPADDING\n", 7);
	printf("% -3dPADDING\n", 777);
	printf("---\n");
	printf("%3d\n", 9);
	printf("%.3d\n", 9);
	printf("%3.3d\n", 9);
	printf("%6.3d\n", 9);
	printf("%3.6d\n", 9);
	printf("---\n");
	printf("%-3dPADDING\n", 9);
	printf("%-.3dPADDING\n", 9);
	printf("%-3.3dPADDING\n", 9);
	printf("%-6.3dPADDING\n", 9);
	printf("%-3.6dPADDING\n", 9);
	printf("---\n");
	printf("%03d\n", 9);
	printf("%0.3d\n", 9);
	printf("%03.3d\n", 9);
	printf("%06.3d\n", 9);
	printf("%03.6d\n", 9);
	printf("---\n");
	printf("%.4d\n", 5);
	printf("---\n");
	printf("---\n");
	printf("% 3d\n", 9);
	printf("% .3d\n", 9);
	printf("% 3.3d\n", 9);
	printf("% 6.3d\n", 9);
	printf("% 3.6d\n", 9);
	printf("---\n");
	printf("% -3dPADDING\n", 9);
	printf("% -.3dPADDING\n", 9);
	printf("% -3.3dPADDING\n", 9);
	printf("% -6.3dPADDING\n", 9);
	printf("% -3.6dPADDING\n", 9);
	printf("---\n");
	printf("% 03d\n", 9);
	printf("% 0.3d\n", 9);
	printf("% 03.3d\n", 9);
	printf("% 06.3d\n", 9);
	printf("% 03.6d\n", 9);
	printf("---\n");
	printf("% .4d\n", 5);
	printf("---\n");
	printf("% 6.3d\n", 9);
	printf("%+ 6.3d\n", 9);
}

void test_get_arg_len(const int conv_specifier, ...)
{
	va_list args;
	va_start(args, conv_specifier);
	printf("%d\n", get_arg_len((const char)conv_specifier, args));
}

void run_test_suite__get_arg_len()
{
	printf("CHARS:\n");
	test_get_arg_len('c', 't');
	printf("\nINTEGERS:\n");
	test_get_arg_len('d', 420420);
	test_get_arg_len('d', 0);
	test_get_arg_len('d', 1234567890);
	test_get_arg_len('d', 12345678901);
	printf("\nSTRINGS:\n");
	test_get_arg_len('s', "yo");
	test_get_arg_len('s', "");
	test_get_arg_len('s', " ");
	test_get_arg_len('s', "hello_world");
	printf("\nPOINTERS:\n");
	int *p1;
	long *p2;
	printf("%p, %p\n", p1, p2);
	test_get_arg_len('p', p1);
	test_get_arg_len('p', p2);
	printf("\nUNSIGNED INTEGERS\n");
	test_get_arg_len('u', 123456);
	printf("\nHEXADECIMAL NUMBERS:\n");
	test_get_arg_len('x', 123456);
}



int main()
{

	decimal_numbers_tests();
	//ft_printf("hola %s test\n", "hello_world");
	return (0);
}
