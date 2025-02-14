/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:00:38 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/14 14:24:16 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 2048
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_malloc_zero(size_t n);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_free_and_null(char *s);
int		gnl_strlen(char *s);
char	*gnl_memcpy(char *s1, char *s2, int n);

#endif
