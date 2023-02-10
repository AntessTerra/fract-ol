/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:18:54 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/10 11:49:34 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

void	init_atof(t_atof *a)
{
	a->afterdot = 0;
	a->sign = 1;
	a->scale = 1;
	a->val = 0;
}

void	more_atof(t_atof *a, char *str)
{
	if (a->afterdot)
	{
		a->scale /= 10;
		a->val = a->val + (*str - '0') * a->scale;
	}
	else
	{
		if (*str == '.')
			a->afterdot++;
		else
			a->val = a->val * 10.0 + (*str - '0');
	}
}

float	ft_atof(char *str)
{
	t_atof	a;

	init_atof(&a);
	while (*str <= ' ' && *str != '\e')
		str++;
	if (*str == '-')
	{
		str++;
		a.sign *= -1;
	}
	while (*str)
	{
		more_atof(&a, str);
		str++;
	}
	return (a.val * a.sign);
}
