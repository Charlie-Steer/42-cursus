/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:32:49 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/09 12:36:33 by cargonz2         ###   ########.fr       */
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
