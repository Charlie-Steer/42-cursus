/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:07:59 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/28 15:48:46 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_tuple	*pa(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple *stacks;

	stacks = push_node(stack_a, stack_b);
	ft_printf("pa\n");
	return (stacks);
}

t_stack_tuple	*pb(t_node *stack_b, t_node *stack_a)
{
	t_stack_tuple	*stacks;
	t_node *temp_stack;

	stacks = push_node(stack_b, stack_a);
	temp_stack = stacks->stack_a;
	stacks->stack_a = stacks->stack_b;
	stacks->stack_b = temp_stack;
	ft_printf("pb\n");
	return (stacks);
}