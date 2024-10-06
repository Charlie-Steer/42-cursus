/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:28:50 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/24 15:21:45 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_malloc_zero(size_t n)
{
	size_t	i;
	char	*new_block;

	new_block = malloc(n);
	if (!new_block)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_block[i] = '\0';
		i++;
	}
	return (new_block);
}

char	*gnl_free_and_null(char *s)
{
	if (s)
		free(s);
	s = NULL;
	return (NULL);
}

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_memcpy(char *s1, char *s2, int n)
{
	int	i;

	if (!s1)
		return (NULL);
	if (!s2)
		return (s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		s1_len;
	int		s2_len;

	if (!s1)
		s1_len = 0;
	else
		s1_len = gnl_strlen(s1);
	if (!s2)
		s2_len = 0;
	else
		s2_len = gnl_strlen(s2);
	new_s = gnl_malloc_zero(s1_len + s2_len + 1);
	if (!new_s)
		return (NULL);
	gnl_memcpy(new_s, s1, s1_len);
	gnl_memcpy(&(new_s[s1_len]), s2, s2_len);
	if (s1)
		free(s1);
	return (new_s);
}
