/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:51:40 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/08 10:15:13 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_numbers(char **number_strings)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (number_strings[i])
	{
		c = number_strings[i][j];
		if (c == '-' || c == '+')
		{
			j++;
			c = number_strings[i][j];
			if (!c)
				return (0);
		}
		while (c && (c >= '0' && c <= '9'))
			c = number_strings[i][j++];
		if (c != '\0' && !(c >= '0' && c <= '9'))
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	check_if_int_overflow(char **number_strings)
{
	long	number;
	int		i;
	int		number_string_len;

	i = 0;
	while (number_strings[i])
	{
		number_string_len = ft_strlen(number_strings[i]);
		if (number_strings[i][0] == '-' && number_string_len > numlen(INT_MIN))
			return (1);
		else if (number_strings[i][0] != '-'
			&& number_string_len > numlen(INT_MAX))
			return (1);
		else
		{
			number = ft_atoi_long(number_strings[i]);
			if (number_strings[i][0] == '-' && number < (long)INT_MIN
			|| number_strings[i][0] != '-' && number > (long)INT_MAX)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_duplicate_numbers(t_node *list)
{
	t_node	*a;
	t_node	*b;

	a = list;
	b = list;
	while (a->next_node != NULL)
	{
		while (b->next_node != NULL)
		{
			if (a == b)
			{
				b = b->next_node;
				continue ;
			}
			if (a->number == b->number)
				return (1);
			b = b->next_node;
		}
		if (a->number == b->number)
			return (1);
		b = list;
		a = a->next_node;
	}
	return (0);
}

int	check_if_ordered(t_node *stack_a)
{
	while (stack_a->next_node)
	{
		if (stack_a->number < stack_a->next_node->number)
		{
			stack_a = stack_a->next_node;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}
