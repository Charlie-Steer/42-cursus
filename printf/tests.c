#include "ft_printf.h"

// void	test_print_parsed_cs(t_conv_spec cs)
// {
// 	printf("cs:		%c\n", cs.conv_specifier);
// 	printf("min_width:	%d\n", cs.min_width);
// 	printf("pt_width:	%d\n", cs.point_width);
// 	printf("alt?:		%d\n", cs.has_alternate);
// 	printf("blank?:		%d\n", cs.has_blank);
// 	printf("point?:		%d\n", cs.has_point);
// 	printf("right_pad?:	%d\n", cs.has_right_pad);
// 	printf("sign?:		%d\n", cs.has_sign);
// 	printf("zero_pad?:	%d\n", cs.has_zero_pad);
// }

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

void test_printf_hex(char *fstr, unsigned int n)
{
	static int test_num = 1;
	printf("TEST #%02d\n", test_num);

	printf("inputs	|\"%s\", %x\n", fstr, n);

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

void test_printf_pointer(char *fstr, void *n)
{
	static int test_num = 1;
	printf("TEST #%02d\n", test_num);

	printf("inputs	|\"%s\", %p\n", fstr, n);

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

void tests_printf_int()
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
	//printf("Hello %-03d World % 4.2d!\n", 7, 9);
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

void tests_printf_uint()
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
	//printf("Hello %-03u World % 4.2u!\n", 7, 9);
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

void tests_printf_hex()
{
	test_printf_hex("%x", 7);
	test_printf_hex("%x", -7);
	print_title("Sign");
	test_printf_hex("%+x", 7);
	test_printf_hex("%+x", -7);
	print_title("Blank");
	test_printf_hex("% x", 7);
	test_printf_hex("% x", -7);
	print_title("Right Pad");
	test_printf_hex("%-3xP", +7);
	test_printf_hex("% -3xP", +7);
	test_printf_hex("% -11xP", +7);
	print_title("Min Width");
	test_printf_hex("%3x", 7);
	test_printf_hex("%1x", 7);
	test_printf_hex("%11x", 7);
	print_title("Zero Pad");
	test_printf_hex("%03x", 7);
	test_printf_hex("%01x", 7);
	test_printf_hex("%011x", 7);
	print_title("Point Pad");
	test_printf_hex("%.3x", 7);
	test_printf_hex("%.11x", 7);
	print_title("Mixed Flags");
	test_printf_hex("%6.3x", 7);
	test_printf_hex("%3.6x", 7);
	test_printf_hex("%22.11x", 7);
	test_printf_hex("%11.22x", 7);
	test_printf_hex("% 6.3x", 7);
	test_printf_hex("% 3.6x", 7);
	test_printf_hex("% 22.11x", 7);
	test_printf_hex("% 11.22x", 7);

	test_printf_hex("%xP", 200);
	test_printf_hex("%xP", -200);
	print_title("Sign");
	test_printf_hex("%+xP", 200);
	test_printf_hex("%+xP", -200);
	print_title("Blank");
	test_printf_hex("% xP", 200);
	test_printf_hex("% xP", -200);
	print_title("Right Pad");
	test_printf_hex("%-3xP", +200);
	test_printf_hex("% -3xP", +200);
	test_printf_hex("% -11xP", +200);
	print_title("Min Width");
	test_printf_hex("%3xP", 200);
	test_printf_hex("%1xP", 200);
	test_printf_hex("%11xP", 200);
	print_title("Zero Pad");
	test_printf_hex("%03xp", 200);
	test_printf_hex("%01xP", 200);
	test_printf_hex("%011xP", 200);
	print_title("Point Pad");
	test_printf_hex("%.3xP", 200);
	test_printf_hex("%.11xP", 200);
	print_title("Mixed Flags");
	test_printf_hex("%6.3xP", 200);
	test_printf_hex("%3.6xP", 200);
	test_printf_hex("%22.11xP", 200);
	test_printf_hex("%11.22xP", 200);
	test_printf_hex("% 6.3xP", 200);
	test_printf_hex("% 3.6xP", 200);
	test_printf_hex("% 22.11xP", 200);
	test_printf_hex("% 11.22xP", 200);

	print_title("Alternate Form Flags");

	test_printf_hex("%#X", 7);
	test_printf_hex("%#X", -7);
	print_title("Sign");
	test_printf_hex("%#+X", 7);
	test_printf_hex("%#+X", -7);
	print_title("Blank");
	test_printf_hex("%# X", 7);
	test_printf_hex("%# X", -7);
	print_title("Right Pad");
	test_printf_hex("%#-3XP", +7);
	test_printf_hex("%# -3XP", +7);
	test_printf_hex("%# -11XP", +7);
	print_title("Min Width");
	test_printf_hex("%#3X", 7);
	test_printf_hex("%#1X", 7);
	test_printf_hex("%#11X", 7);
	print_title("Zero Pad");
	test_printf_hex("%#03X", 7);
	test_printf_hex("%#01X", 7);
	test_printf_hex("%#011X", 7);
	print_title("Point Pad");
	test_printf_hex("%#.3X", 7);
	test_printf_hex("%#.11X", 7);
	print_title("Mixed Flags");
	test_printf_hex("%#6.3X", 7);
	test_printf_hex("%#3.6X", 7);
	test_printf_hex("%#22.11X", 7);
	test_printf_hex("%#11.22X", 7);
	test_printf_hex("%# 6.3X", 7);
	test_printf_hex("%# 3.6X", 7);
	test_printf_hex("%# 22.11X", 7);
	test_printf_hex("%# 11.22X", 7);
	
	test_printf_hex("%#XP", 200);
	test_printf_hex("%#XP", -200);
	print_title("Sign");
	test_printf_hex("%#+XP", 200);
	test_printf_hex("%#+XP", -200);
	print_title("Blank");
	test_printf_hex("%# XP", 200);
	test_printf_hex("%# XP", -200);
	print_title("Right Pad");
	test_printf_hex("%#-3XP", +200);
	test_printf_hex("%# -3XP", +200);
	test_printf_hex("%# -11XP", +200);
	print_title("Min Width");
	test_printf_hex("%#3XP", 200);
	test_printf_hex("%#1XP", 200);
	test_printf_hex("%#11XP", 200);
	print_title("Zero Pad");
	test_printf_hex("%#03Xp", 200);
	test_printf_hex("%#01XP", 200);
	test_printf_hex("%#011XP", 200);
	print_title("Point Pad");
	test_printf_hex("%#.3XP", 200);
	test_printf_hex("%#.11XP", 200);
	print_title("Mixed Flags");
	test_printf_hex("%#6.3XP", 200);
	test_printf_hex("%#3.6XP", 200);
	test_printf_hex("%#22.11XP", 200);
	test_printf_hex("%#11.22XP", 200);
	test_printf_hex("%# 6.3XP", 200);
	test_printf_hex("%# 3.6XP", 200);
	test_printf_hex("%# 22.11XP", 200);
	test_printf_hex("%# 11.22XP", 200);
}

void tests_printf_pointer()
{
	int a = 5;
    int *p = &a;
    test_printf_pointer("%p", p);
    test_printf_pointer("%p", p);
    print_title("Sign");
    test_printf_pointer("%+p", p);
    test_printf_pointer("%+p", p);
    print_title("Blank");
    test_printf_pointer("% p", p);
    test_printf_pointer("% p", p);
    print_title("Right Pad");
    test_printf_pointer("%-3pP", p);
    test_printf_pointer("% -3pP", p);
    test_printf_pointer("% -11pP", p);
    print_title("Min Width");
    test_printf_pointer("%3p", p);
    test_printf_pointer("%1p", p);
    test_printf_pointer("%11p", p);
    print_title("Zero Pad");
    test_printf_pointer("%03pp", p);
    test_printf_pointer("%01p", p);
    test_printf_pointer("%011p", p);
    print_title("Point Pad");
    test_printf_pointer("%.3p", p);
    test_printf_pointer("%.11p", p);
    print_title("Mixed Flags");
    test_printf_pointer("%6.3p", p);
    test_printf_pointer("%3.6p", p);
    test_printf_pointer("%22.11p", p);
    test_printf_pointer("%11.22p", p);
    test_printf_pointer("% 6.3p", p);
    test_printf_pointer("% 3.6p", p);
    test_printf_pointer("% 22.11p", p);
    test_printf_pointer("% 11.22p", p);

    test_printf_pointer("%pP", p);
    test_printf_pointer("%pP", p);
    print_title("Sign");
    test_printf_pointer("%+pP", p);
    test_printf_pointer("%+pP", p);
    print_title("Blank");
    test_printf_pointer("% pP", p);
    test_printf_pointer("% pP", p);
    print_title("Right Pad");
    test_printf_pointer("%-3pP", p);
    test_printf_pointer("% -3pP", p);
    test_printf_pointer("% -11pP", p);
    print_title("Min Width");
    test_printf_pointer("%3pP", p);
    test_printf_pointer("%1pP", p);
    test_printf_pointer("%11pP", p);
    print_title("Zero Pad");
    test_printf_pointer("%03pp", p);
    test_printf_pointer("%01pP", p);
    test_printf_pointer("%011pP", p);
    print_title("Point Pad");
    test_printf_pointer("%.3pP", p);
    test_printf_pointer("%.11pP", p);
    print_title("Mixed Flags");
    test_printf_pointer("%6.3pP", p);
    test_printf_pointer("%3.6pP", p);
    test_printf_pointer("%22.11pP", p);
    test_printf_pointer("%11.22pP", p);
    test_printf_pointer("% 6.3pP", p);
    test_printf_pointer("% 3.6pP", p);
    test_printf_pointer("% 22.11pP", p);
    test_printf_pointer("% 11.22pP", p);

    print_title("Alternate Form Flags");

    test_printf_pointer("%#p", p);
    test_printf_pointer("%#p", p);
    print_title("Sign");
    test_printf_pointer("%#+p", p);
    test_printf_pointer("%#+p", p);
    print_title("Blank");
    test_printf_pointer("%# p", p);
    test_printf_pointer("%# p", p);
    print_title("Right Pad");
    test_printf_pointer("%#-3pP", p);
    test_printf_pointer("%# -3pP", p);
    test_printf_pointer("%# -11pP", p);
    print_title("Min Width");
    test_printf_pointer("%#3p", p);
    test_printf_pointer("%#1p", p);
    test_printf_pointer("%#11p", p);
    print_title("Zero Pad");
    test_printf_pointer("%#03p", p);
    test_printf_pointer("%#01p", p);
    test_printf_pointer("%#011p", p);
    print_title("Point Pad");
    test_printf_pointer("%#.3p", p);
    test_printf_pointer("%#.11p", p);
    print_title("Mixed Flags");
    test_printf_pointer("%#6.3p", p);
    test_printf_pointer("%#3.6p", p);
    test_printf_pointer("%#22.11p", p);
    test_printf_pointer("%#11.22p", p);
    test_printf_pointer("%# 6.3p", p);
    test_printf_pointer("%# 3.6p", p);
    test_printf_pointer("%# 22.11p", p);
    test_printf_pointer("%# 11.22p", p);

	print_title("Additional Tests");
	test_printf_pointer("%+14p", p);
	test_printf_pointer("% 14p", p);
	test_printf_pointer("%+014p", p);
	test_printf_pointer("% 014p", p);
}

void tests_printf_pointer_problem_tests()
{
	int a = 5;
    int *p = &a;
    test_printf_pointer("%22.11p", p);
    test_printf_pointer("% 22.11p", p);
    test_printf_pointer("%22.11pP", p);
    test_printf_pointer("% 22.11pP", p);
    test_printf_pointer("%#22.11pP", p);
    test_printf_pointer("%18.8p", p);
    test_printf_pointer("% 22.11p", p);
    test_printf_pointer("%22.11pP", p);
    test_printf_pointer("% 22.11pP", p);
    test_printf_pointer("%#22.11pP", p);
}

void tests_printf_mixed()
{
	//int a = 13;
	//void *p = &a;
	void *p;
	printf("\n\nc: %12cP\ns: %12sP\nd: %12dP\ni: %12iP\nu: %12uP\nx: %#12xP\nX: %#12XP\np: %12pP\n%12%: %%P\n",
		'g', "Charlie", 42, -42, -1, 365, 14649, p);
	ft_printf("\n\nc: %12cP\ns: %12sP\nd: %12dP\ni: %12iP\nu: %12uP\nx: %#12xP\nX: %#12XP\np: %12pP\n%12%: %%P\n",
		'g', "Charlie", 42, -42, -1, 365, 14649, p);
	printf("\n\nc: %-12cP\ns: %-12sP\nd: %-12dP\ni: %-12iP\nu: %-12uP\nx: %-#12xP\nX: %-#12XP\np: %-12pP\n%%: %-12%P\n",
		'g', "Charlie", 42, -42, -1, 365, 14649, p);
	ft_printf("\n\nc: %-12cP\ns: %-12sP\nd: %-12dP\ni: %-12iP\nu: %-12uP\nx: %-#12xP\nX: %-#12XP\np: %-12pP\n%%: %-12%P\n",
		'g', "Charlie", 42, -42, -1, 365, 14649, p);
}

void tests_francinette_strings_01()
{
	print_title("STRINGS 01");
	test_printf_string("%-s", NULL);
	test_printf_string("%23s", NULL);
	test_printf_pointer("%p", NULL);
	test_printf_string("%s", NULL);
	test_printf_string("%.3sP", "hello");
	test_printf_string("%.sP", "hello");
	test_printf_string("%.0sP", "hello");
	test_printf_string("%.3sP", "holla");
	test_printf_string("%.2sP", "hello");
	test_printf_string("%.7sP", "hello");
	test_printf_string("%7.5sP", "bombastic");
	test_printf_string("%-7.5sP", "tubular");
	test_printf_string("%7.3sP", "hello");
	test_printf_string("%7.7sP", "world");
}

static void tests_francinette_mixed_01()
{
	print_title("MIXED 01");
	test_printf_string("%-sP", NULL);
	test_printf_string("%23sP", NULL);
	test_printf_string("%10sP", NULL);
	test_printf_string("%pP", NULL);
	test_printf_string("%sP", NULL);
	test_printf_string("hello, %s.P", NULL);
	test_printf_string("%sP", NULL);
	test_printf_string("%32sP", NULL);
	test_printf_string("%2sP", NULL);
	test_printf_string("%-32sP", NULL);
	test_printf_string("%-16sP", NULL);
	test_printf_string("%-8sP", NULL);
	test_printf_string("%-3sP", NULL);
	test_printf_string("%.09sP", NULL);
	test_printf_string("%3.sP", NULL);
	test_printf_string("%10.sP", NULL);
	test_printf_string("%-3.sP", NULL);
	test_printf_string("%-8.sP", NULL);
	test_printf_string("%3.1sP", NULL);
	test_printf_string("%9.1sP", NULL);
	test_printf_string("%-3.1sP", NULL);
	test_printf_string("%-9.1sP", NULL);
	test_printf_string("%3.1sP", NULL);
	test_printf_string("%3.2sP", NULL);
	test_printf_string("%3.3sP", NULL);
}

static void tests_francinette_mixed_02()
{
	print_title("MIXED 02");
	test_printf_string("%p", NULL);
	test_printf_string("%3.6sP", NULL);
	test_printf_string("%3.8sP", NULL);
	test_printf_string("%3.20sP", NULL);
	test_printf_string("%3.0sP", NULL);
	test_printf_string("%8.0sP", NULL);
	test_printf_string("%0.8sP", NULL);
	test_printf_string("%20.6sP", NULL);
	test_printf_string("%-3.8s", NULL);
	test_printf_string("%-10.8s", NULL);
	test_printf_int("%.6i", -3);
	test_printf_int("%10.5i", -216);
	test_printf_int("%3.7i", -2375);
	test_printf_int("%-8.5i", 34);
	test_printf_int("%-10.5i", -216);
	test_printf_int("%-8.5i", 0);
	test_printf_int("%-8.3i", 8375);
	test_printf_int("%-8.3i", -8473);
	test_printf_int("%-3.7i", -2375);
	test_printf_int("%08.5i", 34);
	test_printf_int("%010.5i", -216);
	test_printf_int("%08.5i", 0);
	test_printf_int("%08.3i", 8375);
	test_printf_int("%08.3i", -8473);
	test_printf_int("%03.7i", -2375);
}

static void tests_francinette_strings_02()
{
	print_title("STRINGS 02");
	test_printf_string("%3.sP", NULL);
	test_printf_string("%10.sP", NULL);
	test_printf_string("%-3.sP", NULL);
	test_printf_string("%-8.sP", NULL);
	test_printf_string("%3.1sP", NULL);
	test_printf_string("%9.1sP", NULL);
	test_printf_string("%-3.1sP", NULL);
	test_printf_string("%-9.1sP", NULL);
	test_printf_string("%3.6sP", NULL);
	test_printf_string("%3.8sP", NULL);
	test_printf_string("%3.20sP", NULL);
	test_printf_string("%3.0sP", NULL);
	test_printf_string("%8.0sP", NULL);
	test_printf_string("%0.8sP", NULL);
	test_printf_string("%20.6sP", NULL);
	test_printf_string("%3.6sP", NULL);
	test_printf_string("%6.6sP", NULL);
	test_printf_string("%3.3sP", NULL);
	test_printf_string("%4.3sP", NULL);
	test_printf_string("%3.4sP", NULL);
}

static void tests_francinette_ints_01()
{
	print_title("INTS 01");
	test_printf_int("%.6i", -3);
	test_printf_int("%10.5i", -216);
	test_printf_int("%3.7i", -2375);
	test_printf_int("%-8.5iP", 34);
	test_printf_int("%-10.5iP", -216);
	test_printf_int("%-8.5iP", 0);
	test_printf_int("%-8.3iP", 8375);
	test_printf_int("%-8.3iP", -8473);
	test_printf_int("%-3.7iP", -2375);
	test_printf_int("%08.5i", 34);
	test_printf_int("%010.5i", -216);
	test_printf_int("%08.5i", 0);
	test_printf_int("%08.3i", 8375);
	test_printf_int("%08.3i", -8473);
	test_printf_int("%03.7i", -2375);
	test_printf_int("%.0iP", 0);
	test_printf_int("%.iP", 0);
	test_printf_int("%5.0iP", 0);
	test_printf_int("%5.iP", 0);
}

static void tests_francinette_ints_02()
{
	print_title("INTS 02");
	test_printf_int("%-10.5iP", 216);
	test_printf_int("%-10.5iP", -216);
	test_printf_int("%-8.3iP", -8473);
}

static void tests_francinette_ints_03()
{
	print_title("INTS 03");
	test_printf_int("%08.5i", 34);
	test_printf_int("%010.5i", -216);
	test_printf_int("%08.5i", 0);
	test_printf_int("%08.3i", 8375);
	test_printf_int("%08.3i", -8473);
	test_printf_int("%03.7i", -2375);
}

static void tests_francinette_ints_04()
{
	print_title("INTS 04");
	test_printf_int("%.0iP", 0);
	test_printf_int("%.iP", 0);
	test_printf_int("%5.0iP", 0);
	test_printf_int("%5.iP", 0);
	test_printf_int("%.0iP", 5);
	test_printf_int("%.iP", 5);
	test_printf_int("%5.0iP", 5);
	test_printf_int("%5.iP", 5);
	test_printf_int("%.0iP", 0);
	test_printf_int("%.0iP", 7);
	test_printf_int("%.1iP", 0);
	test_printf_int("%.5iP", 0);
	test_printf_int("%.iP", 0);
	test_printf_int("%5.0iP", 0);
	test_printf_int("%5.iP", 0);
}

static void tests_francinette_ints_05()
{
	print_title("INTS 05");
	test_printf_int("this %i number", 0);
	test_printf_int("%i", 0);
	test_printf_int("this %d number", 0);
	test_printf_int("%3i", 0);
	test_printf_int("%-3i", 0);
	test_printf_int("%.3i", 0);
	test_printf_int("%03i", 0);
	test_printf_int("%8.5i", 0);
	test_printf_int("%-8.5i", 0);
	test_printf_int("%08.5i", 0);
	test_printf_int("%5.0i", 0);
	test_printf_int("%5.i", 0);
	test_printf_int("%-5.0i", 0);
	test_printf_int("%-5.i", 0);
	test_printf_int("%d", 0);
	test_printf_int("%3d", 0);
	test_printf_int("%-3d", 0);
	test_printf_int("%.3d", 0);
	test_printf_int("%03d", 0);
	test_printf_int("%8.5d", 0);
}

static void tests_francinette_ints_06()
{
	print_title("INTS 06");
	test_printf_int("%5.0iP", 0);
	test_printf_int("%5.iP", 0);
	test_printf_int("%-5.0iP", 0);
	test_printf_int("%-5.iP", 0);
	test_printf_int("%5.0dP", 0);
	test_printf_int("%5.dP", 0);
	test_printf_int("%-5.0dP", 0);
	test_printf_int("%-5.dP", 0);
}

static void tests_francinette_uints_01()
{
	print_title("UNSIGNED 01");
	test_printf_unsigned("%-8.5uP", 34);
	test_printf_unsigned("%-8.5uP", 0);
	test_printf_unsigned("%-8.3uP", 8375);
	test_printf_unsigned("%08.5uP", 34);
	test_printf_unsigned("%08.5uP", 0);
	test_printf_unsigned("%08.3uP", 8375);
	test_printf_unsigned("%.0uP", 0);
	test_printf_unsigned("%.uP", 0);
	test_printf_unsigned("%5.0uP", 0);
	test_printf_unsigned("%5.uP", 0);
	test_printf_unsigned("%-5.0uP", 0);
	test_printf_unsigned("%-5.uP", 0);
}

static void tests_francinette_hex_01()
{
	print_title("HEX 01");
	test_printf_hex("%-8.5xP", 34);
	test_printf_hex("%-8.5xP", 0);
	test_printf_hex("%-8.3xP", 8375);
	test_printf_hex("%08.5xP", 34);
	test_printf_hex("%08.5xP", 0);
	test_printf_hex("%08.3xP", 8375);
	test_printf_hex("%.0xP", 0);
	test_printf_hex("%.xP", 0);
	test_printf_hex("%5.0xP", 0);
	test_printf_hex("%5.xP", 0);
	test_printf_hex("%-5.0xP", 0);
	test_printf_hex("%-5.xP", 0);
	test_printf_hex("%-8.5xP", 34);
	test_printf_hex("%-8.5xP", 0);
	test_printf_hex("%-8.3xP", 8375);
	test_printf_hex("%08.5xP", 34);
	test_printf_hex("%08.5xP", 0);
	test_printf_hex("%08.3xP", 8375);
	test_printf_hex("%.0xP", 0);
	test_printf_hex("%.xP", 0);
}

static void tests_francinette_hex_02()
{
	print_title("HEX 02");
	test_printf_hex("%5.0xP", 0);
	test_printf_hex("%5.xP", 0);
	test_printf_hex("%-5.0xP", 0);
	test_printf_hex("%-5.xP", 0);
	test_printf_hex("%5.0xP", 0);
	test_printf_hex("%5.xP", 0);
	test_printf_hex("%-5.0xP", 0);
	test_printf_hex("%-5.xP", 0);
	test_printf_hex("%5.0XP", 0);
	test_printf_hex("%5.XP", 0);
	test_printf_hex("%-5.0XP", 0);
	test_printf_hex("%-5.XP", 0);
}

static void tests_francinette_pointers_01()
{
	print_title("POINTERS 01");
	test_printf_pointer("%p", NULL);
	test_printf_pointer("%15pP", NULL);
	test_printf_pointer("%-15pP", NULL);
}

static void tests_francinette_mix_01()
{
	print_title("ORIGINAL");
	printf("t7 %1.50dP", -10);
	//printf("%052.88i%-87.137u%--81.25X%26c%--198.131iP" ,1348141248,2480967409u,3367743035u,96,340172724);
	//printf("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170xP" ,2109506632u,-1086209677,"mD^8<.q*'\rD",-1143516304,2879456117u);
	//printf("%-127.104s%-26.169d%--60.88i%142.52sP" ,"",955786883,-1974652066,"d^ex<#[F\v>=ka/hj");
	//printf("%--133.48i%-103.188u%0003.72XP" ,1341200964,3945708301u,3224169818u);
	//printf("%0%%0104.20x%---176p%--8.25X%-120.98iP" ,462982545u,(void*)2547223992875393254lu,1267937232u,640121608);
	//printf("%-154.60i%---171.156XP\n" ,-857650046,907002431u);
	//printf("%06.38i%-168.40X%0074.18d%-158pP\n" ,514862160,1406013807u,-595638242,(void*)15381379978655233653lu);
	//printf("%--99.86i%158.71sP\n" ,-37593293,"`pz,\ne#.\v$HZjf");
	//printf("%---105p%-%%--150.iP\n" ,(void*)5854188174500153960lu,-1646567843);
	//printf("%029.173iP\n" ,1159327133);
	//printf("%-38p%--.31iP\n" ,(void*)4772992227276040767lu,-1118940749);
	//printf("%34c%--142.160x%--10.37i%--94.58u%-157cP\n" ,62,639732752u,-1818745559,2508057613u,100);
	//printf("%-165.150s%0160.168iP\n" ,"W(xKHU7D:2",1264678805);
	//printf("%00065.197d%132p%-%%-173.71i%--1.32iP\n" ,-699619784,(void*)4809237208452777030lu,366715426,-1301410622);
	//printf("%00070.99u%00142.132x%---78.52d%-147.134i%-%P\n" ,1060731427u,715254811u,-1080597013,-611888681);
	//printf("%-186.138i%86p%-113c%--87pP\n" ,-1320475933,(void*)11899625258064503923lu,-39,(void*)15206197846470084523lu);
	//printf("%-106p%--%%---16.39i%-62.45s%032.34uP\n" ,(void*)4820041568133212049lu,1496653732,"78iTF|2mbbziDh\n0^?Q0",3823859301u);
	//printf("%00101.6i%-41.55d%-%%-76p%--81pP\n" ,383803588,1279553359,(void*)11248044234994893080lu,(void*)8032604661431581565lu);
	//printf("%057.155dP\n" ,-1801054431);
	print_title("FT");
	ft_printf("t7 %1.50dP\n", -10);
	//ft_printf("%052.88i%-87.137u%--81.25X%26c%--198.131iP\n" ,1348141248,2480967409u,3367743035u,96,340172724);
	//ft_printf("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170xP\n" ,2109506632u,-1086209677,"\nmD^8<.q*'\rD",-1143516304,2879456117u);
	//ft_printf("%-127.104s%-26.169d%--60.88i%142.52sP\n" ,"",955786883,-1974652066,"d^ex<#[F\v>=ka/hj");
	//ft_printf("%--133.48i%-103.188u%0003.72XP\n" ,1341200964,3945708301u,3224169818u);
	//ft_printf("%0%%0104.20x%---176p%--8.25X%-120.98iP\n" ,462982545u,(void*)2547223992875393254lu,1267937232u,640121608);
	//ft_printf("%-154.60i%---171.156XP\n" ,-857650046,907002431u);
	//ft_printf("%06.38i%-168.40X%0074.18d%-158pP\n" ,514862160,1406013807u,-595638242,(void*)15381379978655233653lu);
	//ft_printf("%--99.86i%158.71sP\n" ,-37593293,"`pz,\ne#.\v$HZjf");
	//ft_printf("%---105p%-%%--150.iP\n" ,(void*)5854188174500153960lu,-1646567843);
	//ft_printf("%029.173iP\n" ,1159327133);
	//ft_printf("%-38p%--.31iP\n" ,(void*)4772992227276040767lu,-1118940749);
	//ft_printf("%34c%--142.160x%--10.37i%--94.58u%-157cP\n" ,62,639732752u,-1818745559,2508057613u,100);
	//ft_printf("%-165.150s%0160.168iP\n" ,"W(xKHU7D:2",1264678805);
	//ft_printf("%00065.197d%132p%-%%-173.71i%--1.32iP\n" ,-699619784,(void*)4809237208452777030lu,366715426,-1301410622);
	//ft_printf("%00070.99u%00142.132x%---78.52d%-147.134i%-%P\n" ,1060731427u,715254811u,-1080597013,-611888681);
	//ft_printf("%-186.138i%86p%-113c%--87pP\n" ,-1320475933,(void*)11899625258064503923lu,-39,(void*)15206197846470084523lu);
	//ft_printf("%-106p%--%%---16.39i%-62.45s%032.34uP\n" ,(void*)4820041568133212049lu,1496653732,"78iTF|2mbbziDh\n0^?Q0",3823859301u);
	//ft_printf("%00101.6i%-41.55d%-%%-76p%--81pP\n" ,383803588,1279553359,(void*)11248044234994893080lu,(void*)8032604661431581565lu);
	//ft_printf("%057.155dP\n" ,-1801054431);
}

static void tests_printf_correction_01()
{
	int n;
	void *p = &n;
	test_printf_pointer("%p", p);
	test_printf_pointer("%p", NULL);
	test_printf_string("%s", NULL);
	test_printf_pointer("%c", NULL);
	test_printf_string("%s", NULL);
	test_printf_int("%d", NULL);
	test_printf_int("%i", NULL);
	test_printf_unsigned("%u", NULL);
	test_printf_hex("%x", NULL);
	test_printf_hex("%X", NULL);
}

static void tests_eval_01()
{
	print_title("TESTS EVAL 01");
	int a = 5;
	void *p = &a;
	test_printf_char("%c", 'H');
	test_printf_string("%s", "hello world");
	test_printf_pointer("%p", p);
	test_printf_int("%i", 42);
	test_printf_int("%d", -42);
	test_printf_unsigned("%u", -42);
	test_printf_hex("%x", 4251);
	test_printf_hex("%X", 4251);
	printf("\nprintf	|%%\n");
	ft_printf("ft	|%%\n");
	printf("\nreturns |%d, %d\n", printf("%%\n"), ft_printf("%%\n"));
}

static void tests_eval_02()
{
	print_title("TESTS EVAL 02");
	int a = 5;
	void *p = &a;
	test_printf_char("%c", NULL);
	test_printf_string("%s", NULL);
	test_printf_pointer("%p", NULL);
	test_printf_int("%i", NULL);
	test_printf_int("%d", NULL);
	test_printf_unsigned("%u", NULL);
	test_printf_hex("%x", NULL);
	test_printf_hex("%X", NULL);
}

static void tests_eval_03()
{
	print_title("TESTS EVAL 03");
	int a = 5;
	void *p = &a;
	test_printf_string("%s", "");
	test_printf_int("%i", -2147483648);
	test_printf_int("%d", 2147483647);
	test_printf_int("%d", 2147483648u);
	test_printf_unsigned("%u", 0);
	test_printf_unsigned("%u", 4294967295u);
	test_printf_hex("%x", 0);
	test_printf_hex("%X", 4294967295u);
	test_printf_hex("%X", 4294967296lu);
}

static void tests_eval_04()
{
	print_title("TESTS EVAL 04");
	int a = 5;
	void *p = &a;

	printf("returns	|%d, %d\n",
		   printf("\n\nc: %12cP\ns: %12sP\nd: %12dP\ni: %12iP\nu: %12uP\nx: %#12xP\nX: %#12XP\np: %12pP\n%12%: %%P\n", 'g', "Charlie", 42, -42, -1, 365, 14649, p),
		ft_printf("\n\nc: %12cP\ns: %12sP\nd: %12dP\ni: %12iP\nu: %12uP\nx: %#12xP\nX: %#12XP\np: %12pP\n%12%: %%P\n", 'g', "Charlie", 42, -42, -1, 365, 14649, p));
	printf("returns	|%d, %d\n",
		   printf("\n\nc: %-12cP\ns: %-12sP\nd: %-12dP\ni: %-12iP\nu: %-12uP\nx: %-#12xP\nX: %-#12XP\np: %-12pP\n%%: %-12%P\n", 'g', "Charlie", 42, -42, -1, 365, 14649, p),
		ft_printf("\n\nc: %-12cP\ns: %-12sP\nd: %-12dP\ni: %-12iP\nu: %-12uP\nx: %-#12xP\nX: %-#12XP\np: %-12pP\n%%: %-12%P\n", 'g', "Charlie", 42, -42, -1, 365, 14649, p));
}

static void tests_eval_05()
{
	print_title("TESTS EVAL 05");
	int a = 5;
	void *p = &a;

	printf("returns |%d, %d\n\n", printf("%c, %c, %c\n", 'H', 'H', 'H'), ft_printf("%c, %c, %c\n", 'H', 'H', 'H'));

	printf("returns |%d, %d\n\n", printf("%s, %s, %s\n", "hello world", "hello world", "hello world"), ft_printf("%s, %s, %s\n", "hello world", "hello world", "hello world"));

	printf("returns	|%d, %d\n\n", printf("%p, %p, %p\n", p, p, p), ft_printf("%p, %p, %p\n", p, p, p));

	printf("returns	|%d, %d\n\n", printf("%i, %i, %i\n", 42, 42, 42), ft_printf("%i, %i, %i\n", 42, 42, 42));

	printf("returns	|%d, %d\n\n", printf("%d, %d, %d\n", -42, -42, -42), ft_printf("%d, %d, %d\n", -42, -42, -42));

	printf("returns	|%d, %d\n\n", printf("%u, %u, %u\n", -42, -42, -42), ft_printf("%u, %u, %u\n", -42, -42, -42));

	printf("returns	|%d, %d\n\n", printf("%x, %x, %x\n", 4251, 4251, 4251), ft_printf("%x, %x, %x\n", 4251, 4251, 4251));
	printf("returns	|%d, %d\n\n", printf("%X, %X, %X\n", 4251, 4251, 4251), ft_printf("%X, %X, %X\n", 4251, 4251, 4251));

	printf("returns |%d, %d\n\n", printf("%%, %%, %%\n"), ft_printf("%%, %%, %%\n"));
}

static void tests_return_value_issues_01()
{
	test_printf_int("%.0iP", 0);
	test_printf_int("%.iP", 0);
	test_printf_unsigned("%.0uP", 0);
	test_printf_unsigned("%.uP", 0);
	test_printf_hex("%.0xP", 0);
	test_printf_hex("%.xP", 0);
	test_printf_pointer("%.0pP", 0);
	test_printf_pointer("%.pP", 0);
	test_printf_char("%.0cP", 0);
	test_printf_char("%.cP", 0);
	test_printf_string("%.0sP", 0);
	test_printf_string("%.sP", 0);
	test_printf_string("%.0sP", NULL);
	test_printf_string("%.sP", NULL);
	test_printf_string("%.0sP", "hello");
	test_printf_string("%.sP", "");

	test_printf_pointer("%15pP", NULL);
	test_printf_pointer("%-15pP", NULL);
	test_printf_pointer("%15.5pP", NULL);
	test_printf_pointer("%-15.5pP", NULL);
	test_printf_pointer("%5.15pP", NULL);
	test_printf_pointer("%-5.15pP", NULL);
	test_printf_pointer("%15.10pP", NULL);
	test_printf_pointer("%-15.10pP", NULL);
	test_printf_pointer("%10.15pP", NULL);
	test_printf_pointer("%-10.15pP", NULL);
}

static void tests_return_value_issues_02()
{
	print_title("STRINGS 01");
	test_printf_string("%-s", NULL);
	test_printf_string("%23s", NULL);
	test_printf_pointer("%p", NULL);
	test_printf_string("%s", NULL);
	test_printf_string("%.3sP", "hello");
	test_printf_string("%.sP", "hello");
	test_printf_string("%.0sP", "hello");
	test_printf_string("%.3sP", "holla");
	test_printf_string("%.2sP", "hello");
	test_printf_string("%.7sP", "hello");
	test_printf_string("%7.5sP", "bombastic");
	test_printf_string("%-7.5sP", "tubular");
	test_printf_string("%7.3sP", "hello");
	test_printf_string("%7.7sP", "world");
	print_title("MIXED 01");
	test_printf_string("%-sP", NULL);
	test_printf_string("%23sP", NULL);
	test_printf_string("%10sP", NULL);
	test_printf_string("%pP", NULL);
	test_printf_string("%sP", NULL);
	test_printf_string("hello, %s.P", NULL);
	test_printf_string("%sP", NULL);
	test_printf_string("%32sP", NULL);
	test_printf_string("%2sP", NULL);
	test_printf_string("%-32sP", NULL);
	test_printf_string("%-16sP", NULL);
	test_printf_string("%-8sP", NULL);
	test_printf_string("%-3sP", NULL);
	test_printf_string("%.09sP", NULL);
	test_printf_string("%3.sP", NULL);
	test_printf_string("%10.sP", NULL);
	test_printf_string("%-3.sP", NULL);
	test_printf_string("%-8.sP", NULL);
	test_printf_string("%3.1sP", NULL);
	test_printf_string("%9.1sP", NULL);
	test_printf_string("%-3.1sP", NULL);
	test_printf_string("%-9.1sP", NULL);
	test_printf_string("%3.1sP", NULL);
	test_printf_string("%3.2sP", NULL);
	test_printf_string("%3.3sP", NULL);
	print_title("MIXED 02");
	test_printf_string("%p", NULL);
	test_printf_string("%3.6sP", NULL);
	test_printf_string("%3.8sP", NULL);
	test_printf_string("%3.20sP", NULL);
	test_printf_string("%3.0sP", NULL);
	test_printf_string("%8.0sP", NULL);
	test_printf_string("%0.8sP", NULL);
	test_printf_string("%20.6sP", NULL);
	test_printf_string("%-3.8s", NULL);
	test_printf_string("%-10.8s", NULL);
	print_title("STRINGS 02");
	test_printf_string("%3.sP", NULL);
	test_printf_string("%10.sP", NULL);
	test_printf_string("%-3.sP", NULL);
	test_printf_string("%-8.sP", NULL);
	test_printf_string("%3.1sP", NULL);
	test_printf_string("%9.1sP", NULL);
	test_printf_string("%-3.1sP", NULL);
	test_printf_string("%-9.1sP", NULL);
	test_printf_string("%3.6sP", NULL);
	test_printf_string("%3.8sP", NULL);
	test_printf_string("%3.20sP", NULL);
	test_printf_string("%3.0sP", NULL);
	test_printf_string("%8.0sP", NULL);
	test_printf_string("%0.8sP", NULL);
	test_printf_string("%20.6sP", NULL);
	test_printf_string("%3.6sP", NULL);
	test_printf_string("%6.6sP", NULL);
	test_printf_string("%3.3sP", NULL);
	test_printf_string("%4.3sP", NULL);
	test_printf_string("%3.4sP", NULL);
}

int main()
{
	// tests_francinette_strings_01();
	// tests_francinette_mixed_01();
	// tests_francinette_mixed_02();
	// tests_francinette_strings_02();
	// tests_francinette_ints_01();
	// tests_francinette_ints_02();
	// tests_francinette_ints_03();
	// tests_francinette_ints_04();
	// tests_francinette_ints_05();
	// tests_francinette_ints_06();
	// tests_francinette_uints_01();
	// tests_francinette_hex_01();
	// tests_francinette_hex_02();
	// tests_francinette_pointers_01();
	tests_eval_01();
	tests_eval_02();
	tests_eval_03();
	tests_eval_04();
	tests_eval_05();
	//tests_return_value_issues_01();
	//tests_return_value_issues_02();

	return (0);
}
