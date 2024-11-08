/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:49:37 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/08 10:36:32 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_tuple	*push_nodes_to_b(
	t_node *stack_a, t_node *stack_b, int a_len, int *largest_numbers)
{
	t_node			*temp_node;
	t_stack_tuple	*stacks;
	int				i;

	i = 0;
	while (i < a_len)
	{
		if ((stack_a->number == largest_numbers[0])
			|| (stack_a->number == largest_numbers[1])
			|| (stack_a->number == largest_numbers[2]))
			stack_a = ra(stack_a);
		else
		{
			stacks = pb(stack_b, stack_a);
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
			free(stacks);
		}
		i++;
	}
	stacks = malloc(sizeof(t_stack_tuple));
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	return (stacks);
}

t_node	*order_stack_a(t_node *stack_a)
{
	t_stack_tuple	*stacks;
	t_node			*stack_a_start;
	int				largest_number;

	stack_a_start = stack_a;
	largest_number = stack_a->number;
	if (stack_a->next_node->number > largest_number)
		largest_number = stack_a->next_node->number;
	if (stack_a->next_node->next_node->number > largest_number)
		largest_number = stack_a->next_node->next_node->number;
	if (stack_a->number == largest_number)
		stack_a = ra(stack_a);
	else if (stack_a->next_node->number == largest_number)
		stack_a = rra(stack_a);
	if (stack_a->number > stack_a->next_node->number)
		stack_a = sa(stack_a);
	return (stack_a);
}

t_stack_tuple	*handle_one_and_two_len_cases(t_stack_tuple *stacks, int a_len)
{
	if (a_len == 1)
	{
		stacks->return_code = 0;
		return (stacks);
	}
	else if (a_len == 2)
	{
		if (stacks->stack_a->number > stacks->stack_a->next_node->number)
		{
			stacks->stack_a = sa(stacks->stack_a);
			stacks->return_code = 0;
		}
		return (stacks);
	}
	else
	{
		ft_printf("This shouldn't be happening.");
		return (NULL);
	}
}

t_stack_tuple	*split_stacks(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple	*stacks;
	int				*largest_numbers;
	int				a_len;

	stacks = malloc(sizeof(t_stack_tuple));
	if (!stacks)
		return (NULL);
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	a_len = get_list_len(stack_a);
	if (a_len == 1 || a_len == 2)
		return (stacks = handle_one_and_two_len_cases(stacks, a_len));
	largest_numbers = malloc(3 * sizeof(int));
	init_and_order_largest_numbers(stack_a, largest_numbers, a_len);
	if (a_len > 3)
	{
		free(stacks);
		set_actual_largest_numbers(stack_a, a_len, largest_numbers);
		stacks = push_nodes_to_b(stack_a, stack_b, a_len, largest_numbers);
		stack_a = stacks->stack_a;
	}
	stacks->stack_a = order_stack_a(stack_a);
	stacks->return_code = 1;
	free(largest_numbers);
	return (stacks);
}
