/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/13 17:06:02 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Are all these in use?
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h> //! REMOVE THIS GUY!

//! MAKE SURE ALL THESE FUNCTIONS ARE USED BETWEEN FILES IN THE END
char	*get_next_line(int fd);

char	*ft_malloc_zero(size_t n);
int		contains_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*free_and_null(char *s);
int		ft_strlen(char *s);
char	*ft_memcpy(char *s1, char *s2, int n);

