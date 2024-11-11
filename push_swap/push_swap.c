/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 15:07:14 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*rotate_until_ordered(t_node *stack_a)
{
	t_node	*stack_a_start;
	t_node	*stack_a_end;
	int		i;
	int		a_len;

	i = 0;
	a_len = get_list_len(stack_a);
	stack_a_start = stack_a;
	stack_a_end = stack_a;
	while (i++ < a_len - 1)
		stack_a_end = stack_a_end->next_node;
	i = 0;
	while (stack_a_end->number <= stack_a_start->number)
	{
		stack_a = rra(stack_a);
		stack_a_end = stack_a;
		while (i++ < a_len - 1)
			stack_a_end = stack_a_end->next_node;
		i = 0;
	}
	return (stack_a);
}

t_node	*create_number_strings_and_stack_a(int argc, char *argv[])
{
	t_number_strings	number_strings;
	t_node				*stack_a;

	stack_a = NULL;
	number_strings = create_number_strings(argc, argv);
	if (!number_strings.number_strings)
		return (NULL);
	stack_a = create_stack_a(number_strings);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

t_node	*get_halfway_node(t_node *stack_a)
{
	t_node	*stack_a_start;
	int		a_half_len;

	stack_a_start = stack_a;
	a_half_len = get_list_len(stack_a) / 2;
	while (stack_a && stack_a->ordered_position != a_half_len)
		stack_a = stack_a->next_node;
	return (stack_a);
}

void	push_smaller_half_to_b(t_node **stack_a, t_node **stack_b)
{
	t_stack_tuple	*stacks;
	t_node			*halfway_node;
	int				i;

	if (get_list_len(*stack_a) > 7)
	{
		halfway_node = get_halfway_node(*stack_a);
		i = halfway_node->ordered_position;
		while (*stack_a && i)
		{
			if ((*stack_a)->number <= halfway_node->number)
			{
				i--;
				stacks = pb(*stack_b, *stack_a);
				*stack_a = stacks->stack_a;
				*stack_b = stacks->stack_b;
				free(stacks);
			}
			else
				*stack_a = ra(*stack_a);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_node				*stack_a;
	t_node				*stack_b;
	t_stack_tuple		*stacks;

	stack_a = create_number_strings_and_stack_a(argc, argv);
	if (!stack_a)
		return (1);
	if (check_if_ordered(stack_a))
		return (free_stacks_separately(stack_a, NULL), 0);
	set_ordered_position(stack_a, get_list_len(stack_a));
	stack_b = NULL;
	push_smaller_half_to_b(&stack_a, &stack_b);
	stacks = split_stacks(stack_a, stack_b);
	if (stacks->return_code == 0)
		return (free_stacks(stacks), 0);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	free(stacks);
	stacks = run_core_algorithm(stack_a, stack_b);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	stack_a = rotate_until_ordered(stack_a);
	free_stacks_separately(stack_a, stack_b);
	free(stacks);
	return (0);
}
