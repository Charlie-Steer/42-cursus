/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:41:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/07 16:26:39 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

// ! REMOVE COMPETING STRUCT DEFINITION?
typedef struct s_node {
	struct s_node	*next_node;
	int		number;
	int		position;
	int		ordered_position;
	int		target_position;
	int		a_surface_cost;
	int		b_surface_cost;
	int		total_cost;
} t_node;

typedef struct s_stack_tuple {
	t_node *stack_a;
	t_node *stack_b;
	int		return_code;
} t_stack_tuple;

typedef struct s_stacks_and_costs {
	t_node	*stack_a;
	t_node	*stack_b;
	int		a_cost;
	int		b_cost;
} t_stacks_and_costs;

typedef struct s_number_strings {
	char **number_strings;
	int is_heap_allocated;
} t_number_strings;

enum e_stack {
	A,
	B
};

// rotate_and_push.c
t_stack_tuple		*surface_nodes_and_push_a(t_node *stack_a, t_node* stack_b, t_node *node_to_move);

// set_costs.c
void				set_surface_costs(t_node *stack_a, t_node *stack_b);
void				set_total_cost(t_node *stack_b);

// split_stacks.c
t_stack_tuple		*push_nodes_to_b(t_node *stack_a, t_node *stack_b, int a_len, int *largest_numbers);
t_node				*order_stack_a(t_node *stack_a);
t_stack_tuple		*handle_one_and_two_len_cases(t_stack_tuple *stacks, int a_len);
t_stack_tuple		*split_stacks(t_node *stack_a, t_node *stack_b);

// split_stacks_helper.c
int					init_and_order_largest_numbers(t_node *stack_a, int *largest_numbers, int a_len);
void				set_actual_largest_numbers(t_node *stack_a, int a_len, int *largest_numbers);

// main subroutines 1
t_node				*create_list_of_integers_from_strings(char **number_strings);
t_node				*set_ordered_position(t_node *list, int number_of_integers);
t_number_strings	create_number_strings(int argc, char *argv[]);
t_node				*create_stack_a(t_number_strings number_strings);
void				set_position(t_node *stack);

// debug.c //! DELETE
void				test_number_strings(char **number_strings);
void 				print_stacks(char *title, t_node *stack_a, t_node *stack_b);
void 				print_stack_values(t_node *stack);

// list_utils.c
t_node				*create_node(int number);
int					add_last_link(t_node* list_node, t_node* node_to_point_to);

// checks.c
int					check_if_numbers(char **number_strings);
int					check_if_int_overflow(char **number_strings);
int					check_if_duplicate_numbers(t_node *list);
int					check_if_ordered(t_node *stack_a);

// utils.c
long				ft_atoi_long(const char *str);
int					numlen(long long n);
int					ft_abs(int n);
int					get_list_len(t_node *list);
int					ft_min(int a, int b);

int					number_of_strings(char **char_array);

// free.c
t_number_strings	free_number_strings(t_number_strings number_strings);
void				free_stacks(t_stack_tuple *stacks);
void				free_stacks_separately(t_node *stack_a, t_node *stack_b);

// STACK ACTIONS
// base
t_node				*swap_nodes(t_node *list);
t_stack_tuple		*push_node(t_node *to, t_node *from);
t_node				*rotate_stack(t_node* stack);
t_node				*reverse_rotate_stack(t_node* stack);

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