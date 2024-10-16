/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:29:06 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/16 18:11:20 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//? What to do if operation cannot be performed?
void	swap_nodes(t_node *stack)
{
	t_node	*last;
	t_node	*second_last;
	t_node	*third_last;

	if (!stack || !stack->next_node)
		return ;

	last = stack;
	second_last = NULL;
	third_last = NULL;
	while (last->next_node)
	{
		third_last = second_last;
		second_last = last;
		last = last->next_node;
	}

	if (third_last)
		third_last->next_node = last;
	last->next_node = second_last;
	second_last->next_node = NULL;
}

void	push_node(t_node *from, t_node *to)
{
	t_node *from_last;
	t_node *from_second_last;
	t_node *to_last;

	if (!from)
		return ;

	from_last = from;
	from_second_last = NULL;
	to_last = to;
	while(from_last->next_node)
	{
		from_second_last = from_last;
		from_last = from_last->next_node;
	}
	while(to_last->next_node)
		to_last = to_last->next_node;

	to_last->next_node = from_last;

	if (from_second_last)
		from_second_last->next_node = NULL;
}

t_node	*rotate_stack(t_node* stack)
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

t_node	*inverse_rotate_stack(t_node* stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack)
		return (NULL);

	first = stack;
	second = NULL;
	last = stack;

	if (first->next_node)
		second = first->next_node;

	while (last->next_node)
		last = last->next_node;

	last->next_node = first;
	first->next_node = NULL;

	stack = second;

	return (stack);
}