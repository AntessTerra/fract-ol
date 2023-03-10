/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:52:55 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/13 15:16:04 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

int	key_hook(int key, t_box *box)
{
	if (key == 65307)
	{
		mlx_destroy_window(box->mlx, box->win);
		exit(0);
	}
	if (key == 65362)
		box->fractal.movey -= 0.05 / box->fractal.zoom;
	if (key == 65361)
		box->fractal.movex -= 0.05 / box->fractal.zoom;
	if (key == 65364)
		box->fractal.movey += 0.05 / box->fractal.zoom;
	if (key == 65363)
		box->fractal.movex += 0.05 / box->fractal.zoom;
	if (key == 65453)
		box->fractal.zoom /= 1.05;
	if (key == 65451)
		box->fractal.zoom *= 1.05;
	update(box);
	return (0);
}

int	exit_hook(t_box *box)
{
	mlx_destroy_window(box->mlx, box->win);
	exit(0);
}

int	update(t_box *box)
{
	mlx_destroy_image(box->mlx, box->image.img);
	init_img(box);
	if (box->fractal.name == 'J')
		draw_julia(&box->image, &box->fractal);
	else if (box->fractal.name == 'M')
		draw_mandel(&box->image, &box->fractal);
	else if (box->fractal.name == 'B')
		draw_burning(&box->image, &box->fractal);
	mlx_put_image_to_window(box->mlx, box->win, box->image.img, 0, 0);
	return (0);
}
