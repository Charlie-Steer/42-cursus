/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:14:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/01/30 00:42:27 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	word_count;
	int		found_word;
	size_t	i;

	word_count = 0;
	found_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			found_word = 0;
		}
		else if (!found_word)
		{
			found_word = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	word_len;
	size_t	i;

	word_len = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word_len++;
		i++;
	}
	return (word_len);
}

static char	**allocate_string_array(char const *s, char c)
{
	size_t	word_count;
	char	**str_arr;

	word_count = count_words(s, c);
	str_arr = malloc(sizeof(char *) * (word_count + 1));
	return (str_arr);
}

static size_t	allocate_string(char **str_arr, char const *s,
				size_t word_len, int j)
{
	str_arr[j] = ft_substr(s, 0, word_len);
	if (str_arr[j] == NULL)
	{
		while (j > 0)
		{
			free(str_arr[j - 1]);
			j--;
		}
		free(str_arr);
		return (-1);
	}
	j++;
	word_len = 0;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_len;
	size_t	i;
	int		j;
	char	**str_arr;

	i = 0;
	j = 0;
	str_arr = allocate_string_array(s, c);
	if (str_arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		word_len = get_word_len(s + i, c);
		i += word_len;
		if (word_len != 0)
		{
			j = allocate_string(str_arr, &s[i - word_len], word_len, j);
			if (j == -1)
				return (NULL);
		}
	}
	str_arr[j] = NULL;
	return (str_arr);
}
