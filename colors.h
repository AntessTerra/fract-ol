/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:04:25 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/09 12:09:01 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff

typedef struct s_color
{
	double	f;
	double	p;
	double	q;
	double	t;
	int		i;
	float	c;
	float	hprime;
	float	x;
	float	m;
}				t_color;

int	hsvtorgb(float h, float s, float v);

#endif
