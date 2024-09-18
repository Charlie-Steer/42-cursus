/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:33:33 by cargonz2          #+#    #+#             */
/*   Updated: 2024/01/01 23:21:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;

	if (s == NULL)
		return (NULL);
	else if (ft_strlen(s) < start)
		return (ft_strdup(""));
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	t = malloc(sizeof(char) * (len + 1));
	if (t == NULL)
		return (NULL);
	ft_strlcpy(t, &s[start], len + 1);
	return (t);
}
