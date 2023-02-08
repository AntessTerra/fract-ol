/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:59:45 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/08 13:48:50 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "colors.h"
# include <math.h>

typedef struct s_julia
{
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	unsigned int	color;
	int				max_iter;
	int				y;
	int				x;
	int				i;
}				t_julia;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_box
{
	void	*mlx;
	void	*win;
	t_julia	julia;
	t_image	image;
}				t_box;

int	create_rgb(int r, int g, int b);

#endif
