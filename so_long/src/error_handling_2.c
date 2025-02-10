/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:12:36 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 15:57:09 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling_1.h"
#include "so_long.h"

void	terminate_program_heap_gd(t_game_data *gd, char *error_msg)
{
	bool	error_msg_exists;

	error_msg_exists = (error_msg != NULL && *error_msg != '\0');
	if (error_msg_exists)
		print_error(error_msg);
	if (gd)
	{
		if (gd->map)
			free_map(gd->map, gd->rows);
		if (gd->mlx)
			mlx_terminate(gd->mlx);
		free(gd);
	}
	if (error_msg_exists)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	terminate_program_no_heap_gd(t_game_data gd, char *error_msg)
{
	bool	error_msg_exists;

	error_msg_exists = (error_msg != NULL && *error_msg != '\0');
	if (error_msg_exists)
		print_error(error_msg);
	if (gd.map)
		free_map(gd.map, gd.rows);
	if (gd.mlx)
		mlx_terminate(gd.mlx);
	if (error_msg_exists)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
