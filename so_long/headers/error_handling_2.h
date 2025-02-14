/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:49:32 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/14 14:03:07 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_2_H
# define ERROR_HANDLING_2_H

# include "so_long.h"

void	free_textures(t_textures textures);
void	terminate_program_heap_gd(t_game_data *gd, char *error_msg);
void	terminate_program_no_heap_gd(t_game_data gd, char *error_msg);
void	close_file_print_error_and_exit(int map_fd, char *error_message);

#endif
