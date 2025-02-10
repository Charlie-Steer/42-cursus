/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:49:32 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/05 13:56:20 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef ERROR_HANDLING_2_H
# define ERROR_HANDLING_2_H

void	terminate_program_heap_gd(t_game_data *gd, char *error_msg);
void	terminate_program_no_heap_gd(t_game_data gd, char *error_msg);

#endif
