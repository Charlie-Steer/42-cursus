/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:16:29 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 15:53:13 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>
#include <unistd.h>

t_node				*create_number_strings_and_stack_a(int argc, char *argv[]);
t_number_strings	create_number_strings(int argc, char *argv[]);
t_node				*create_stack_a(t_number_strings number_strings);
t_node				*create_list_of_integers_from_strings(
						char **number_strings);

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*instructions;
	int		number_of_numbers;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_number_strings_and_stack_a(argc, argv);
	if (!stack_a)
		return (1);
	instructions = read_input_and_record_instructions(NULL);
	if (!check_if_valid_instructions(instructions))
		return (free_everything(instructions, stack_a, stack_b), 1);
	number_of_numbers = get_list_len(stack_a);
	if (number_of_numbers == 1)
	{
		handle_one_number(instructions);
		free_everything(instructions, stack_a, stack_b);
		return (0);
	}
	run_instructions(instructions, &stack_a, &stack_b);
	print_ok_or_ko(check_if_ordered(stack_a)
		&& number_of_numbers == get_list_len(stack_a));
	free_everything(instructions, stack_a, stack_b);
	return (0);
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
		free_everything(NULL, list, NULL);
		return (write(2, "Error\n", 6), NULL);
	}
	else
		return (list);
}

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
