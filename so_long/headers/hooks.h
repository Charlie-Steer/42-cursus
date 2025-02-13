/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:37:19 by cargonz2          #+#    #+#             */
/*   Updated: 2025/02/12 20:07:15 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "so_long.h"

void	check_and_pick_up_collectibles(void *param);
void	move_player(t_game_data *game_data, enum e_direction direction);
void	my_key_hook(mlx_key_data_t key_data, void *param);

#endif
