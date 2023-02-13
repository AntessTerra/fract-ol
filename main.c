/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:19:44 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/13 15:35:56 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

/*	Todo:
	- One more fractal
	- Follow zoom aftem mouse cursor
*/

int	invalid_args(void)
{
	ft_printf("%s\n%s\n%s\n%s\n%s",
		"Invalid or no arguments ./fractol <type> <optoins>",
		"Options: 	J <colorshift> <cReal> <cImaginary>",
		"		M <colorshift>",
		"		B <colorshift>",
		"Try: ./fractol J -0.77097 -0.085 or ./fractol J -0.65488 -0.4477");
	exit(0);
}

int	check_arguments(t_box *box, int argc, char **argv)
{
	if (argc > 1)
	{
		init_fractal(box);
		if ((argc == 2 || argc == 3) && (argv[1][0] == 'M'
			|| argv[1][0] == 'B'))
		{
			if (argc == 3)
				box->fractal.crange = ft_atoi(argv[2]);
			return (1);
		}
		else if (argv[1][0] == 'J' && argc >= 2 && argc <= 5)
		{
			if (argc == 3 || argc == 5)
				box->fractal.crange = ft_atoi(argv[2]);
			if (argc == 5 || argc == 4)
			{
				box->fractal.cre = ft_atof(argv[argc - 2]);
				box->fractal.cim = ft_atof(argv[argc - 1]);
			}
			return (1);
		}
	}
	return (invalid_args());
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
		else if (box.fractal.name == 'B')
			draw_burning(&box.image, &box.fractal);
		mlx_put_image_to_window(box.mlx, box.win, box.image.img, 0, 0);
		mlx_hook(box.win, 17, 0, exit_hook, &box);
		mlx_key_hook(box.win, key_hook, &box);
		mlx_loop_hook(box.mlx, update, &box);
		mlx_loop(box.mlx);
	}
	return (0);
}
