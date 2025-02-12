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

#include "libft.h"
#include "so_long.h"

bool	has_valid_extension(char *path)
{
	int	len;

	len = strlen(path);
	if (len < 4)
		return (false);
	if (path[len - 4] == '.' && path[len - 3] == 'b' && path[len - 2] == 'e'
		&& path[len - 1] == 'r')
		return (true);
	else
		return (false);
}

int	check_if_valid_arguments(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (has_valid_extension(argv[1]))
			return (1);
		else
			ft_putstr_fd("Error\nInvalid map file extension."
				"Please provide a \".ber\" file.\n",
				STDERR_FILENO);
	}
	else if (argc < 2)
		ft_putstr_fd("Error\n"
			"Please provide a valid path for a map file as an argument.\n",
			STDERR_FILENO);
	else if (argc > 2)
		ft_putstr_fd("Error\nToo many arguments!\n", STDERR_FILENO);
	return (0);
}
