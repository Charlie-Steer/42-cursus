/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:16:29 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 13:03:42 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>
#include <unistd.h>

#define INITIAL_INSTRUCTION_NUMBER 100000

t_node	*create_number_strings_and_stack_a(int argc, char *argv[]);
t_number_strings	create_number_strings(int argc, char *argv[]);
t_node	*create_stack_a(t_number_strings number_strings);
t_node	*create_list_of_integers_from_strings(char **number_strings);

int check_if_valid_instructions(int *instructions);
void	record_instruction(char *line, int *instructions, int index);
void	run_instruction(int *instructions, int i, t_node **stack_a, t_node **stack_b);
void	handle_one_number(int *instructions);

int	*read_input_and_record_instructions()
{
	char	*line;
	int		instruction_index;
	int		*instructions;
	int		instruction_array_size;

	instruction_array_size = INITIAL_INSTRUCTION_NUMBER;
	instructions = ft_calloc(instruction_array_size, sizeof(int));
	instruction_index = 0;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ; //? RETURN? //! POTENTIAL ERROR
		record_instruction(line, instructions, instruction_index);
		free(line);
		if (++instruction_index > instruction_array_size)
		{
			instruction_array_size *= 2;
			int *new_instructions = ft_calloc(instruction_array_size, sizeof(int));
			memcpy(new_instructions, instructions, instruction_array_size / 2);
			free(instructions);
			instructions = new_instructions;
		}
	}
	return (instructions);
}

int main(int argc, char *argv[])
{
	//! CHECK FOR LEAKS
	//! ENSURE EVERYTHING IN THE PDF IS HANDLED THE SAME.
	//! TEST EVERYTHING WITH BOTH "" AND UNCAPPED ARGUMENTS.
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_number_strings_and_stack_a(argc, argv);
	if (!stack_a)
		return (1);
	int *instructions = read_input_and_record_instructions();
	if (!check_if_valid_instructions(instructions))
		return (free_everything(instructions, stack_a, stack_b),
			write(1, "ERROR\n", 6), 1);
	int number_of_numbers = get_list_len(stack_a);
	if (number_of_numbers == 1)
		handle_one_number(instructions);
	i = 0;
	while (instructions[i] != 0)
		run_instruction(instructions, i++, &stack_a, &stack_b);
	if (check_if_ordered(stack_a) && number_of_numbers == get_list_len(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_everything(instructions, stack_a, stack_b);
	return (0);
}

void	handle_one_number(int *instructions)
{
	int	i;
	int push_a_balance;
	int push_b_balance;

	push_a_balance = 0;
	push_b_balance = 1;
	i = 0;
	while (instructions[i++] != 0)
	{
		if (push_a_balance == 1 && instructions[i] == PA)
		{
			push_a_balance = 0;
			push_b_balance = 1;
		}
		else if (push_b_balance == 1 && instructions[i] == PB)
		{
			push_b_balance = 0;
			push_a_balance = 1;
		}
	}
	if (push_a_balance == 0 && push_b_balance == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
}

void	run_instruction(int *instructions, int i, t_node **stack_a, t_node **stack_b)
{
	if (instructions[i] == SA)
		sa(stack_a);
	else if (instructions[i] == SB)
		sb(stack_b);
	else if (instructions[i] == SS)
		ss(stack_a, stack_b);
	else if (instructions[i] == PA)
		pa(stack_a, stack_b);
	else if (instructions[i] == PB)
		pb(stack_b, stack_a);
	else if (instructions[i] == RA)
		ra(stack_a);
	else if (instructions[i] == RB)
		rb(stack_b);
	else if (instructions[i] == RR)
		rr(stack_a, stack_b);
	else if (instructions[i] == RRA)
		rra(stack_a);
	else if (instructions[i] == RRB)
		rrb(stack_b);
	else if (instructions[i] == RRR)
		rrr(stack_a, stack_b);
	else
	 	ft_printf("BAD INSTRUCTION\n");
}

void	record_instruction(char *line, int *instructions, int index)
{
		if (ft_strncmp(line, "sa\n", 4) == 0)
			instructions[index] = SA;
		else if (ft_strncmp(line, "sb\n", 3) == 0)
			instructions[index] = SB;
		else if (ft_strncmp(line, "ss\n", 3) == 0)
			instructions[index] = SS;
		else if (ft_strncmp(line, "pa\n", 3) == 0)
			instructions[index] = PA;
		else if (ft_strncmp(line, "pb\n", 3) == 0)
			instructions[index] = PB;
		else if (ft_strncmp(line, "ra\n", 3) == 0)
			instructions[index] = RA;
		else if (ft_strncmp(line, "rb\n", 3) == 0)
			instructions[index] = RB;
		else if (ft_strncmp(line, "rr\n", 3) == 0)
			instructions[index] = RR;
		else if (ft_strncmp(line, "rra\n", 4) == 0)
			instructions[index] = RRA;
		else if (ft_strncmp(line, "rrb\n", 4) == 0)
			instructions[index] = RRB;
		else if (ft_strncmp(line, "rrr\n", 4) == 0)
			instructions[index] = RRR;
		else
		 	instructions[index] = -1;
}

int check_if_valid_instructions(int *instructions)
{
	int	i;

	i = 0;
	while (instructions[i] != 0)
	{
		if (instructions[i] == -1)
		{
			write(STDERR_FILENO, "Error\n", 6);
			free(instructions);
			exit(1);
		}
		i++;
	}
	return (1);
}

t_node	*create_number_strings_and_stack_a(int argc, char *argv[])
{
	t_number_strings	number_strings;
	t_node				*stack_a;

	stack_a = NULL;
	number_strings = create_number_strings(argc, argv);
	if (!number_strings.number_strings)
		return (NULL);
	// for (int i = 0; i < 11; i++)
	// 	printf("%s\n", number_strings.number_strings[i]);
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
		// ft_printf("wut?\n");
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
	// free_stacks_separately(list, NULL); //! TEST
	// printf("before\n");
	// exit(0); //! TEST
	// printf("after\n");

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
