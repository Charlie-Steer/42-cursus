/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:16:29 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/10 19:49:45 by cargonz2         ###   ########.fr       */
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

//! CHECK FOR LEAKS
//! ENSURE EVERYTHING IN THE PDF IS HANDLED THE SAME.
int main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	stack_a = create_number_strings_and_stack_a(argc, argv);
	if (!stack_a)
		return (1);

	// print_stacks("START", stack_a, stack_b);

	//! MAKE RESIZEABLE ARRAYS.
	char *line;
	int instruction_array_size = INITIAL_INSTRUCTION_NUMBER;
	int *instructions = ft_calloc(instruction_array_size, sizeof(int));	//! MAKE RESIZEABLE ARRAYS.
	int i = 0;
	int instructions_recorded = 0;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ; //? RETURN?
		else
		{
			// printf("hello?\n");
		 	record_instruction(line, instructions, i);
			// printf("BEFORE FREE(LINE)\n");
			free(line);
			// printf("AFTER FREE(LINE)\n");
			instructions_recorded++;
			if (instructions_recorded > instruction_array_size)
			{
				instruction_array_size *= 2;
				int *new_instructions = ft_calloc(instruction_array_size, sizeof(int));
				memcpy(new_instructions, instructions, instruction_array_size / 2);
				// printf("BEFORE FREE\n");
				free(instructions);
				instructions = new_instructions;
				// printf("AFTER FREE\n");
			}
		}
		i++;
	}
	// if (check_if_valid_instructions(instructions))
	// 	ft_printf("VALID!\n");

	// print_stacks("START", stack_a, stack_b);
	// for (int j = 0; j < 1000; j++)
	// {
	// 	printf("%d, ", instructions[j]);
	// }
	// printf("\n");

	if (!check_if_valid_instructions(instructions))
	{
		return (write(1, "ERROR\n", 6), 1);
	}

	i = 0;
	// printf("%d\n", instructions[i]);
	while (instructions[i] != 0)
	{
		// printf("i: %d\n", i);
		run_instruction(instructions, i, &stack_a, &stack_b);
		// print_stacks("INSTRUCTION", stack_a, stack_b);
		i++;
	}
	
	// print_stacks("END", stack_a, stack_b);

	//! ALSO CHECK IF LEN IS THE SAME AS START.
	if (check_if_ordered(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
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
		return (write(2, "Error\n", 6), number_strings);
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