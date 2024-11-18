/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:53:10 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/25 14:26:07 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_conv_spec
{
	int		has_blank;
	int		has_sign;
	int		has_zero_pad;
	int		has_right_pad;
	int		has_alternate;
	int		has_point;

	int		min_width;
	int		point_width;

	char	conv_specifier;
}	t_conv_spec;

// CORE FUNCTIONS
int			ft_printf(char const *str, ...);

t_conv_spec	pf_parse_conversion_specification(
				t_conv_spec cs, const char *str);
int			pf_determine_cs_print_len(char *n_str, t_conv_spec cs);

int			pf_print_char(int c, t_conv_spec cs);
int			pf_print_str(char *str, t_conv_spec cs);
int			pf_print_int(int n, t_conv_spec cs);
int			pf_print_unsigned_int(unsigned int n, t_conv_spec cs);
int			pf_print_hexadecimal(unsigned int n, t_conv_spec cs);
int			pf_print_pointer(void *n, t_conv_spec cs);

// HELPER FUNCTIONS
int			pf_int_add_prefix(char *print_str, char *n_str, t_conv_spec cs,
				int arg_len);
int			pf_hexa_add_prefix(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len);
char		*pf_get_hex_base(int conv_specifier);
int			pf_pointer_add_prefix(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len);
int			pf_add_pointer_arg(char *print_str, char *n_str, int arg_len);
int			pf_calc_min_width_comp(int str_len, t_conv_spec cs, char *str);
int			pf_print_point_str(char *str, int str_len, t_conv_spec cs);
int			pf_get_strlen(char *str, t_conv_spec cs);

// LIBFT FUNCTIONS
int			pf_toupper(int c);
int			pf_putchar_fd(char c, int fd);
char		*pf_strchr(const char *s, int c);
char		*pf_itoa(int n);
int			pf_putstr_fd(char *s, int fd);
void		*pf_memmove(void *dst, const void *src, size_t len);
char		*pf_itoa_unsigned(unsigned int n);
size_t		pf_strlen(const char *s);
int			pf_max(int a, int b);
void		*pf_memmove(void *dst, const void *src, size_t len);
char		*pf_itoa_base(unsigned long n, char *base);
int			pf_isdigit(int c);
int			pf_memcmp(const void *s1, const void *s2, size_t n);
int			pf_atoi(const char *str);
int			pf_numlen(long num, int account_sign);
int			pf_numlen_base_unsigned(unsigned long num, char *base);
void		*pf_memcpy(void *dst, const void *src, size_t n);
void		pf_bzero(void *s, size_t n);
int			pf_strncmp(const char *s1, const char *s2, size_t n);
#endif
