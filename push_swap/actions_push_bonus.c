/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_push_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:10:25 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/10 20:07:38 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void pa(t_node **stack_a, t_node **stack_b)
{
	t_stack_tuple	*stacks;

	stacks = push_node(*stack_a, *stack_b);
	*stack_a = stacks->stack_a;
	*stack_b = stacks->stack_b;
	free(stacks);
	// ft_printf("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	t_stack_tuple	*stacks;

	stacks = push_node(*stack_b, *stack_a);
	*stack_a = stacks->stack_b;
	*stack_b = stacks->stack_a;
	free(stacks);
}
