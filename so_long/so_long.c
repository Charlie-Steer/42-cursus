/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:10:19 by cargonz2          #+#    #+#             */
/*   Updated: 2024/11/25 12:35:47 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	if (check_if_valid_arguments(argc, argv))
	{
		t_two_ints width_and_height = get_map_len(argv[1]);
		#if DEBUG >= 1 //! DELETE
			ft_printf("width: %d\nheight: %d\n\n", width_and_height.a, width_and_height.b);
		#endif
		char **map = save_map(argv[1], width_and_height.a, width_and_height.b);

		#if DEBUG >= 1 //! DELETE
			DEBUG_print_map(map, width_and_height.a, width_and_height.b);
		#endif

		validate_map_and_store_map_data(map, width_and_height.a, width_and_height.b);

		// MLX
		mlx_t *mlx = mlx_init(1920, 1080, "My project", 1);
		if (!mlx) {
			print_error("Error on mlx_init");
		}
		ft_printf("w: %d, h: %d\n", mlx->width, mlx->height);
		int width = mlx->width;
		int height = mlx->height;
		mlx_image_t* img = mlx_new_image(mlx, width, height);
		// if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		// 	ft_error();
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				mlx_put_pixel(img, x, y, 0xFF00FFFF);
			}
		}
		ft_printf("After writing to image.\n");
		mlx_image_to_window(mlx, img, 0, 0);
		ft_printf("After displaying on window.\n");
		mlx_loop(mlx);
		ft_printf("After loop.\n");
		mlx_terminate(mlx);
		ft_printf("After terminate.\n");
	}
}