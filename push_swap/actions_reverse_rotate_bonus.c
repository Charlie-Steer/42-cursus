/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_reverse_rotate_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:29:33 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/10 14:31:29 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_node **stack_a)
{
	*stack_a = reverse_rotate_stack(*stack_a);
	// ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	*stack_b = reverse_rotate_stack(*stack_b);
	// ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	*stack_a = reverse_rotate_stack(*stack_a);
	*stack_b = reverse_rotate_stack(*stack_b);
	// ft_printf("rrr\n");
}
