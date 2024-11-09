/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:38:34 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/09 14:51:02 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

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

// debug.c //! DELETE
void				test_number_strings(char **number_strings);
void				print_stacks(char *title, t_node *stack_a, t_node *stack_b);
void				print_stack_values(t_node *stack);

// checks.c
int					check_if_numbers(char **number_strings);
int					check_if_int_overflow(char **number_strings);
int					check_if_duplicate_numbers(t_node *list);
int					check_if_ordered(t_node *stack_a);

// utils
t_node              *create_node(int number);
int                 add_last_link(t_node *list_node, t_node *node_to_point_to);

// free.c
t_number_strings	free_number_strings(t_number_strings number_strings);
void				free_stacks(t_stack_tuple *stacks);
void				free_stacks_separately(t_node *stack_a, t_node *stack_b);

// STACK ACTIONS
// base
t_node				*swap_nodes(t_node *list);
t_stack_tuple		*push_node(t_node *to, t_node *from);
t_node				*rotate_stack(t_node *stack);
t_node				*reverse_rotate_stack(t_node *stack);

// swap
t_node				*sa(t_node *stack_a);
t_node				*sb(t_node *stack_b);
t_stack_tuple		*ss(t_node *stack_a, t_node *stack_b);
// push
t_stack_tuple		*pa(t_node *stack_a, t_node *stack_b);
t_stack_tuple		*pb(t_node *stack_b, t_node *stack_a);
// rotate
t_node				*ra(t_node *stack_a);
t_node				*rb(t_node *stack_b);
t_stack_tuple		*rr(t_node *stack_a, t_node *stack_b);
// reverse rotate
t_node				*rra(t_node *stack_a);
t_node				*rrb(t_node *stack_b);
t_stack_tuple		*rrr(t_node *stack_a, t_node *stack_b);
#endif