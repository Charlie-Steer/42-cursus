/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/11 21:53:16 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h> //! REMOVE THIS GUY!

typedef struct s_two_strings
{
	char *line;
	char *remainder;
} t_two_strings;

//! MAKE SURE ALL THESE FUNCTIONS ARE USED BETWEEN FILES IN THE END
char	*get_next_line(int fd);
int		get_char_index(char c, char *block, int n);
void	ft_bzero(char *block, int n);
int		ft_strlen(char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcat_n_max_of_b(char *a, char *b, int n);
