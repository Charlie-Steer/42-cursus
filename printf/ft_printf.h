/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:53:10 by cargonz2          #+#    #+#             */
/*   Updated: 2024/07/25 18:57:04 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! TEST WITHOUT THESE. IN CASE NON-FT FUNCTION USED.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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

int			ft_printf(char const *str, ...);

t_conv_spec	parse_conversion_specification(
				t_conv_spec cs, const char *str);
int			determine_cs_print_len(char *n_str, t_conv_spec cs);

int			print_char(int c, t_conv_spec cs);
int			print_str(char *str, t_conv_spec cs);
int			print_int(int n, t_conv_spec cs);
int			print_unsigned_int(unsigned int n, t_conv_spec cs);
int			print_hexadecimal(unsigned int n, t_conv_spec cs);
int			print_pointer(void *n, t_conv_spec cs);

int			int_add_prefix(char *print_str, char *n_str, t_conv_spec cs,
				int arg_len);
int			hexa_add_prefix(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len);
char		*get_hex_base(int conv_specifier);
int			pointer_add_prefix(char *print_str, t_conv_spec cs, char *n_str,
				int arg_len);

// LIBFT FUNCTIONS
int			ft_toupper(int c);
void		ft_putchar_fd(char c, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_itoa(int n);
void		ft_putstr_fd(char *s, int fd);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_itoa_unsigned(unsigned int n);
size_t		ft_strlen(const char *s);
int			ft_max(int a, int b);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_itoa_base(unsigned long n, char *base);
int			ft_isdigit(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_numlen(long num, int account_sign);
int			ft_numlen_base_unsigned(unsigned long num, char *base);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
