/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:04:51 by cargonz2          #+#    #+#             */
/*   Updated: 2024/01/01 23:18:24 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = NULL;
	new_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, s1, s1_len);
	ft_memmove(&new_str[s1_len], s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}
