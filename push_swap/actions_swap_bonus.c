/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:21:02 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 13:42:03 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_node **stack_a)
{
	*stack_a = swap_nodes(*stack_a);
}

void	sb(t_node **stack_b)
{
	*stack_b = swap_nodes(*stack_b);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	*stack_a = swap_nodes(*stack_a);
	*stack_b = swap_nodes(*stack_b);
}
