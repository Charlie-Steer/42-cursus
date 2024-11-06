/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/06 17:39:34 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(char *title, t_node *stack_a, t_node *stack_b);
void set_target(t_node *stack_a, t_node *stack_b);
void free_stacks_separately(t_node *stack_a, t_node *stack_b);
t_number_strings free_number_strings(t_number_strings number_strings);

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
}

// char **create_number_strings(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		return (NULL);
// 	else if (argv[1] == NULL || argv[1][0] == '\0')
// 		return (write(2, "Error\n", 6), NULL);

// 	char **number_strings;
// 	if (argc == 2)
// 		number_strings = ft_split(argv[1], ' ');
// 	else
// 		number_strings = &argv[1];

// 	if (!check_if_numbers(number_strings))
// 		return (write(2, "Error\n", 6), NULL);
// 		// return (write(2, "Error: Non-number input.\n", 25), NULL);
// 	else if (check_if_int_overflow(number_strings))
// 		return (write(2, "Error\n", 6), NULL);
// 		// return (write(2, "Error: Number values outside integer bounds not allowed.\n", 57), NULL);
// 	else
// 	 	return (number_strings);
// }

t_number_strings create_number_strings(int argc, char *argv[])
{
	t_number_strings number_strings;
	ft_memset(&number_strings, 0, sizeof(number_strings));
	if (argc == 1)
		return (number_strings);
	else if (argv[1] == NULL || argv[1][0] == '\0')
		return (write(2, "Error\n", 6), number_strings);

	if (argc == 2) {
		number_strings.number_strings = ft_split(argv[1], ' ');
		number_strings.is_heap_allocated = 1;
	}
	else
		number_strings.number_strings = &argv[1];

	if (!check_if_numbers(number_strings.number_strings)) {
		number_strings = free_number_strings(number_strings);
		return (write(2, "Error\n", 6), number_strings);
	}
		// return (write(2, "Error: Non-number input.\n", 25), NULL);
	else if (check_if_int_overflow(number_strings.number_strings)) {
		number_strings = free_number_strings(number_strings);
		return (write(2, "Error\n", 6), number_strings);
	}
		// return (write(2, "Error: Number values outside integer bounds not allowed.\n", 57), NULL);
	else
	 	return (number_strings);
}

t_number_strings free_number_strings(t_number_strings number_strings)
{
    int i = 0;
    if (!number_strings.number_strings || !number_strings.is_heap_allocated)
        return (number_strings);
    while (number_strings.number_strings[i]) {
        free(number_strings.number_strings[i]);
		i++;
	}
    free(number_strings.number_strings);
	number_strings.number_strings = NULL;
	return (number_strings);
}

void test_number_strings(char **number_strings)
{
	int i = 0;
	while (number_strings[i] != NULL) {
		printf("%s\n", number_strings[i]);
		i++;
	}
}

t_node	*create_stack_a(t_number_strings number_strings)
{
	t_node *list = create_list_of_integers_from_strings(number_strings.number_strings);
	// test_number_strings(number_strings.number_strings);
	if (number_strings.is_heap_allocated) {
		free_number_strings(number_strings);
	}
	if (!list)
		return (write(2, "Error\n", 6), NULL);

	if (check_if_duplicate_numbers(list)) {
		free_stacks_separately(list, NULL);
		return (write(2, "Error\n", 6), NULL);
		// return (write(2, "Error: Duplicate values are not allowed.\n", 41), NULL);
	}
	else
		return (list);
}

void print_stack_values(t_node *stack)
{
	int i;
	int list_len;

	i = 0;
	list_len = get_list_len(stack);
	ft_printf("%11s   %2s   %2s   %2s   %2s   %2s   %2s\n", "number", "ord_pos", "pos", "tar_pos", "cost_a", "cost_b", "total_cost");
	while (i < list_len)
	{
		ft_printf("%11d   %7d   %3d   %7d   %7d   %7d   %7d\n", stack->number, stack->ordered_position, stack->position, stack->target_position, stack->a_surface_cost, stack->b_surface_cost, stack->total_cost);
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

int *init_largest_numbers_array(t_node *stack_a, int *largest_numbers) {
	int i = 0;

	// init largest_numbers[].
	while (i < 3)
	{
		largest_numbers[i] = stack_a->number;
		stack_a = stack_a->next_node;
		i++;
	}
	return (largest_numbers);
}

int *order_largest_numbers_array(t_node *stack_a, int *largest_numbers) {
	int i = 0;
	int temp_number;

	// order temp values.
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
	return (largest_numbers);
}

// returns 0 if ordered, 1 if unordered.
int init_and_order_largest_numbers(t_node *stack_a, int *largest_numbers, int a_len) {
	init_largest_numbers_array(stack_a, largest_numbers);
	// printf("%d, %d, %d\n", largest_numbers[0], largest_numbers[1], largest_numbers[2]);
	order_largest_numbers_array(stack_a, largest_numbers);
	// printf("%d, %d, %d\n", largest_numbers[0], largest_numbers[1], largest_numbers[2]);
	if (a_len == 3)
		return (1);
	return (0);
}

void set_actual_largest_numbers(t_node *stack_a, int a_len, int *largest_numbers) {
	int i = 3;

	stack_a = stack_a->next_node->next_node->next_node;
	while (i < a_len)
	{
		if (stack_a->number > largest_numbers[2])
		{
			largest_numbers[0] = largest_numbers[1];
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
}

t_stack_tuple *push_nodes_to_b(t_node *stack_a, t_node *stack_b, int a_len, int *largest_numbers) {
	int i = 0;
	t_node *temp_node;
	t_stack_tuple *stacks;
	while (i < a_len)
	{
		if ((stack_a->number == largest_numbers[0])
			|| (stack_a->number == largest_numbers[1])
			|| (stack_a->number == largest_numbers[2]))
		{
			stack_a = ra(stack_a);
		}
		else
		{
			stacks = pb(stack_b, stack_a); //! HANDLE NULL!
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
			free(stacks);
		}
		i++;
	}
	stacks = malloc(sizeof(t_stack_tuple));
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	return (stacks);
}

t_node *order_stack_a(t_node *stack_a, t_node *stack_b) {
	// Set order of stack_a to ascending.
	t_stack_tuple *stacks;
	t_node *stack_a_start = stack_a;
	int largest_number = stack_a->number;
	if (stack_a->next_node->number > largest_number)
		largest_number = stack_a->next_node->number;
	if (stack_a->next_node->next_node->number > largest_number)
		largest_number = stack_a->next_node->next_node->number;

	if (stack_a->number == largest_number)
		stack_a = ra(stack_a);
	else if (stack_a->next_node->number == largest_number)
		stack_a = rra(stack_a);

	if (stack_a->number > stack_a->next_node->number)
		stack_a = sa(stack_a);

	return (stack_a);
}

t_stack_tuple *handle_one_and_two_len_cases(t_stack_tuple *stacks, int a_len)
{
	if (a_len == 1)
	{
		stacks->return_code = 0;
		return (stacks);
	}
	else if (a_len == 2)
	{
		if (stacks->stack_a->number > stacks->stack_a->next_node->number) {
			stacks->stack_a = sa(stacks->stack_a);
			// printf("%d, %d\n", stacks->stack_a->number, stacks->stack_a->next_node->number);
			stacks->return_code = 0;
		}
		return (stacks);
	}
	else
	{
		ft_printf("This shouldn't be happening.");	
		return (NULL);
	}
}

//! This only works if stack_a is at least of size 2.
//! USER HAS TO FREE T_STACK_TUPLE.
t_stack_tuple *split_stacks(t_node *stack_a, t_node *stack_b)
{
	t_stack_tuple *stacks = malloc(sizeof(t_stack_tuple));
	if (!stacks)
		return (NULL);
	int	*largest_numbers;
	int a_len;

	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	a_len = get_list_len(stack_a);
	if (a_len == 1 || a_len == 2)
	{
		stacks = handle_one_and_two_len_cases(stacks, a_len);
		return (stacks);
	}
	largest_numbers = malloc(3 * sizeof(int));
	init_and_order_largest_numbers(stack_a, largest_numbers, a_len);
	if (a_len > 3)
	{
		free(stacks);
		set_actual_largest_numbers(stack_a, a_len, largest_numbers);
		stacks = push_nodes_to_b(stack_a, stack_b, a_len, largest_numbers);
		stack_a = stacks->stack_a;
	}
	stack_a = order_stack_a(stack_a, stack_b);
	stacks->stack_a = stack_a;
	stacks->return_code = 1;
	free(largest_numbers);
	return (stacks);
}

void set_target(t_node *stack_a, t_node *stack_b)
{
	int a_len = get_list_len(stack_a);
	int b_len = get_list_len(stack_b);
	t_node *a_start = stack_a;
	int i = 0;
	int j = 0;
	while (i < b_len)
	{
		int min_a_above_b_number = INT_MAX;
		while (j < a_len)
		{
			if (stack_a->number > stack_b->number && stack_a->number <= min_a_above_b_number)
			{
				min_a_above_b_number = stack_a->number;
			}
			stack_a = stack_a->next_node;
			j++;
		}
		j = 0;
		stack_a = a_start;
		while (stack_a->number != min_a_above_b_number)
		{
			stack_a = stack_a->next_node;
		}
		stack_b->target_position = stack_a->position;
		stack_a = a_start;
		stack_b = stack_b->next_node;
		i++;
	}
}

void set_surface_cost(enum e_stack cost_stack, t_node *node, int stack_len)
{
	if (node->position <= stack_len / 2)
	{
		if (cost_stack == A)
		{
			node->a_surface_cost = node->position;
		}
		else if (cost_stack == B)
		{
			node->b_surface_cost = node->position;
		}
	}
	else
	{
		if (cost_stack == A)
		{
			node->a_surface_cost = node->position - stack_len;
		}
		else if (cost_stack == B)
		{
			node->b_surface_cost = node->position - stack_len;
		}
	}
}

void calculate_costs(t_node *stack_a, t_node *stack_b)
{
	t_node *stack_a_start = stack_a;
	t_node *stack_b_start = stack_b;
	int a_len = get_list_len(stack_a);
	int b_len = get_list_len(stack_b);

	// set cost_b
	int i = 0;
	while (i < b_len)
	{
		set_surface_cost(B, stack_b, b_len);
		stack_b = stack_b->next_node;
		i++;
	}

	// set cost_a
	i = 0;
	while (i < a_len)
	{
		set_surface_cost(A, stack_a, a_len);
		stack_a = stack_a->next_node;
		i++;
	}
	stack_a = stack_a_start;
	stack_b = stack_b_start;
	i = 0;
	while (i < b_len)
	{
		while (stack_a->position != stack_b->target_position)
		{
			stack_a = stack_a->next_node;
		}
		stack_b->a_surface_cost = stack_a->a_surface_cost;
		
		stack_a = stack_a_start;
		stack_b = stack_b->next_node;
		i++;
	}
}

void set_total_cost(t_node *stack_b)
{
	int	b_len;
	int i;

	b_len = get_list_len(stack_b);
	i = 0;
	while (i < b_len)
	{
		stack_b->total_cost = ft_abs(stack_b->a_surface_cost)
			+ ft_abs(stack_b->b_surface_cost);
		stack_b = stack_b->next_node;
		i++;
	}
}

t_node	*select_node(t_node *stack_b)
{
	int	b_len;
	int	i;
	t_node *cheapest_node;

	cheapest_node = stack_b;
	b_len = get_list_len(stack_b);
	i = 0;
	while (i < b_len) {
		if (stack_b->total_cost < cheapest_node->total_cost)
		{
			cheapest_node = stack_b;
		}
		stack_b = stack_b -> next_node;
		i++;
	}
	return (cheapest_node);
}

t_stack_tuple *surface_nodes_and_push_a(t_node *stack_a, t_node* stack_b, t_node *node_to_move)
{
	int a_cost = node_to_move->a_surface_cost;
	int b_cost = node_to_move->b_surface_cost;
	t_stack_tuple *stacks;
	while (a_cost || b_cost)
	{
		if (a_cost > 0 && b_cost > 0)
		{
			stacks = rr(stack_a, stack_b);
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
			a_cost -= 1;
			b_cost -= 1;
		}
		else if (a_cost < 0 && b_cost < 0)
		{
			stacks = rrr(stack_a, stack_b);
			stack_a = stacks->stack_a;
			stack_b = stacks->stack_b;
			a_cost += 1;
			b_cost += 1;
		}
		else if (a_cost > 0)
		{
			stack_a = ra(stack_a);
			a_cost -= 1;
		}
		else if (a_cost < 0)
		{
			stack_a = rra(stack_a);
			a_cost += 1;
		}
		else if (b_cost > 0)
		{
			stack_b = rb(stack_b);
			b_cost -= 1;
		}
		else if (b_cost < 0)
		{
			stack_b = rrb(stack_b);
			b_cost += 1;
		}
		else
			ft_printf("This shouldn't be happening.\n");
	}
	stacks = pa(stack_a, stack_b);
	return (stacks);
}

t_node *rotate_until_ordered(t_node *stack_a)
{
	int i = 0;
	int a_len = get_list_len(stack_a);
	t_node *stack_a_start = stack_a;
	t_node *stack_a_end = stack_a;
	while (i < a_len - 1)
	{
		stack_a_end = stack_a_end->next_node;
		i++;
	}

	i = 0;
	while (stack_a_end->number <= stack_a_start->number)
	{
		stack_a = rra(stack_a);
		stack_a_end = stack_a;
		while (i < a_len - 1)
		{
			stack_a_end = stack_a_end->next_node;
			i++;
		}
		i = 0;
	}
	return (stack_a);
}

void print_stacks(char *title, t_node *stack_a, t_node *stack_b) {
	printf("\n%s\n", title);
	print_stack_values(stack_a);
	printf("\n");
	print_stack_values(stack_b);
	printf("\n");
	printf("-----\n");
}

int check_if_ordered(t_node *stack_a)
{
	while (stack_a->next_node)
	{
		if (stack_a->number < stack_a->next_node->number)
		{
			stack_a = stack_a->next_node;
			continue;
		}
		else
		 	return (0);
	}
	return (1);
}

void free_stacks(t_stack_tuple *stacks)
{
	t_node *next_node;
	if (!stacks)
		return;

	while (stacks->stack_a)
	{
		next_node = stacks->stack_a->next_node;
		free(stacks->stack_a);
		stacks->stack_a = next_node;
	}
	while (stacks->stack_b)
	{
		next_node = stacks->stack_b->next_node;
		free(stacks->stack_b);
		stacks->stack_b = next_node;
	}
	free(stacks);
}

void free_stacks_separately(t_node *stack_a, t_node *stack_b)
{
	t_node *next_node;

	while (stack_a)
	{
		next_node = stack_a->next_node;
		free(stack_a);
		stack_a = next_node;
	}
	while (stack_b)
	{
		next_node = stack_b->next_node;
		free(stack_b);
		stack_b = next_node;
	}
}

//! ENSURE CORRECT MEMORY MANAGEMENT.
//! For example no ft_split malloc unfreed.
int main(int argc, char *argv[])
{
	// char **number_strings;
	t_number_strings number_strings;
	t_node *stack_a;
	t_node *stack_b;
	t_stack_tuple *stacks;

	if (!((number_strings = create_number_strings(argc, argv)).number_strings)) {
		return (1);
	}
	if (!(stack_a = create_stack_a(number_strings))) {
		return (1);
	}

	// print_stacks("START", stack_a, NULL);
	if (check_if_ordered(stack_a))
		return (free_stacks_separately(stack_a, NULL), 0);

	set_ordered_position(stack_a, get_list_len(stack_a));

	stack_b = NULL;
	stacks = split_stacks(stack_a, stack_b);
	// print_stacks("AFTER SPLIT", stacks->stack_a, stacks->stack_b);
	if (stacks->return_code == 0)
		return (free_stacks(stacks), 0);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	free(stacks);
	while (stack_b)
	{
		set_position(stack_a);
		set_position(stack_b);
		set_target(stack_a, stack_b);

		calculate_costs(stack_a, stack_b);
		set_total_cost(stack_b);
		t_node *node_to_move = select_node(stack_b);
		stacks = surface_nodes_and_push_a(stack_a, stack_b, node_to_move);
		stack_a = stacks->stack_a;
		stack_b = stacks->stack_b;
		free(stacks);
	}
	stack_a = rotate_until_ordered(stack_a);

	// print_stacks("AFTER ROTATION", stack_a, stack_b);

	// free_stacks(stacks);
	free_stacks_separately(stack_a, stack_b);
	return (0);
}