/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:19:44 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/07 16:20:28 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "fractol.h"

int	deal_key(int key, t_box *box)
{
	ft_printf("Keypress: %i\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(box->mlx, box->win);
		exit(0);
	}
	return (0);
}

void	my_mlx_pyxel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_lenght + x * (image->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	main(void)
{
	t_box	box;
	t_image	image;


	box.mlx = mlx_init();
	box.win = mlx_new_window(box.mlx, 1920, 1080, "fractol");
	//image.img = mlx_new_image(box.mlx, 1920, 1080);
	//image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_lenght, &image.endian);
	//my_mlx_pyxel_put(&image, 5, 5, WHITE);
	image.img = mlx_xpm_file_to_image(box.mlx, "dog.xpm", &image.img_width, &image.img_height);
	mlx_put_image_to_window(box.mlx, box.win, image.img, 800, 300);
	mlx_key_hook(box.win, deal_key, &box);
	mlx_loop(box.mlx);
	return (0);
}
