/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:20:53 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/10 11:43:15 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_atof
{
	float	val;
	int		afterdot;
	float	scale;
	int		sign;
}				t_atof;

float	ft_atof(char *str);

#endif
