/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:24:51 by cargonz2          #+#    #+#             */
/*   Updated: 2025/01/31 14:30:09 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSING_H
# define MAP_PARSING_H
# include "so_long.h"

t_game_data	record_map_character(char c, t_game_data map_data, char **map,
				t_position coords);
void		ensure_surrounded_by_walls(t_game_data game_data);
void		flood_fill(char **map, int x_pos, int y_pos);
void		check_if_valid_path(char **map, int cols, int rows,
				char **other_map);
char		**clone_map(char **map, int cols, int rows);

#endif
