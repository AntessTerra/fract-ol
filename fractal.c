/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:45:14 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/09 14:17:04 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

void	init_fractal(t_box *box)
{
	box->fractal.max_iter = 300;
	box->fractal.zoom = 1;
	box->fractal.movex = 0;
	box->fractal.movey = 0.05;
	box->fractal.cre = -0.7;
	box->fractal.cim = 0.27015;
}

void	null_re_im(t_fractal *f)
{
	f->newre = 0;
	f->newim = 0;
	f->oldre = 0;
	f->oldim = 0;
}

void	draw_julia(t_image *image, t_fractal *j)
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
			j->color = hsvtorgb(j->i % 256, 255, 255 * (j->i < j->max_iter));
			my_mlx_pyxel_put(image, j->x, j->y, j->color);
		}
	}
}

void	draw_mandel(t_image *image, t_fractal *j)
{
	j->y = 0;
	while (j->y++ < 1080)
	{
		j->x = 0;
		while (j->x++ < 1920)
		{
			j->pr = 1.5 * (j->x - 1920 / 2)
				/ (0.5 * j->zoom * 1920) + j->movex;
			j->pi = (j->y - 1080 / 2) / (0.5 * j->zoom * 1080) + j->movey;
			null_re_im(j);
			j->i = 0;
			while (j->i++ < j->max_iter)
			{
				j->oldre = j->newre;
				j->oldim = j->newim;
				j->newre = j->oldre * j->oldre - j->oldim * j->oldim + j->pr;
				j->newim = 2 * j->oldre * j->oldim + j->pi;
				if ((j->newre * j->newre + j->newim * j->newim) > 4)
					break ;
			}
			j->color = hsvtorgb(j->i % 256, 255, 255 * (j->i < j->max_iter));
			my_mlx_pyxel_put(image, j->x, j->y, j->color);
		}
	}
}
