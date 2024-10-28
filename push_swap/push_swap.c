/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/28 13:39:12 by cargonz2         ###   ########.fr       */
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
	list = reverse_rotate_stack(list);
	
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
	ft_printf("%11s   %2s   %2s   %2s\n", "number", "ord_pos", "pos", "tar_pos");
	while (i < list_len)
	{
		ft_printf("%11d   %7d   %3d   %7d\n", stack->number, stack->ordered_position, stack->position, stack->target_position);
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


//! This only works if stack_a is at least of size 2.
//! BUGGY!
t_stack_tuple *split_stacks(t_node *stack_a, t_node *stack_b)
{
	int	largest_numbers[3];
	int large_numbers_index;
	int a_len;
	int i;
	int temp_number;
	t_node *stack_a_start;

	large_numbers_index = 0;
	a_len = get_list_len(stack_a);
	i = 0;
	stack_a_start = stack_a;

	// init largest_numbers[].
	while (i < 3)
	{
		largest_numbers[i] = stack_a->number;
		stack_a = stack_a->next_node;
		i++;
	}

	// order temp values.
	//! Seemingly working
	while (!(largest_numbers[0] < largest_numbers[1])
		|| !(largest_numbers[1] < largest_numbers[2])
		|| !(largest_numbers[0] < largest_numbers[2]))
	{
		if (largest_numbers[1] > largest_numbers[2])
		{
			temp_number = largest_numbers[2];
			largest_numbers[2] = largest_numbers[1];
			largest_numbers[1] = temp_number;
		}
		if (largest_numbers[0] > largest_numbers[1])
		{
			temp_number = largest_numbers[1];
			largest_numbers[1] = largest_numbers[0];
			largest_numbers[0] = temp_number;
		}
	}

	// set actual largest_numbers.
	while (i < a_len) //! Shares i with previous loop!
	{
		if (stack_a->number > largest_numbers[2])
		{
			temp_number = largest_numbers[1];
			largest_numbers[0] = temp_number;
			largest_numbers[1] = largest_numbers[2];
			largest_numbers[2] = stack_a->number;
		}
		else if (stack_a->number > largest_numbers[1])
		{
			largest_numbers[0] = largest_numbers[1];
			largest_numbers[1] = stack_a->number;
		}
		else if (stack_a->number > largest_numbers[0])
			largest_numbers[0] = stack_a->number;
		stack_a = stack_a->next_node;
		i++;
	}

	for(int j = 0; j < 3; j++)
		ft_printf("largest_numbers[%d]: %d\n", j, largest_numbers[j]);
	i = 0;
	stack_a = stack_a_start;
	t_node *temp_node;
	t_stack_tuple *stacks;
	while (i < a_len)
	{
		if ((stack_a->number == largest_numbers[0])
			|| (stack_a->number == largest_numbers[1])
			|| (stack_a->number == largest_numbers[2]))
		{
			printf("match!\n");
			stack_a = ra(stack_a);
		}
		else
		{
			printf("nope!\n");
			printf("stack_a: %d\n", stack_a->number);
			printf("stack_b: %p\n", stack_b);
			// printf("stack_b: %d\n", stack_b->number);
			stacks = pb(stack_b, stack_a); //! HANDLE NULL!
			printf("here?\n");
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
		}
		i++;
	}
	for(int j = 0; j < 3; j++)
		ft_printf("largest_numbers[%d]: %d\n", j, largest_numbers[j]);

	// Set order of stack_a to ascending.
	t_node *first_node = stack_a;
	t_node *middle_node = stack_a->next_node;
	t_node *last_node = stack_a->next_node->next_node;

	temp_node = first_node;
	first_node = last_node;
	last_node = temp_node;
	first_node->next_node = middle_node;
	middle_node->next_node = last_node;
	last_node->next_node = NULL;
	stack_a = first_node;
	printf("%d\n", first_node->number);
	printf("%d\n", first_node->next_node->number);
	printf("%d\n", first_node->next_node->next_node->number);


	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;

	return (stacks);
}

//! NOT SURE IF BASED ON STACK_A'S ORD_POS OR POS.
void set_target(t_node *stack_a, t_node *stack_b)
{
	int len = get_list_len(stack_a);
	int i = 0;
	int j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (stack_b->number < stack_a->number)
			{
				stack_b->target_position = stack_a->position; //? May be ord_pos?
				
			}

			j++;
		}
		j = 0;
		stack_a->target_position;
		i++;
	}

}


//! ENSURE CORRECT MEMORY MANAGEMENT.
//! For example no ft_split malloc unfreed.
int main(int argc, char *argv[])
{
	char **number_strings;
	t_node *stack_a;
	t_node *stack_b;
	t_stack_tuple *stacks;

	if (!(number_strings = create_number_strings(argc, argv)))
		return (1);
	if (!(stack_a = create_stack_a(number_strings)))
		return (1);

	set_ordered_position(stack_a, get_list_len(stack_a));

	stack_b = NULL;
	print_stack_values(stack_a);
	print_stack_values(stack_b);
	stacks = split_stacks(stack_a, stack_b);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	while (stack_b)
	{
		set_position(stack_a);
		set_position(stack_b);
		print_stack_values(stack_a);
		printf("\n");
		print_stack_values(stack_b);
		printf("\n");

		set_target(stack_a, stack_b);
	}


	return (0);
}