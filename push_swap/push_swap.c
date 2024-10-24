/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/24 16:18:46 by cargonz2         ###   ########.fr       */
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

#include <stdio.h>
int check_if_int_overflow(char **number_strings)
{
	long number;
	int i = 0;
	int	min_int_len;
	int max_int_len;

	min_int_len = numlen(INT_MIN);
	max_int_len = numlen(INT_MAX);
	while (number_strings[i])
	{
		int number_string_len = ft_strlen(number_strings[i]);
		if (number_strings[i][0] == '-' && number_string_len > min_int_len)
				return (1);
		else if (number_strings[i][0] != '-' && number_string_len > max_int_len)
				return (1);
		else
		{
			number = ft_atoi_long(number_strings[i]);
			if (number_strings[i][0] == '-' && number < (long)INT_MIN
			|| number_strings[i][0] != '-' && number > (long)INT_MAX)
				return (1);
		}
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

int	get_list_len(t_node *list)
{
	int len;

	if (!list)
		return (0);
	len = 1;
	while (list->next_node != NULL)
	{
		len++;
		list = list->next_node;
	}
	return (len);
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

void test_stack_actions(t_node *list)
{
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
}

char **create_number_strings(int argc, char *argv[])
{
	if (argc == 1)
		return (NULL);

	char **number_strings;
	if (argc == 2)
		number_strings = ft_split(argv[1], ' ');
	else
		number_strings = &argv[1];

	// //print number_strings
	// {
	// 	int i = 0;
	// 	while (number_strings[i] != NULL)
	// 	{
	// 		ft_printf("%11s\n", number_strings[i]);
	// 		i++;
	// 	}
	// }

	if (!check_if_numbers(number_strings))
		return (write(2, "Error: Non-number input.\n", 25), NULL);
	else if (check_if_int_overflow(number_strings))
		return (write(2, "Error: Number values outside integer bounds not allowed.\n", 57), NULL);
	else
	 	return (number_strings);
}

t_node	*create_stack_a(char *number_strings[])
{
	t_node *list = create_list_of_integers_from_strings(number_strings);
	if (!list)
		return (write(2, "Error\n", 6), NULL);

	if (check_if_duplicate_numbers(list))
		return (write(2, "Error: Duplicate values are not allowed.\n", 41), NULL);
	else
		return (list);
}

void print_stack_values(t_node *stack)
{
	int i;
	int list_len;

	i = 0;
	list_len = get_list_len(stack);
	ft_printf("%11s   %2s   %2s\n", "number", "ord_pos", "pos");
	while (i < list_len)
	{
		ft_printf("%11d   %7d   %3d\n", stack->number, stack->ordered_position, stack->position);
		if (stack->next_node)
			stack = stack->next_node;
		i++;
	}
}

void set_position(t_node *stack)
{
	int i;
	int len;

	i = 0;
	len = get_list_len(stack);
	while (i < len)
	{
		// ft_printf("%d\n", i);
		stack->position = i;
		stack = stack->next_node;
		i++;
	}
}


//! NON-WORKING STATE. ASK FOR ADVICE.
//! This only works if stack_a is at least of size 2.
void split_stacks(t_node *stack_a, t_node *stack_b)
{
	int	largest_numbers[3];
	int large_numbers_index;
	int a_len;
	int i;
	t_node *stack_a_traversal;

	large_numbers_index = 0;
	a_len = get_list_len(stack_a);
	i = 0;
	stack_a_traversal = stack_a;

	// init largest_numbers[].
	while (i < 3)
	{
		largest_numbers[i] = stack_a_traversal->number;
		stack_a_traversal = stack_a_traversal->next_node;
	}

	while (i < a_len)
	{
		ft_max(stack_a->number, );
		i++;
	}

	// Alternate solution.

	while ((a_len = get_list_len(stack_a)) > 3)
	{
		push_node(stack_a, stack_b);
	}

}


//! ENSURE CORRECT MEMORY MANAGEMENT.
//! For example no ft_split malloc unfreed.
int main(int argc, char *argv[])
{
	char **number_strings;
	t_node *stack_a;
	t_node stack_b;

	if (!(number_strings = create_number_strings(argc, argv)))
		return (1);
	if (!(stack_a = create_stack_a(number_strings)))
		return (1);

	set_ordered_position(stack_a, get_list_len(stack_a));

	//
	
	for (int i = 0; i < 10; i++) //! Change condition and for to while.
	{
		set_position(stack_a);
	}

	print_stack_values(stack_a);

	return (0);
}