/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:44:53 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/03 19:48:28 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef SETUP_H
# define SETUP_H

mlx_t		*init_mlx(t_game_data game_data);
void		create_background(t_game_data game_data);
t_images	create_images(mlx_t *mlx);
void		resize_images(t_game_data game_data);

#endif
