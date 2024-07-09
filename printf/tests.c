#include "libftprintf.h"

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
	test_num++;

	fflush(stdout);
}

void test_printf_unsigned(char *fstr, unsigned int n)
{
	static int test_num = 1;
	printf("TEST #%02d\n", test_num);

	printf("inputs	|\"%s\", %u\n", fstr, n);

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

	test_num++;

	fflush(stdout);
}

void test_printf_char(char *fstr, char c)
{
	static int test_num = 1;
	printf("TEST #%02d\n", test_num);

	printf("inputs	|\"%s\", %c\n", fstr, c);

	printf("printf	|");
	fflush(stdout);
	int orig_ret_val = printf(fstr, c);
	printf("\n");

	printf("ft	|");
	fflush(stdout);
	int ft_ret_val = ft_printf(fstr, c);
	printf("\n");
	fflush(stdout);

	printf("returns	|%d, ", orig_ret_val);
	printf("%d\n", ft_ret_val);
	printf("\n");

	test_num++;

	fflush(stdout);
}

void test_printf_string(char *fstr, char *s)
{
	static int test_num = 1;
	printf("TEST #%02d\n", test_num);

	printf("inputs	|\"%s\", %s\n", fstr, s);

	printf("printf	|");
	fflush(stdout);
	int orig_ret_val = printf(fstr, s);
	printf("\n");

	printf("ft	|");
	fflush(stdout);
	int ft_ret_val = ft_printf(fstr, s);
	printf("\n");
	fflush(stdout);

	printf("returns	|%d, ", orig_ret_val);
	printf("%d\n", ft_ret_val);
	printf("\n");

	test_num++;

	fflush(stdout);
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

// void decimal_numbers_tests()
// {
// 	printf("\nPRINTF()\n");
// 	printf("%d\n", 7);
// 	printf("% d\n", 7);
// 	printf("%3d\n", 7);
// 	printf("% 3d\n", 7);
// 	printf("% 3d\n", 777);
// 	printf("% -3dPADDING\n", 7);
// 	printf("% -3dPADDING\n", 777);
// 	printf("---\n");
// 	printf("%3d\n", 9);
// 	printf("%.3d\n", 9);
// 	printf("%3.3d\n", 9);
// 	printf("%6.3d\n", 9);
// 	printf("%3.6d\n", 9);
// 	printf("---\n");
// 	printf("%-3dPADDING\n", 9);
// 	printf("%-.3dPADDING\n", 9);
// 	printf("%-3.3dPADDING\n", 9);
// 	printf("%-6.3dPADDING\n", 9);
// 	printf("%-3.6dPADDING\n", 9);
// 	printf("---\n");
// 	printf("%03d\n", 9);
// 	printf("%0.3d\n", 9);
// 	printf("%03.3d\n", 9);
// 	printf("%06.3d\n", 9);
// 	printf("%03.6d\n", 9);
// 	printf("---\n");
// 	printf("%.4d\n", 5);
// 	printf("---\n");
// 	printf("---\n");
// 	printf("% 3d\n", 9);
// 	printf("% .3d\n", 9);
// 	printf("% 3.3d\n", 9);
// 	printf("% 6.3d\n", 9);
// 	printf("% 3.6d\n", 9);
// 	printf("---\n");
// 	printf("% -3dPADDING\n", 9);
// 	printf("% -.3dPADDING\n", 9);
// 	printf("% -3.3dPADDING\n", 9);
// 	printf("% -6.3dPADDING\n", 9);
// 	printf("% -3.6dPADDING\n", 9);
// 	printf("---\n");
// 	printf("% 03d\n", 9);
// 	printf("% 0.3d\n", 9);
// 	printf("% 03.3d\n", 9);
// 	printf("% 06.3d\n", 9);
// 	printf("% 03.6d\n", 9);
// 	printf("---\n");
// 	printf("% .4d\n", 5);
// 	printf("---\n");
// 	printf("% 6.3d\n", 9);
// 	printf("%+ 6.3d\n", 9);
// }

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
	print_title("Multi-CS");
	//test_printf_int("Hello %-03d World % 4.2d!", 7, 9);
	printf("Hello %-03d World % 4.2d!\n", 7, 9);
	ft_printf("Hello %-03d World % 4.2d!\n", 7, 9);

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

void unsigned_print_tests()
{
	test_printf_unsigned("%u", 7);
	test_printf_unsigned("%u", -7);
	print_title("Sign");
	test_printf_unsigned("%+u", 7);
	test_printf_unsigned("%+u", -7);
	print_title("Blank");
	test_printf_unsigned("% u", 7);
	test_printf_unsigned("% u", -7);
	print_title("Right Pad");
	test_printf_unsigned("%-3uP", +7);
	test_printf_unsigned("% -3uP", +7);
	test_printf_unsigned("% -11uP", +7);
	print_title("Min Width");
	test_printf_unsigned("%3u", 7);
	test_printf_unsigned("%1u", 7);
	test_printf_unsigned("%11u", 7);
	print_title("Zero Pad");
	test_printf_unsigned("%03u", 7);
	test_printf_unsigned("%01u", 7);
	test_printf_unsigned("%011u", 7);
	print_title("Point Pad");
	test_printf_unsigned("%.3u", 7);
	test_printf_unsigned("%.11u", 7);
	print_title("Mixed Flags");
	test_printf_unsigned("%6.3u", 7);
	test_printf_unsigned("%3.6u", 7);
	test_printf_unsigned("%22.11u", 7);
	test_printf_unsigned("%11.22u", 7);
	test_printf_unsigned("% 6.3u", 7);
	test_printf_unsigned("% 3.6u", 7);
	test_printf_unsigned("% 22.11u", 7);
	test_printf_unsigned("% 11.22u", 7);
	print_title("Multi-CS");
	//test_printf_unsigned("Hello %-03d World % 4.2d!", 7, 9);
	printf("Hello %-03u World % 4.2u!\n", 7, 9);
	ft_printf("Hello %-03u World % 4.2u!\n", 7, 9);
}

void tests_printf_char()
{
	test_printf_char("%cP", '\0');
	test_printf_char("%cP", '\n');
	test_printf_char("%cP", ' ');
	test_printf_char("%cP", '7');
	test_printf_char("%cP", 'a');
	test_printf_char("%cP", '~');
}

void tests_printf_string()
{
	test_printf_string("%sP", "hello");
	test_printf_string("%sP", " ");
	test_printf_string("%sP", "");
	test_printf_string("% sP", "hello");
	test_printf_string("% sP", " ");
	test_printf_string("% sP", "");
}

int main()
{
	//ft_decimal_numbers_tests();
	//unsigned_print_tests();
	tests_printf_char();
	tests_printf_string();
	//print_title("Sign Mixed");
	//printf("%6.3d\n", 6);
	//printf("%6.3d\n", -6);
	//printf("%.3d\n", 666);
	//printf("%.3d\n", -666);
	//printf("%.6d\n", 666);
	//printf("%.6d\n", -666);
	//printf("%-12.6dP\n", 777);
	//printf("%-12.6dP\n", -777);
	//printf("%-7.6dP\n", 777);
	//printf("%-7.6dP\n", -777);
	//printf("%+06d\n", 666);
	//printf("%+6d\n", 666);
	//printf("%+.6d\n", 666);
	//printf("%s\n", ft_itoa_signless(365));
	//printf("%s\n", ft_itoa_signless(-365));
	//printf("%s\n", ft_itoa_signless(1));
	//printf("%s\n", ft_itoa_signless(-1));
	//printf("%s\n", ft_itoa_signless(2147483647));
	//printf("%s\n", ft_itoa_signless(-2147483648));
	return (0);
}
