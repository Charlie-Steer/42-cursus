/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:11:39 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/19 15:36:39 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "MLX42.h"
#include "libft/libft.h"
#include "fcntl.h"
#include "stdio.h"
#include <assert.h>
#include <stdbool.h>

typedef struct s_two_ints {
	int a;
	int b;
} t_two_ints;

typedef struct s_map_data {
	int width;
	int height;

	int player_amount;
	int exit_amount;
	int collectible_amount;
} t_map_data;

#endif
