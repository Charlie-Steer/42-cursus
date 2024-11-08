/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:34:54 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/08 10:31:29 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_surface_cost(enum e_stack cost_stack, t_node *node, int stack_len)
{
	if (node->position <= stack_len / 2)
	{
		if (cost_stack == A)
		{
			node->a_surface_cost = node->position;
		}
		else if (cost_stack == B)
		{
			node->b_surface_cost = node->position;
		}
	}
	else
	{
		if (cost_stack == A)
		{
			node->a_surface_cost = node->position - stack_len;
		}
		else if (cost_stack == B)
		{
			node->b_surface_cost = node->position - stack_len;
		}
	}
}

void	set_cost_b(t_node *stack_b, int b_len)
{
	int	i;

	i = 0;
	while (i < b_len)
	{
		set_surface_cost(B, stack_b, b_len);
		stack_b = stack_b->next_node;
		i++;
	}
}

void	set_cost_a(t_node *stack_a, t_node *stack_b, int a_len, int b_len)
{
	t_node	*stack_a_start;
	t_node	*stack_b_start;
	int		i;

	stack_a_start = stack_a;
	stack_b_start = stack_b;
	i = 0;
	while (i < a_len)
	{
		set_surface_cost(A, stack_a, a_len);
		stack_a = stack_a->next_node;
		i++;
	}
	stack_a = stack_a_start;
	stack_b = stack_b_start;
	i = 0;
	while (i < b_len)
	{
		while (stack_a->position != stack_b->target_position)
			stack_a = stack_a->next_node;
		stack_b->a_surface_cost = stack_a->a_surface_cost;
		stack_a = stack_a_start;
		stack_b = stack_b->next_node;
		i++;
	}
}

void	set_surface_costs(t_node *stack_a, t_node *stack_b)
{
	t_node	*stack_a_start;
	t_node	*stack_b_start;
	int		a_len;
	int		b_len;

	stack_a_start = stack_a;
	stack_b_start = stack_b;
	a_len = get_list_len(stack_a);
	b_len = get_list_len(stack_b);
	set_cost_b(stack_b, b_len);
	set_cost_a(stack_a, stack_b, a_len, b_len);
}

void	set_total_cost(t_node *stack_b)
{
	int	b_len;
	int	i;

	b_len = get_list_len(stack_b);
	i = 0;
	while (i < b_len)
	{
		stack_b->total_cost = ft_abs(stack_b->a_surface_cost)
			+ ft_abs(stack_b->b_surface_cost);
		stack_b = stack_b->next_node;
		i++;
	}
}
