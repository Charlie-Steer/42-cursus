/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:19:55 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/20 08:20:11 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_if_valid_arguments(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			return (1);
		else
		 	ft_putstr_fd("Error\nInvalid map file extension. Please provide a \".ber\" file.\n", STDERR_FILENO);
	}
	else if (argc < 2)
	{
		ft_putstr_fd("Error\nPlease provide a valid path for a map file as an argument.\n", STDERR_FILENO);
		exit(1);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments!\n", STDERR_FILENO);
		exit(1);
	}
	else
		assert(0);
	return (0);
}