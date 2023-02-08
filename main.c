/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:19:44 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/08 20:44:12 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

/*	Todo:
	- HSV to RGB colors
	- Parameters in command line (name of fractal, parameters)
	- One more fractal
	- Follow zoom aftem mouse cursor
	- Display help and info on screen
		- Includes figuring out how to update images
*/

void	my_mlx_pyxel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->ll + x
			* (image->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	main(int argc, char **argv)
{
	t_box	box;

	box.menu = 0;
	if (argc == 2)
	{
		box.mlx = mlx_init();
		box.win = mlx_new_window(box.mlx, 1920, 1080, "fractol");
		box.image.img = mlx_new_image(box.mlx, 1920, 1080);
		box.image.addr = mlx_get_data_addr(box.image.img, &box.image.bpp,
				&box.image.ll, &box.image.end);
		init_fractal(&box);
		box.fractal.name = argv[1][0];
		mlx_put_image_to_window(box.mlx, box.win, box.image.img, 0, 0);
		mlx_hook(box.win, 17, 0, exit_hook, &box);
		mlx_key_hook(box.win, key_hook, &box);
		mlx_loop_hook(box.mlx, update, &box);
		mlx_loop(box.mlx);
	}
	return (0);
}
