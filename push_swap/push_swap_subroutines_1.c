/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_subroutines_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:43:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 15:22:58 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_list_of_integers_from_strings(char **number_strings)
{
	t_node	*new_node;
	t_node	*previous_node;
	t_node	*first_node;
	int		i;
	int		number;

	previous_node = NULL;
	i = 0;
	while (number_strings[i])
	{
		number = ft_atoi(number_strings[i]);
		new_node = create_node(number);
		if (!new_node)
			return (NULL);
		if (!previous_node)
			first_node = new_node;
		else
			add_last_link(previous_node, new_node);
		previous_node = new_node;
		i++;
	}
	return (first_node);
}

t_node	*set_ordered_position(t_node *list, int number_of_integers)
{
	t_node	*node_to_sort;
	t_node	*node_to_compare_to;
	int		i;
	int		j;

	node_to_sort = list;
	i = 0;
	while (i++ < number_of_integers)
	{
		j = 0;
		node_to_compare_to = list;
		while (j++ < number_of_integers)
		{
			if (node_to_sort == node_to_compare_to)
			{
				node_to_compare_to = node_to_compare_to->next_node;
				continue ;
			}
			if (node_to_sort->number > node_to_compare_to->number)
				node_to_sort->ordered_position++;
			node_to_compare_to = node_to_compare_to->next_node;
		}
		node_to_sort = node_to_sort->next_node;
	}
	return (list);
}

t_number_strings	create_number_strings(int argc, char *argv[])
{
	t_number_strings	number_strings;

	ft_memset(&number_strings, 0, sizeof(number_strings));
	if (argc == 1)
		return (number_strings);
	else if (argv[1] == NULL || argv[1][0] == '\0')
		return (write(2, "Error\n", 6), number_strings);
	if (argc == 2)
	{
		number_strings.number_strings = ft_split(argv[1], ' ');
		number_strings.is_heap_allocated = 1;
	}
	else
		number_strings.number_strings = &argv[1];
	if (!check_if_numbers(number_strings.number_strings)
		|| check_if_int_overflow(number_strings.number_strings))
	{
		number_strings = free_number_strings(number_strings);
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		return (number_strings);
}

t_node	*create_stack_a(t_number_strings number_strings)
{
	t_node	*list;

	list = create_list_of_integers_from_strings(number_strings.number_strings);
	if (number_strings.is_heap_allocated)
	{
		free_number_strings(number_strings);
	}
	if (!list)
		return (write(2, "Error\n", 6), NULL);
	if (check_if_duplicate_numbers(list))
	{
		free_stacks_separately(list, NULL);
		return (write(2, "Error\n", 6), NULL);
	}
	else
		return (list);
}

void	set_position(t_node *stack)
{
	int	len;
	int	i;

	len = get_list_len(stack);
	i = 0;
	while (i < len)
	{
		stack->position = i;
		stack = stack->next_node;
		i++;
	}
}
