/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/07 16:38:06 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_node *stack_a, t_node *stack_b, int a_len, int b_len)
{
	t_node	*a_start;
	int		min_a_above_b_number;
	int		i;
	int		j;

	a_start = stack_a;
	i = 0;
	while (i++ < b_len)
	{
		min_a_above_b_number = INT_MAX;
		j = 0;
		while (j++ < a_len)
		{
			if (stack_a->number > stack_b->number
				&& stack_a->number <= min_a_above_b_number)
				min_a_above_b_number = stack_a->number;
			stack_a = stack_a->next_node;
		}
		stack_a = a_start;
		while (stack_a->number != min_a_above_b_number)
			stack_a = stack_a->next_node;
		stack_b->target_position = stack_a->position;
		stack_a = a_start;
		stack_b = stack_b->next_node;
	}
}

t_node	*select_node(t_node *stack_b)
{
	t_node	*cheapest_node;
	int		b_len;
	int		i;

	cheapest_node = stack_b;
	b_len = get_list_len(stack_b);
	i = 0;
	while (i < b_len)
	{
		if (stack_b->total_cost < cheapest_node->total_cost)
		{
			cheapest_node = stack_b;
		}
		stack_b = stack_b -> next_node;
		i++;
	}
	return (cheapest_node);
}

t_node	*rotate_until_ordered(t_node *stack_a)
{
	t_node	*stack_a_start;
	t_node	*stack_a_end;
	int		i;
	int		a_len;

	i = 0;
	a_len = get_list_len(stack_a);
	stack_a_start = stack_a;
	stack_a_end = stack_a;
	while (i++ < a_len - 1)
		stack_a_end = stack_a_end->next_node;
	i = 0;
	while (stack_a_end->number <= stack_a_start->number)
	{
		stack_a = rra(stack_a);
		stack_a_end = stack_a;
		while (i++ < a_len - 1)
			stack_a_end = stack_a_end->next_node;
		i = 0;
	}
	return (stack_a);
}

t_stack_tuple	*run_core_algorithm(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple	*stacks;
	t_stack_tuple	*return_stacks;
	t_node			*node_to_move;

	return_stacks = malloc(sizeof(t_stack_tuple));
	while (stack_b)
	{
		set_position(stack_a);
		set_position(stack_b);
		set_target(stack_a, stack_b, get_list_len(stack_a),
			get_list_len(stack_b));
		set_surface_costs(stack_a, stack_b);
		set_total_cost(stack_b);
		node_to_move = select_node(stack_b);
		stacks = surface_nodes_and_push_a(stack_a, stack_b, node_to_move);
		stack_a = stacks->stack_a;
		stack_b = stacks->stack_b;
		free(stacks);
	}
	return_stacks->stack_a = stack_a;
	return_stacks->stack_b = stack_b;
	return (return_stacks);
}

int	main(int argc, char *argv[])
{
	t_number_strings	number_strings;
	t_node				*stack_a;
	t_node				*stack_b;
	t_stack_tuple		*stacks;

	if (!((number_strings = create_number_strings(argc, argv)).number_strings))
		return (1);
	if (!(stack_a = create_stack_a(number_strings)))
		return (1);

	if (check_if_ordered(stack_a))
		return (free_stacks_separately(stack_a, NULL), 0);

	set_ordered_position(stack_a, get_list_len(stack_a));

	stack_b = NULL;
	stacks = split_stacks(stack_a, stack_b);
	if (stacks->return_code == 0)
		return (free_stacks(stacks), 0);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	free(stacks);

	stacks = run_core_algorithm(stack_a, stack_b);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;

	stack_a = rotate_until_ordered(stack_a);
	free_stacks_separately(stack_a, stack_b);
	free(stacks);
	return (0);
}
