/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/09 18:33:23 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_strings(char **char_array)
{
	int	count;

	count = 0;
	while (char_array[count])
		count++;
	return (count);
}

int main(int argc, char *argv[])
{
	if (argc != 2) //? Should argc !=2 behave differently?
		return (ft_printf("Error: invalid argument count.\n"), 1);
	
	//! VALIDATE WHETHER DUPLICATE NUMBERS!

	char **number_strings = ft_split(argv[1], ' ');

	t_node *new_node;
	t_node *previous_node;
	t_node *first_node;

	previous_node = NULL;
	int	i = 0;
	while (number_strings[i])
	{
		int number = ft_atoi(number_strings[i]);
		new_node = create_node(number);
		if (!new_node)
			return (1); //? Frees?
		if (!previous_node)
			first_node = new_node;
		else
			add_last_link(previous_node, new_node);
		previous_node = new_node;
		i++;
	}

	while (first_node->next_node != NULL)
	{
		ft_printf("%d\n", first_node->number);
		first_node = first_node->next_node;
	}
	ft_printf("%d\n", first_node->number);

	return (0);
}