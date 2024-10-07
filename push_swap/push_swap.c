/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:52 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/07 20:11:17 by cargonz2         ###   ########.fr       */
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
		ft_printf("Error: invalid argument count.\n");

	char **number_strings = ft_split(argv[1], ' ');
	char **number_array = ft_calloc(number_of_strings(number_strings), sizeof(int));
	if (!number_array)
		return (1);

	int	i = 0;
	while (number_strings[i])
	{
		int *number = ft_calloc(1, sizeof(int));
		if (!number)
			return (1); //! Should free all allocated numbers so far.

		*number = ft_atoi(number_strings[i]);
		ft_lstnew((void *)number);
		i++;
	}
	argv[1];

	return (0);
}