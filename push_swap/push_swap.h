/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:41:38 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/07 20:11:28 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
// ! REMOVE COMPETING STRUCT DEFINITION?
struct s_list {
	s_list	*next_node;
	int		*number;
	int		*position;
	int		*ordered_position;
	int		*target_position;
	int		*a_surface_cost;
	int		*b_surface_cost;
	int		*total_cost;
} t_list;
#endif