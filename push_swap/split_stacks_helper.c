/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stacks_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:00:44 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/09 15:12:21 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_largest_numbers_array(t_node *stack_a, int *largest_numbers)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		largest_numbers[i] = stack_a->number;
		stack_a = stack_a->next_node;
		i++;
	}
	return (largest_numbers);
}

int	*order_largest_numbers_array(int *largest_numbers)
{
	int	temp_number;
	int	i;

	i = 0;
	while (!(largest_numbers[0] < largest_numbers[1])
		|| !(largest_numbers[1] < largest_numbers[2])
		|| !(largest_numbers[0] < largest_numbers[2]))
	{
		if (largest_numbers[1] > largest_numbers[2])
		{
			temp_number = largest_numbers[2];
			largest_numbers[2] = largest_numbers[1];
			largest_numbers[1] = temp_number;
		}
		if (largest_numbers[0] > largest_numbers[1])
		{
			temp_number = largest_numbers[1];
			largest_numbers[1] = largest_numbers[0];
			largest_numbers[0] = temp_number;
		}
	}
	return (largest_numbers);
}

// returns 0 if ordered, 1 if unordered.
int	init_and_order_largest_numbers(
	t_node *stack_a, int *largest_numbers, int a_len)
{
	init_largest_numbers_array(stack_a, largest_numbers);
	order_largest_numbers_array(largest_numbers);
	if (a_len == 3)
		return (1);
	return (0);
}

void	set_actual_largest_numbers(
	t_node *stack_a, int a_len, int *largest_numbers)
{
	int	i;

	i = 3;
	stack_a = stack_a->next_node->next_node->next_node;
	while (i < a_len)
	{
		if (stack_a->number > largest_numbers[2])
		{
			largest_numbers[0] = largest_numbers[1];
			largest_numbers[1] = largest_numbers[2];
			largest_numbers[2] = stack_a->number;
		}
		else if (stack_a->number > largest_numbers[1])
		{
			largest_numbers[0] = largest_numbers[1];
			largest_numbers[1] = stack_a->number;
		}
		else if (stack_a->number > largest_numbers[0])
			largest_numbers[0] = stack_a->number;
		stack_a = stack_a->next_node;
		i++;
	}
}
