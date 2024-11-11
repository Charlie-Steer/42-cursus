/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:38:34 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/11 19:07:27 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft/libft.h"

# define INITIAL_INSTRUCTION_NUMBER 100000

typedef struct s_node
{
	struct s_node	*next_node;
	int				number;
	int				position;
	int				ordered_position;
	int				target_position;
	int				a_surface_cost;
	int				b_surface_cost;
	int				total_cost;
}	t_node;

typedef struct s_stack_tuple
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		return_code;
}	t_stack_tuple;

typedef struct s_number_strings
{
	char	**number_strings;
	int		is_heap_allocated;
}	t_number_strings;

enum e_action
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

// extra_bonus.c
void				print_ok_or_ko(int condition);

// instruction_handling.c
int					*read_input_and_record_instructions(int *instructions);
void				run_instructions(
						int *instructions, t_node **stack_a, t_node **stack_b);
void				handle_one_number(int *instructions);

// checks_bonus.c
int					check_if_numbers(char **number_strings);
int					check_if_int_overflow(char **number_strings);
int					check_if_duplicate_numbers(t_node *list);
int					check_if_ordered(t_node *stack_a);
int					check_if_valid_instructions(int *instructions);

// utils_bonus.c
t_node				*create_node(int number);
int					add_last_link(t_node *list_node, t_node *node_to_point_to);
int					get_list_len(t_node *list);

// free_bonus.c
t_number_strings	free_number_strings(t_number_strings number_strings);
void				free_stacks(t_stack_tuple *stacks);
void				free_everything(int *instructions, t_node *stack_a,
						t_node *stack_b);

// STACK ACTIONS
// base
t_node				*swap_nodes(t_node *list);
t_stack_tuple		*push_node(t_node *to, t_node *from);
t_node				*rotate_stack(t_node *stack);
t_node				*reverse_rotate_stack(t_node *stack);
// swap
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
// push
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_b, t_node **stack_a);
// rotate
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
// reverse rotate
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
#endif
