/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:19:44 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/08 17:15:38 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

void	my_mlx_pyxel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_lenght + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	init_julia(t_julia *julia)
{
	julia->max_iter = 300;
	julia->zoom = 1;
	julia->movex = 0;
	julia->movey = 0.05;
	julia->cre = -0.7;
	julia->cim = 0.27015;
}

void	draw_julia(t_image *image, t_julia *j)
{
	j->y = 0;
	while (j->y++ < 1080)
	{
		j->x = 0;
		while (j->x++ < 1920)
		{
			j->newre = 1.5 * (j->x - 1920 / 2)
				/ (0.5 * j->zoom * 1920) + j->movex;
			j->newim = (j->y - 1080 / 2) / (0.5 * j->zoom * 1080) + j->movey;
			j->i = 0;
			while (j->i++ < j->max_iter)
			{
				j->oldre = j->newre;
				j->oldim = j->newim;
				j->newre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
				j->newim = 2 * j->oldre * j->oldim + j->cim;
				if ((j->newre * j->newre + j->newim * j->newim) > 4)
					break ;
			}
			j->color = create_rgb(0, j->i % 256, 255 * (j->i < j->max_iter));
			my_mlx_pyxel_put(image, j->x, j->y, j->color);
		}
	}
}

int	key_hook(int key, t_box *box)
{
	ft_printf("Keypress: %i\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(box->mlx, box->win);
		exit(0);
	}
	if (key == 65362)
		box->julia.movey -= 0.05 / box->julia.zoom;
	if (key == 65361)
		box->julia.movex -= 0.05 / box->julia.zoom;
	if (key == 65364)
		box->julia.movey += 0.05 / box->julia.zoom;
	if (key == 65363)
		box->julia.movex += 0.05 / box->julia.zoom;
	if (key == 65453)
		box->julia.zoom /= 1.05;
	if (key == 65451)
		box->julia.zoom *= 1.05;
	if ((key >= 65361 && key <= 65364) || (key == 65453 || key == 65451))
	{
		draw_julia(&box->image, &box->julia);
		mlx_put_image_to_window(box->mlx, box->win, box->image.img, 0, 0);
	}
	return (0);
}

int	exit_hook(t_box *box)
{
	mlx_destroy_window(box->mlx, box->win);
	exit(0);
}

int	main(void)
{
	t_box	box;

	box.mlx = mlx_init();
	box.win = mlx_new_window(box.mlx, 1920, 1080, "fractol");
	box.image.img = mlx_new_image(box.mlx, 1920, 1080);
	box.image.addr = mlx_get_data_addr(box.image.img, &box.image.bits_per_pixel,
			&box.image.line_lenght, &box.image.endian);
	init_julia(&box.julia);
	draw_julia(&box.image, &box.julia);
	mlx_put_image_to_window(box.mlx, box.win, box.image.img, 0, 0);
	mlx_hook(box.win, 17, 0, exit_hook, &box);
	mlx_key_hook(box.win, key_hook, &box);
	mlx_loop(box.mlx);
	return (0);
}
