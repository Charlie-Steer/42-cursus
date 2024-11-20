/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/20 10:50:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (check_if_valid_arguments(argc, argv))
	{
		t_two_ints width_and_height = get_map_len(argv[1]);
		ft_printf("%d, %d\n", width_and_height.a, width_and_height.b);
		char **map = save_map(argv[1], width_and_height.a, width_and_height.b);

		#if DEBUG == 1 //! DELETE
			DEBUG_print_map(map, width_and_height.a, width_and_height.b);
		#endif

		validate_map_and_store_map_data(map, width_and_height.a, width_and_height.b);
	}
}