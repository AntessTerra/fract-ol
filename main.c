/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:19:44 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/09 15:56:53 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

/*	Todo:
	- HSV to RGB colors ALMOST
	- One more fractal
	- Follow zoom aftem mouse cursor
	- Redo atof!!!
*/

void	my_mlx_pyxel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->ll + x
			* (image->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	init_img(t_box *box)
{
	box->image.img = mlx_new_image(box->mlx, 1920, 1080);
	box->image.addr = mlx_get_data_addr(box->image.img, &box->image.bpp,
			&box->image.ll, &box->image.end);
}

int	check_arguments(t_box *box, int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc == 2 && argv[1][0] == 'M')
		{
			init_fractal(box);
			return (1);
		}
		else if (argv[1][0] == 'J' && argc >= 2 && argc <= 4)
		{
			init_fractal(box);
			if (argc == 3)
				box->fractal.cre = atof(argv[2]);
			else if (argc == 4)
			{
				box->fractal.cre = atof(argv[2]);
				box->fractal.cim = atof(argv[3]);
			}
			return (1);
		}
	}
	ft_printf("%s\n%s\n%s",
		"Invalid or no arguments. Please try with [J] or [M].",
		"For [J] you can add params for different looks.",
		"Try: ./fractol J -0.77097 -0.085 or ./fractol J -0.65488 -0.4477");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_box	box;

	if (check_arguments(&box, argc, argv))
	{
		box.mlx = mlx_init();
		box.win = mlx_new_window(box.mlx, 1920, 1080, "fractol");
		init_img(&box);
		box.fractal.name = argv[1][0];
		if (box.fractal.name == 'J')
			draw_julia(&box.image, &box.fractal);
		else if (box.fractal.name == 'M')
			draw_mandel(&box.image, &box.fractal);
		mlx_put_image_to_window(box.mlx, box.win, box.image.img, 0, 0);
		mlx_hook(box.win, 17, 0, exit_hook, &box);
		mlx_key_hook(box.win, key_hook, &box);
		mlx_loop_hook(box.mlx, update, &box);
		mlx_loop(box.mlx);
	}
	return (0);
}
