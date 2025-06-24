/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:28:25 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:31:23 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdbool.h"
#include "stdlib.h"

void	zero_block(void *block, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)block)[i] = '\0';
		i++;
	}
}

int	str_to_int(char *str)
{
	int		num;
	int		i;
	bool	is_negative;

	num = 0;
	i = 0;
	is_negative = false;
	if (str[0] == '-')
	{
		is_negative = true;
		i += 1;
	}
	else if (str[0] == '+')
		i += 1;
	while (str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (is_negative)
		num = -num;
	return (num);
}

void	*allocate(int bytes)
{
	void	*block;

	block = malloc(bytes);
	zero_block(block, bytes);
	return (block);
}
