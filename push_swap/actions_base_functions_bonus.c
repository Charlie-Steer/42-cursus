/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_base_functions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:08:31 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/10 14:57:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*swap_nodes(t_node *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->next_node)
		return (stack);
	first = stack;
	second = stack->next_node;
	first->next_node = second->next_node;
	second->next_node = first;
	return (second);
}

t_stack_tuple	*push_node(t_node *to, t_node *from)
{
	t_stack_tuple	*stacks;
	t_node			*from_new_start;

	stacks = ft_calloc(1, sizeof(t_stack_tuple));
	from_new_start = from->next_node;
	if (!from)
	{
		stacks->stack_a = to;
		stacks->stack_b = NULL;
		return (stacks);
	}
	else
	{
		stacks->stack_a = from;
		stacks->stack_a->next_node = to;
		stacks->stack_b = from_new_start;
		return (stacks);
	}
}

// First becomes last.
t_node	*rotate_stack(t_node *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack)
		return (NULL);
	first = stack;
	second = stack->next_node;
	last = stack;
	while (last->next_node)
	{
		last = last->next_node;
	}
	last->next_node = first;
	first->next_node = NULL;
	stack = second;
	return (stack);
}

// Last becomes first.
t_node	*reverse_rotate_stack(t_node *stack)
{
	t_node	*first;
	t_node	*second_last;
	t_node	*last;

	if (!stack)
		return (NULL);
	first = stack;
	second_last = NULL;
	last = stack;
	while (last->next_node)
	{
		second_last = last;
		last = last->next_node;
	}
	second_last->next_node = NULL;
	last->next_node = first;
	stack = last;
	return (stack);
}
