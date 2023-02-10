/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:49:27 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/10 13:24:13 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

int	create_rgb(int r, int g, int b, int m)
{
	return ((r + m) << 16 | (g + m) << 8 | (b + m));
}

int	hsvtorgb(float h, float s, float v)
{
	t_color	o;

	o.c = v * s;
	o.hprime = fmod(h / 60.0, 6);
	o.x = o.c * (1 - fabs(fmod(o.hprime, 2) - 1));
	o.m = v - o.c;
	if (0 <= o.hprime && o.hprime < 1)
		return (create_rgb(o.c, o.x, 0, o.m));
	else if (1 <= o.hprime && o.hprime < 2)
		return (create_rgb(o.x, o.c, 0, o.m));
	else if (2 <= o.hprime && o.hprime < 3)
		return (create_rgb(0, o.c, o.x, o.m));
	else if (3 <= o.hprime && o.hprime < 4)
		return (create_rgb(0, o.x, o.c, o.m));
	else if (4 <= o.hprime && o.hprime < 5)
		return (create_rgb(o.x, 0, o.c, o.m));
	else if (5 <= o.hprime && o.hprime < 6)
		return (create_rgb(o.c, 0, o.x, o.m));
	else
		return (create_rgb(0, 0, 0, o.m));
}
