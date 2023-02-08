/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:40:25 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/08 20:14:04 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

void	help(t_box *box)
{
	mlx_string_put(box->mlx, box->win, 25, 25, WHITE,
		"Helping now :D.");
}

void	help_backgroud(t_box *box)
{
	if (!box->menu)
		mlx_string_put(box->mlx, box->win, 25, 25, WHITE,
			"Press H for help");
	else if (box->menu)
		help(box);
}
