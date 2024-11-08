/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:40:05 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/08 10:39:52 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i > 0)
			num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

int	numlen(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 1;
	if (n < 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	get_list_len(t_node *list)
{
	int	len;

	if (!list)
		return (0);
	len = 1;
	while (list->next_node != NULL)
	{
		len++;
		list = list->next_node;
	}
	return (len);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
