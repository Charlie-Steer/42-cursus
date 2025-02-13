/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:44:53 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/13 17:33:14 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "so_long.h"

mlx_t		*init_mlx(t_game_data game_data);
void		create_background(t_game_data game_data);
t_textures	create_textures(t_game_data gd);
t_images	create_images(t_game_data gd);
void		resize_images(t_game_data game_data);

#endif
