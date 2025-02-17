/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:49:54 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/10 19:27:39 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// Allocates a new node initialized to the "number" value.
// Memory must be handled by the user.
t_node	*create_node(int number)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (NULL);
	node->number = number;
	return (node);
}

// Returns 0 if input is valid, -1 if any input is NULL.
int	add_last_link(t_node *list_node, t_node *node_to_point_to)
{
	if (list_node == NULL || node_to_point_to == NULL)
		return (-1);
	if (list_node == NULL)
		list_node->next_node = node_to_point_to;
	else
	{
		while (list_node->next_node != NULL)
			list_node = list_node->next_node;
		list_node->next_node = node_to_point_to;
	}
	return (0);
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
