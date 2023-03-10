/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:59:45 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/13 15:14:18 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "colors.h"
# include "utils.h"
# include <math.h>

typedef struct s_fractal
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
	double			pr;
	double			pi;
	unsigned int	color;
	unsigned int	crange;
	int				max_iter;
	int				y;
	int				x;
	int				i;
	char			name;
}				t_fractal;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
}				t_image;

typedef struct s_box
{
	void		*mlx;
	void		*win;
	t_fractal	fractal;
	t_image		image;
}				t_box;

void	my_mlx_pyxel_put(t_image *image, int x, int y, int color);
void	init_fractal(t_box *box);
void	draw_julia(t_image *image, t_fractal *j);
void	draw_mandel(t_image *image, t_fractal *j);
void	draw_burning(t_image *image, t_fractal *j);
int		exit_hook(t_box *box);
int		key_hook(int key, t_box *box);
int		update(t_box *box);
void	init_img(t_box *box);

#endif
