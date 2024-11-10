/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:25:06 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/10 14:27:38 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_node **stack_a)
{
	*stack_a = rotate_stack(*stack_a);
	// ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	*stack_b = rotate_stack(*stack_b);
	// ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	*stack_a = rotate_stack(*stack_a);
	*stack_b = rotate_stack(*stack_b);
	// ft_printf("rr\n");
}
