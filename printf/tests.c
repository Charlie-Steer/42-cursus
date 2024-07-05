//#include "libftprintf.h"
#include "ft_printf.c"

void test_printf_int(char *fstr, int n)
{
	static int test_num = 1;
	printf("TEST #%02d\n", test_num);

	printf("inputs	|\"%s\", %d\n", fstr, n);

	printf("printf	|");
	fflush(stdout);
	int orig_ret_val = printf(fstr, n);
	printf("\n");

	printf("ft	|");
	fflush(stdout);
	int ft_ret_val = ft_printf(fstr, n);
	printf("\n");
	fflush(stdout);

	printf("returns	|%d, ", orig_ret_val);
	printf("%d\n", ft_ret_val);
	printf("\n");

	//// cs print len test.
	//printf("cslen|%d", determine_cs_print_len(ft_itoa(n)));
	//test_num++;

	fflush(stdout);
}

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
	printf("\nPRINTF()\n");
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


void print_title(char *str) {
    char *temp = strdup(str); // Duplicate the string to allow modification
    if (temp == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    char *original_temp = temp;
    while (*temp != '\0') {
        *temp = ft_toupper((int)(*temp)); // Use toupper instead of ft_toupper
        temp++;
    }
    printf("\n\n%s:\n\n", original_temp);
    free(original_temp); // Free the duplicated string
}


void ft_decimal_numbers_tests()
{
	test_printf_int("%d", 7);
	test_printf_int("%d", -7);
	print_title("Sign");
	test_printf_int("%+d", 7);
	test_printf_int("%+d", -7);
	print_title("Blank");
	test_printf_int("% d", 7);
	test_printf_int("% d", -7);
	print_title("Right Pad");
	test_printf_int("%-3dP", +7);
	test_printf_int("% -3dP", +7);
	test_printf_int("% -11dP", +7);
	print_title("Min Width");
	test_printf_int("%3d", 7);
	test_printf_int("%1d", 7);
	test_printf_int("%11d", 7);
	print_title("Zero Pad");
	test_printf_int("%03d", 7);
	test_printf_int("%01d", 7);
	test_printf_int("%011d", 7);
	print_title("Point Pad");
	test_printf_int("%.3d", 7);
	test_printf_int("%.11d", 7);
	print_title("Mixed Flags");
	test_printf_int("%6.3d", 7);
	test_printf_int("%3.6d", 7);
	test_printf_int("%22.11d", 7);
	test_printf_int("%11.22d", 7);
	test_printf_int("% 6.3d", 7);
	test_printf_int("% 3.6d", 7);
	test_printf_int("% 22.11d", 7);
	test_printf_int("% 11.22d", 7);

	////
	//ft_printf("%3d\n", -7);
	//ft_printf("%-d\n", -7);
	//ft_printf("%d\n", 7);
	//ft_printf("%a\n", 7);
	//ft_printf("% d\n", 7);
	//ft_printf("%3d\n", 7);
	//ft_printf("% 3d\n", 7);
	//ft_printf("% 3d\n", 777);
	//ft_printf("% -3dPADDING\n", 7);
	//ft_printf("% -3dPADDING\n", 777);
	//ft_printf("---\n");
	//ft_printf("%3d\n", 9);
	//ft_printf("%.3d\n", 9);
	//ft_printf("%3.3d\n", 9);
	//ft_printf("%6.3d\n", 9);
	//ft_printf("%3.6d\n", 9);
	//ft_printf("---\n");
	//ft_printf("%-3dPADDING\n", 9);
	//ft_printf("%-.3dPADDING\n", 9);
	//ft_printf("%-3.3dPADDING\n", 9);
	//ft_printf("%-6.3dPADDING\n", 9);
	//ft_printf("%-3.6dPADDING\n", 9);
	//ft_printf("---\n");
	//ft_printf("%03d\n", 9);
	//ft_printf("%0.3d\n", 9);
	//ft_printf("%03.3d\n", 9);
	//ft_printf("%06.3d\n", 9);
	//ft_printf("%03.6d\n", 9);
	//ft_printf("---\n");
	//ft_printf("%.4d\n", 5);
	//ft_printf("---\n");
	//ft_printf("---\n");
	//ft_printf("% 3d\n", 9);
	//ft_printf("% .3d\n", 9);
	//ft_printf("% 3.3d\n", 9);
	//ft_printf("% 6.3d\n", 9);
	//ft_printf("% 3.6d\n", 9);
	//ft_printf("---\n");
	//ft_printf("% -3dPADDING\n", 9);
	//ft_printf("% -.3dPADDING\n", 9);
	//ft_printf("% -3.3dPADDING\n", 9);
	//ft_printf("% -6.3dPADDING\n", 9);
	//ft_printf("% -3.6dPADDING\n", 9);
	//ft_printf("---\n");
	//ft_printf("% 03d\n", 9);
	//ft_printf("% 0.3d\n", 9);
	//ft_printf("% 03.3d\n", 9);
	//ft_printf("% 06.3d\n", 9);
	//ft_printf("% 03.6d\n", 9);
	//ft_printf("---\n");
	//ft_printf("% .4d\n", 5);
	//ft_printf("---\n");
	//ft_printf("% 6.3d\n", 9);
	//ft_printf("%+ 6.3d\n", 9);
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
	//ft_decimal_numbers_tests();
	print_title("Sign Mixed");
	printf("%6.3d\n", 6);
	printf("%6.3d\n", -6);
	printf("%.3d\n", 666);
	printf("%.3d\n", -666);
	printf("%.6d\n", 666);
	printf("%.6d\n", -666);
	printf("%-12.6dP\n", 777);
	printf("%-12.6dP\n", -777);
	printf("%-7.6dP\n", 777);
	printf("%-7.6dP\n", -777);
	//printf("%s\n", ft_itoa_signless(365));
	//printf("%s\n", ft_itoa_signless(-365));
	//printf("%s\n", ft_itoa_signless(1));
	//printf("%s\n", ft_itoa_signless(-1));
	//printf("%s\n", ft_itoa_signless(2147483647));
	//printf("%s\n", ft_itoa_signless(-2147483648));
	return (0);
}
