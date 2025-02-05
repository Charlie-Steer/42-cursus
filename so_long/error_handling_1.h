/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_1.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:51:34 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 13:52:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_1_H
# define ERROR_HANDLING_1_H
# include "so_long.h"

void	print_error(char *error_message);
void	free_map(char **map, int rows);
void	print_error_and_exit(char *error_message);
void	print_error_free_map_and_exit(char *error_message, char **map,
			int rows);
void	print_error_free_maps_and_exit(char *error_message, char **map1,
			char **map2, int rows);

#endif
