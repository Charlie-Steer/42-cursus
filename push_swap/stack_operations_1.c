/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:29:06 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/21 17:26:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//? What to do if operation cannot be performed?
// ! User warning: remember to set the start of the list to returned value.
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

// ! User warning: remember to set the start of the list to returned value.
t_list_tuple	push_node(t_node *from, t_node *to)
{
	t_list_tuple new_lists;
	t_node *from_new_start = from->next_node;
	if (!from)
	{
		new_lists.from = from;
		new_lists.to = to;
		return (new_lists);
	}

	from->next_node = to;

	new_lists.from = from_new_start;
	new_lists.to = from;

	return (new_lists);
}

// First becomes last.
t_node	*rotate_stack(t_node* stack)
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
t_node	*inverse_rotate_stack(t_node* stack)
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