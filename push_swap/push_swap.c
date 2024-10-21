/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/21 19:13:26 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <climits>

int	number_of_strings(char **char_array)
{
	int	count;

	count = 0;
	while (char_array[count])
		count++;
	return (count);
}

int check_if_numbers(char **number_strings)
{
	int i = 0;
	int j = 0;
	char c;
	while (number_strings[i])
	{
		c = number_strings[i][j];
		if (c == '-' || c == '+')
		{
			j++;
			c = number_strings[i][j];
			if (!c)
				return (0);
		}
		while (c && (c >= '0' && c <= '9'))
		{
			j++;
			c = number_strings[i][j];
		}
		if (c != '\0' && !(c >= '0' && c <= '9'))
		{
			// ft_printf("Error on: %c (%d)\n", c, c); 
			return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int check_if_int_overflow(char **number_strings)
{
	int number = 0;
	int sign = 1;
	int i = 0;
	int j = 0;

	char *max_int_str = ft_itoa(INT_MAX);
	int max_int_str_len = strlen(max_int_str);
	free(max_int_str);
	// if (number_strings[i][0] == '-')
	if (ft_strlen(number_strings[i]) > max_int_str_len)
	{
		free(max_int_str);
		return (1);
	}
	free(max_int_str);
	if ()

	while (number_strings[i])
	{
		while (number_strings[i][j])
		{
			if (number_strings[i][j] == '-')
			{
				sign = -1;
				i++;
			}
			else if (number_strings[i][j] == '+')
				i++;
			while (number_strings[i][j] >= '0' && number_strings[i][j] <= '9')
			{
				if (i > 0)
					num *= 10;
				num += str[i] - '0';
				i++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
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
		if (a->number == b->number)
			return (1);
		b = list;
		a = a->next_node;
	}
	return (0);
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

//! ENSURE CORRECT MEMORY MANAGEMENT.
//! For example no ft_split malloc unfreed.
int main(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	
	// ! HANDLE THE FOLLOWING ERRORS (IN EVERY CASE THE OUTPUT SHOULD BE "Error\n"):
	// // ! SOME ARGUMENTS ARE NOT NUMBERS.
	// ! SOME ARGUMENTS ARE BIGGER THAN AN INTEGER.
	// // ! THERE ARE DUPLICATE NUMBERS.

	char **number_strings;
	char **number_strings_test;
	if (argc == 2)
	{
		number_strings = ft_split(argv[1], ' ');
		if (!check_if_numbers(number_strings))
			return (write(2, "Error: Non-number input.\n", 25), 1);

		int i = 0;
		while (number_strings[i] != NULL)
		{
			ft_printf("%s\n", number_strings[i]);
			i++;
		}
		i = 0;
		// number_strings_test = ft_split(argv[2], ' '); //! DELETE
	}
	else
		number_strings = &argv[1];

	t_node *list = create_list_of_integers_from_strings(number_strings);
	// t_node *list_test = create_list_of_integers_from_strings(number_strings_test); //! DELETE

	if (check_if_int_overflow(list))
		return (write(2, "Error: Number values outside integer bounds not allowed.\n", 57), 1);

	if (check_if_duplicate_numbers(list))
		return (write(2, "Error: Duplicate values are not allowed.\n", 41), 1);

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

	// list = rotate_stack(list);
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