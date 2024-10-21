/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:40:05 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/21 18:53:10 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Allocates a new node initialized to the "number" value.
// Memory must be handled by the user.
t_node	*create_node(int number)
{
	t_node	*node;
	
	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (NULL);

	node->number = number;
	return (node);
}

// Returns 0 if input is valid, -1 if any input is NULL.
int add_last_link(t_node* list_node, t_node* node_to_point_to)
{
	if (list_node == NULL || node_to_point_to == NULL)
		return (-1);
	if (list_node == NULL)
		list_node->next_node = node_to_point_to;
	else
	{
		while (list_node->next_node != NULL)
			list_node = list_node->next_node;
		list_node->next_node = node_to_point_to;
	}
	return (0);
}
