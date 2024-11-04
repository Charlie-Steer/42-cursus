/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:41:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/04 15:19:22 by cargonz2         ###   ########.fr       */
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

enum e_stack {
	A,
	B
};

t_node			*create_node(int number);
int				add_last_link(t_node* list_node, t_node* node_to_point_to);
long			ft_atoi_long(const char *str);
int				numlen(long long n);

t_node			*swap_nodes(t_node *list);
t_stack_tuple	*push_node(t_node *to, t_node *from);
t_node			*rotate_stack(t_node* stack);
t_node			*reverse_rotate_stack(t_node* stack);
int				ft_abs(int n);

// STACK ACTIONS
// swap
t_node			*sa(t_node *stack_a);
t_node			*sb(t_node *stack_b);
t_stack_tuple	*ss(t_node *stack_a, t_node *stack_b);
// push
t_stack_tuple	*pa(t_node *stack_a, t_node *stack_b);
t_stack_tuple	*pb(t_node *stack_b, t_node *stack_a);
// rotate
t_node			*ra(t_node *stack_a);
t_node			*rb(t_node *stack_b);
t_stack_tuple	*rr(t_node *stack_a, t_node *stack_b);
// reverse rotate
t_node			*rra(t_node *stack_a);
t_node			*rrb(t_node *stack_b);
t_stack_tuple	*rrr(t_node *stack_a, t_node *stack_b);
#endif