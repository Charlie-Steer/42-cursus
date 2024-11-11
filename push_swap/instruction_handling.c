/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:45:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 16:01:52 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	record_instruction(char *line, int *instructions, int index);
void	run_instruction(
			int *instructions, int i, t_node **stack_a, t_node **stack_b);

//! SEEMINGLY MAIN PROBLEMATIC FUNCTION
int	*read_input_and_record_instructions(int *instructions)
{
	char	*line;
	int		instruction_index;
	int		instruction_array_size;
	int		*new_instructions;

	instruction_array_size = INITIAL_INSTRUCTION_NUMBER;
	instructions = ft_calloc(instruction_array_size, sizeof(int));
	instruction_index = 0;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		record_instruction(line, instructions, instruction_index);
		free(line);
		if (++instruction_index > instruction_array_size)
		{
			instruction_array_size *= 2;
			new_instructions = ft_calloc(instruction_array_size, sizeof(int));
			memcpy(new_instructions, instructions, instruction_array_size / 2);
			free(instructions);
			instructions = new_instructions;
		}
	}
	return (instructions);
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

void	run_instructions(int *instructions, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (instructions[i] != 0)
	{
		run_instruction(instructions, i, stack_a, stack_b);
		i++;
	}
}

void	run_instruction(
	int *instructions, int i, t_node **stack_a, t_node **stack_b)
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

void	handle_one_number(int *instructions)
{
	int	i;
	int	push_a_balance;
	int	push_b_balance;

	push_a_balance = 0;
	push_b_balance = 1;
	i = 0;
	while (instructions[i] != 0)
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
		i++;
	}
	print_ok_or_ko(push_a_balance == 0 && push_b_balance == 1);
}
