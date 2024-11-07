/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:18:34 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/07 12:46:31 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_number_strings(char **number_strings)
{
	int	i;

	i = 0;
	while (number_strings[i] != NULL)
	{
		ft_printf("%s\n", number_strings[i]);
		i++;
	}
}

void	print_stack_values(t_node *stack)
{
	int	list_len;
	int	i;

	list_len = get_list_len(stack);
	ft_printf("%11s   %2s   %2s   %2s   %2s   %2s   %2s\n", "number", "ord_pos", "pos", "tar_pos", "cost_a", "cost_b", "total_cost");
	i = 0;
	while (i < list_len)
	{
		ft_printf("%11d   %7d   %3d   %7d   %7d   %7d   %7d\n", stack->number, stack->ordered_position, stack->position, stack->target_position, stack->a_surface_cost, stack->b_surface_cost, stack->total_cost);
		if (stack->next_node)
			stack = stack->next_node;
		i++;
	}
}

void	print_stacks(char *title, t_node *stack_a, t_node *stack_b)
{
	ft_printf("\n%s\n", title);
	print_stack_values(stack_a);
	ft_printf("\n");
	print_stack_values(stack_b);
	ft_printf("\n");
	ft_printf("-----\n");
}