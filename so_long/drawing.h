/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:31:55 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/04 20:32:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H
# include "so_long.h"

void	draw_terrain_and_wall_tiles(t_images images, t_game_data gd);
void	draw_player_and_collectible_tiles(t_images images, t_game_data gd);

#endif
