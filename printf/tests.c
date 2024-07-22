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

int main()
{
	tests_printf_int();
	tests_printf_uint();
	tests_printf_char();
	tests_printf_string();
	tests_printf_hex();
	tests_printf_pointer();
	tests_printf_mixed();
	return (0);
}
