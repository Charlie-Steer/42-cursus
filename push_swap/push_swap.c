/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/16 18:24:33 by cargonz2         ###   ########.fr       */
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

t_node	*create_list_of_integers_from_strings(char **number_strings)
{
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
			return (NULL); //? Frees?
		if (!previous_node)
			first_node = new_node;
		else
			add_last_link(previous_node, new_node);
		previous_node = new_node;
		i++;
	}

	return (first_node);
}

int check_if_duplicate_numbers(t_node *list)
{
	t_node	*a = list;
	t_node	*b = list;
	while (a->next_node != NULL)
	{
		while (b->next_node != NULL)
		{
			if (a == b)
			{
				b = b->next_node;
				continue ;
			}
			if (a->number == b->number)
				return (1);
			b = b->next_node;
		}
		b = list;
		a = a->next_node;
	}
	return (0);
}

int	calculate_number_of_integers(t_node *list)
{
	int number_of_ints;

	if (!list)
		return (0);
	number_of_ints = 1;
	while (list->next_node != NULL)
	{
		number_of_ints++;
		list = list->next_node;
	}
	return (number_of_ints);
}

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_node *set_ordered_position(t_node *list, int number_of_integers)
{
	int i;
	int j;
	t_node *node_to_sort;
	t_node *node_to_compare_to;

	node_to_sort = list;
	node_to_compare_to = list;
	i = 0;
	j = 0;
	while (i < number_of_integers)
	{
		i++;
		while (j < number_of_integers)
		{
			j++;
			if (node_to_sort == node_to_compare_to)
			{
				node_to_compare_to = node_to_compare_to->next_node;
				continue ;
			}
			if (node_to_sort->number > node_to_compare_to->number)
				node_to_sort->ordered_position++;
			node_to_compare_to = node_to_compare_to->next_node;
		}
		node_to_compare_to = list;
		j = 0;
		node_to_sort = node_to_sort->next_node;
	}
	return (list);
}


int main(int argc, char *argv[])
{
	// ! MAYBE VALUES SHOULDN'T BE PROVIDED AS A SINGLE STRING
	// ! BUT AS AN INFINITE AMOUNT OF ARGUMENTS.

	// ! ALLOWED TWO LISTS BECAUSE OF TESTING PURPOSES
	if (argc != 2 && argc != 3) //? Should argc !=2 behave differently? Instructions say to "give the prompt back".
		return (ft_printf("Error: invalid argument count.\n"), 1);
	
	// ! HANDLE THE FOLLOWING ERRORS (IN EVERY CASE THE OUTPUT SHOULD BE "Error\n"):
	// ! SOME ARGUMENTS ARE NOT INTEGERS.
	// ! SOME ARGUMENTS ARE BIGGER THAN AN INTEGER.
	// ! THERE ARE DUPLICATE NUMBERS.
	
	char **number_strings = ft_split(argv[1], ' ');
	char **number_strings_test = ft_split(argv[2], ' '); //! DELETE
	t_node *list = create_list_of_integers_from_strings(number_strings);
	t_node *list_test = create_list_of_integers_from_strings(number_strings_test); //! DELETE

	if (check_if_duplicate_numbers(list) == 1)
		return (ft_printf("Error: duplicate values are not allowed\n"), 1);

	// // create_list  test
	// {
	// 	while (list->next_node != NULL)
	// 	{
	// 		ft_printf("%d\n", list->number);
	// 		list = list->next_node;
	// 	}
	// 	ft_printf("%d\n", list->number);
	// }

	set_ordered_position(list, calculate_number_of_integers(list));
	// // set_ordered_position test
	// {
	// 	while (list->next_node != NULL)
	// 	{
	// 		ft_printf("%d\n", list->ordered_position);
	// 		list = list->next_node;
	// 	}
	// 	ft_printf("%d\n", list->ordered_position);
	// }

	// // list_state test
	// {
	// 	t_node *test_list = list;
	// 	while (list->next_node != NULL)
	// 	{
	// 		ft_printf("%d\n", list->number);
	// 		list = list->next_node;
	// 	}
	// 	ft_printf("%d\n\n", list->number);
	// }

	// swap_nodes(list);
	// push_node(list, list_test);

	// push_node(list, list_test);
	list = inverse_rotate_stack(list);
	list = inverse_rotate_stack(list);
	
	// list_state test
	{
		t_node *test_list = list;
		while (test_list->next_node != NULL)
		{
			ft_printf("%d\n", test_list->number);
			test_list = test_list->next_node;
		}
		ft_printf("%d\n\n", test_list->number);
	}

	// // list_state test
	// {
	// 	t_node *test_list = list_test;
	// 	while (test_list->next_node != NULL)
	// 	{
	// 		ft_printf("%d\n", test_list->number);
	// 		test_list = test_list->next_node;
	// 	}
	// 	ft_printf("%d\n\n", test_list->number);
	// }


	return (0);
}