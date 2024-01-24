/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:29 by xlow              #+#    #+#             */
/*   Updated: 2023/11/16 14:57:48 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_selection(int type, t_fractal *fractal)
{
	if (fractal->img_ptr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, 1000, 1000);
	fractal->img_addr = mlx_get_data_addr(fractal->img_ptr, &fractal->bpp,
			&fractal->line_len, &fractal->endian);
	if (type == 1)
		mandelbrot_fill(fractal);
	if (type == 2)
		julia_fill(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr,
		fractal->img_ptr, 0, 0);
}

void	draw_on_img(double x, double y, t_fractal *fractal, unsigned int colour)
{
	unsigned int	byte_offset;

	byte_offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->img_addr + byte_offset) = colour;
}

int	type_assignment(int argc, char **argv, t_fractal *fractal)
{
	int	type;

	type = 0;
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			type = 1;
	}
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal->c_re = ft_atof(argv[2]);
		fractal->c_im = ft_atof(argv[3]);
		type = 2;
	}
	fractal->zoom = 1;
	return (type);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal.type = type_assignment(argc, argv, &fractal);
	if (fractal.type)
	{
		fractal.mlx_ptr = mlx_init();
		fractal.window_ptr = mlx_new_window(fractal.mlx_ptr,
				1000, 1000, "fractol");
		fractal.img_ptr = mlx_new_image(fractal.mlx_ptr, 1000, 1000);
		fractal_selection(fractal.type, &fractal);
		mlx_key_hook(fractal.window_ptr, key_hook, &fractal);
		mlx_mouse_hook(fractal.window_ptr, mouse_hook, &fractal);
		mlx_hook(fractal.window_ptr, 17, 1L << 17, exit_button, &fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		woopsies();
}
