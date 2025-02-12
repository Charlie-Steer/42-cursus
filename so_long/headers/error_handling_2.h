/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:49:32 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/12 16:08:32 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_2_H
# define ERROR_HANDLING_2_H

# include "so_long.h"

void	terminate_program_heap_gd(t_game_data *gd, char *error_msg);
void	terminate_program_no_heap_gd(t_game_data gd, char *error_msg);

#endif
