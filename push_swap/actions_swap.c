/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:11:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/04 16:37:25 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sa(t_node *stack_a)
{
	stack_a = swap_nodes(stack_a);
	ft_printf("sa\n");
	ft_printf("%p\n", (void *)stack_a);
	return (stack_a);
}

t_node	*sb(t_node *stack_b)
{
	stack_b = swap_nodes(stack_b);
	ft_printf("sb\n");
	return (stack_b);
}

t_stack_tuple	*ss(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple *stacks;

	stacks->stack_a = swap_nodes(stack_a);
	stacks->stack_b = swap_nodes(stack_b);
	ft_printf("ss\n");
	return (stacks);
}