/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/11 17:22:12 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h> //! REMOVE THIS GUY!

struct s_line_and_remainder
{
	char *line;
	char *remainder;
};

//! MAKE SURE ALL THESE FUNCTIONS ARE USED BETWEEN FILES IN THE END
char	*get_next_line(int fd);
int		get_char_index(char c, char *block, int n);
void	ft_bzero(char *block, int n);
int		ft_strlen(char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
