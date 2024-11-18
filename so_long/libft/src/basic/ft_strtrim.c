/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:25 by cargonz2          #+#    #+#             */
/*   Updated: 2024/01/15 12:37:33 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_matches_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] != set[j])
		{
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

static size_t	find_matches_end(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	i = s1_len;
	j = 0;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0' && s1[i - 1] != set[j])
		{
			j++;
		}
		if (set[j] == '\0')
		{
			break ;
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	matches_start;
	size_t	matches_end;
	size_t	trimmed_len;
	char	*trimmed_str;

	matches_start = find_matches_start(s1, set);
	matches_end = find_matches_end(s1, set);
	if (matches_start >= matches_end)
		return (ft_strdup(""));
	trimmed_len = matches_end - matches_start;
	trimmed_str = malloc(trimmed_len + 1);
	if (trimmed_str == NULL)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + matches_start, trimmed_len + 1);
	return (trimmed_str);
}
