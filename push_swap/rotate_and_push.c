/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:25:08 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/09 15:13:14 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks_and_costs	dual_action(t_stacks_and_costs stacks_and_costs)
{
	t_stack_tuple		*stacks;

	if (stacks_and_costs.a_cost > 0 && stacks_and_costs.b_cost > 0)
	{
		stacks = rr(stacks_and_costs.stack_a, stacks_and_costs.stack_b);
		stacks_and_costs.stack_a = stacks->stack_a;
		stacks_and_costs.stack_b = stacks->stack_b;
		stacks_and_costs.a_cost -= 1;
		stacks_and_costs.b_cost -= 1;
	}
	else if (stacks_and_costs.a_cost < 0 && stacks_and_costs.b_cost < 0)
	{
		stacks = rrr(stacks_and_costs.stack_a, stacks_and_costs.stack_b);
		stacks_and_costs.stack_a = stacks->stack_a;
		stacks_and_costs.stack_b = stacks->stack_b;
		stacks_and_costs.a_cost += 1;
		stacks_and_costs.b_cost += 1;
	}
	return (stacks_and_costs);
}

t_stacks_and_costs	single_action(t_stacks_and_costs stacks_and_costs)
{
	if (stacks_and_costs.a_cost > 0)
	{
		stacks_and_costs.stack_a = ra(stacks_and_costs.stack_a);
		stacks_and_costs.a_cost -= 1;
	}
	else if (stacks_and_costs.a_cost < 0)
	{
		stacks_and_costs.stack_a = rra(stacks_and_costs.stack_a);
		stacks_and_costs.a_cost += 1;
	}
	else if (stacks_and_costs.b_cost > 0)
	{
		stacks_and_costs.stack_b = rb(stacks_and_costs.stack_b);
		stacks_and_costs.b_cost -= 1;
	}
	else if (stacks_and_costs.b_cost < 0)
	{
		stacks_and_costs.stack_b = rrb(stacks_and_costs.stack_b);
		stacks_and_costs.b_cost += 1;
	}
	else
		ft_printf("This shouldn't be happening.\n");
	return (stacks_and_costs);
}

t_stack_tuple	*surface_nodes_and_push_a(
	t_node *stack_a, t_node *stack_b, t_node *node_to_move)
{
	t_stack_tuple		*stacks;
	t_stacks_and_costs	stacks_and_costs;

	stacks_and_costs.stack_a = stack_a;
	stacks_and_costs.stack_b = stack_b;
	stacks_and_costs.a_cost = node_to_move->a_surface_cost;
	stacks_and_costs.b_cost = node_to_move->b_surface_cost;
	while (stacks_and_costs.a_cost || stacks_and_costs.b_cost)
	{
		if ((stacks_and_costs.a_cost > 0 && stacks_and_costs.b_cost > 0)
			|| (stacks_and_costs.a_cost < 0 && stacks_and_costs.b_cost < 0))
			stacks_and_costs = dual_action(stacks_and_costs);
		else
			stacks_and_costs = single_action(stacks_and_costs);
	}
	stacks = pa(stacks_and_costs.stack_a, stacks_and_costs.stack_b);
	return (stacks);
}
