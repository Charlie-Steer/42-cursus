/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:41:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/22 16:24:54 by cargonz2         ###   ########.fr       */
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

typedef struct s_list_tuple {
	t_node *from;
	t_node *to;
} t_list_tuple;

t_node			*create_node(int number);
int				add_last_link(t_node* list_node, t_node* node_to_point_to);
long			ft_atoi_long(const char *str);
int				numlen(long long n);

t_node			*swap_nodes(t_node *list);
t_list_tuple	push_node(t_node *from, t_node *to);
t_node			*rotate_stack(t_node* stack);
t_node			*inverse_rotate_stack(t_node* stack);
#endif