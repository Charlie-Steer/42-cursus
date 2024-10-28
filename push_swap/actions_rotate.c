/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:08:27 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/25 12:08:42 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *ra(t_node *stack_a)
{
	stack_a = rotate_stack(stack_a);
	ft_printf("ra\n");
	return (stack_a);
}

t_node *rb(t_node *stack_b)
{
	stack_b = rotate_stack(stack_b);
	ft_printf("rb\n");
	return (stack_b);
}

t_stack_tuple *rr(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple *stacks;

	stacks->stack_a = rotate_stack(stack_a);
	stacks->stack_b = rotate_stack(stack_b);
	ft_printf("rr\n");

	return (stacks);
}