/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:09:04 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/08 10:09:20 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*rra(t_node *stack_a)
{
	stack_a = reverse_rotate_stack(stack_a);
	ft_printf("rra\n");
	return (stack_a);
}

t_node	*rrb(t_node *stack_b)
{
	stack_b = reverse_rotate_stack(stack_b);
	ft_printf("rrb\n");
	return (stack_b);
}

t_stack_tuple	*rrr(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple	*stacks;

	stacks = malloc(sizeof(t_stack_tuple));
	stacks->stack_a = reverse_rotate_stack(stack_a);
	stacks->stack_b = reverse_rotate_stack(stack_b);
	ft_printf("rrr\n");
	return (stacks);
}
