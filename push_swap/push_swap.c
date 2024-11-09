/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/09 11:26:48 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_node *stack_a, t_node *stack_b, int a_len, int b_len)
{
	t_node	*a_start;
	int		min_a_above_b_number;
	int		i;
	int		j;

	a_start = stack_a;
	i = 0;
	while (i++ < b_len)
	{
		min_a_above_b_number = INT_MAX;
		j = 0;
		while (j++ < a_len)
		{
			if (stack_a->number > stack_b->number
				&& stack_a->number <= min_a_above_b_number)
				min_a_above_b_number = stack_a->number;
			stack_a = stack_a->next_node;
		}
		stack_a = a_start;
		while (stack_a->number != min_a_above_b_number)
			stack_a = stack_a->next_node;
		stack_b->target_position = stack_a->position;
		stack_a = a_start;
		stack_b = stack_b->next_node;
	}
}

t_node	*select_node(t_node *stack_b)
{
	t_node	*cheapest_node;
	int		b_len;
	int		i;

	cheapest_node = stack_b;
	b_len = get_list_len(stack_b);
	i = 0;
	while (i < b_len)
	{
		if (stack_b->total_cost < cheapest_node->total_cost)
		{
			cheapest_node = stack_b;
		}
		stack_b = stack_b -> next_node;
		i++;
	}
	return (cheapest_node);
}

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

t_stack_tuple	*run_core_algorithm(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple	*stacks;
	t_stack_tuple	*return_stacks;
	t_node			*node_to_move;

	return_stacks = malloc(sizeof(t_stack_tuple));
	while (stack_b)
	{
		set_position(stack_a);
		set_position(stack_b);
		set_target(stack_a, stack_b, get_list_len(stack_a),
			get_list_len(stack_b));
		set_surface_costs(stack_a, stack_b);
		set_total_cost(stack_b);
		node_to_move = select_node(stack_b);
		stacks = surface_nodes_and_push_a(stack_a, stack_b, node_to_move);
		stack_a = stacks->stack_a;
		stack_b = stacks->stack_b;
		free(stacks);
	}
	return_stacks->stack_a = stack_a;
	return_stacks->stack_b = stack_b;
	return (return_stacks);
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

#include <assert.h> //! DELETE!
t_stack_tuple	*push_smaller_half_to_b(t_node *stack_a, t_node *stack_b)
{
	t_node			*stack_a_start;
	int				a_len;
	int				a_half_len;
	t_stack_tuple	*stacks;
	t_node			*halfway_node;

	stack_a_start = stack_a;
	a_len = get_list_len(stack_a);
	int a_third_len = a_len / 3;

	while (stack_a && stack_a->ordered_position != a_third_len)
	{
		stack_a = stack_a->next_node;
	}
	t_node *thirdway_node = stack_a;
	stack_a = stack_a_start;

	int i = 0;
	while (stack_a && i <= thirdway_node->ordered_position)
	{
		if (stack_a->number <= thirdway_node->number)
		{
			i++;
			stacks = pb(stack_b, stack_a);
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
			free(stacks);
		}
		else
		{
			stack_a = ra(stack_a);
		}
	}
	// print_stacks("After Thirds", stack_a, stack_b);


	stack_a_start = stack_a;
	// a_len = get_list_len(stack_a);
	a_half_len = a_len / 2;
	// ft_printf("%d, %d\n", a_len, a_half_len);
	while (stack_a && stack_a->ordered_position != a_half_len)
	{
		stack_a = stack_a->next_node;
	}
	halfway_node = stack_a;
	// ft_printf("halfway_node: %d", halfway_node->number);
	stack_a = stack_a_start;
	// print_stacks("Pre-halves", stack_a, stack_b);

	// ft_printf("i: %d\n", i);
	// assert(0);
	while (stack_a && i <= halfway_node->ordered_position) //! IF SINGLE SPLIT CHANGE TO a_len
	{
		if (stack_a->number <= halfway_node->number)
		{
			i++;
			stacks = pb(stack_b, stack_a);
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
			free(stacks);
		}
		else
		{
			stack_a = ra(stack_a);
		}
	}
	// print_stacks("After Halved", stack_a, stack_b);
	stacks = ft_calloc(1, sizeof(t_stack_tuple));
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	return (stacks);
}

int	main(int argc, char *argv[])
{
	t_node				*stack_a;
	t_node				*stack_b;
	t_stack_tuple		*stacks;

	stack_a = create_number_strings_and_stack_a(argc, argv);
	if (!stack_a)
		return (1);
	// ft_printf("here?\n");
	if (check_if_ordered(stack_a))
		return (free_stacks_separately(stack_a, NULL), 0);
	// print_stacks("HEALTH CHECK", stack_a, NULL);
	// ft_printf("MESSAGE\n");
	set_ordered_position(stack_a, get_list_len(stack_a));

	stack_b = NULL;
	if (get_list_len(stack_a) > 10)
	{
		stacks = push_smaller_half_to_b(stack_a, stack_b);
		stack_a = stacks->stack_a;
		stack_b = stacks->stack_b;
		free (stacks);
	}

	// ft_printf("%p\n", stack_b);
	// print_stacks("After Premoves", stack_a, stack_b);

	// stack_b = NULL;
	stacks = split_stacks(stack_a, stack_b);
	if (stacks->return_code == 0)
		return (free_stacks(stacks), 0);
	// ft_printf("hello!\n");
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	free(stacks);
	stacks = run_core_algorithm(stack_a, stack_b);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	stack_a = rotate_until_ordered(stack_a);
	// print_stacks("END", stack_a, stack_b);
	free_stacks_separately(stack_a, stack_b);
	free(stacks);
	return (0);
}
