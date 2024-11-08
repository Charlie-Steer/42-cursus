/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:09:47 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/08 10:18:46 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number_strings	free_number_strings(t_number_strings number_strings)
{
	int	i;

	i = 0;
	if (!number_strings.number_strings || !number_strings.is_heap_allocated)
		return (number_strings);
	while (number_strings.number_strings[i])
	{
		free(number_strings.number_strings[i]);
		i++;
	}
	free(number_strings.number_strings);
	number_strings.number_strings = NULL;
	return (number_strings);
}

void	free_stacks(t_stack_tuple *stacks)
{
	t_node	*next_node;

	if (!stacks)
		return ;
	while (stacks->stack_a)
	{
		next_node = stacks->stack_a->next_node;
		free(stacks->stack_a);
		stacks->stack_a = next_node;
	}
	while (stacks->stack_b)
	{
		next_node = stacks->stack_b->next_node;
		free(stacks->stack_b);
		stacks->stack_b = next_node;
	}
	free(stacks);
}

void	free_stacks_separately(t_node *stack_a, t_node *stack_b)
{
	t_node	*next_node;

	while (stack_a)
	{
		next_node = stack_a->next_node;
		free(stack_a);
		stack_a = next_node;
	}
	while (stack_b)
	{
		next_node = stack_b->next_node;
		free(stack_b);
		stack_b = next_node;
	}
}
