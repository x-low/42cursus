/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:01:30 by xlow              #+#    #+#             */
/*   Updated: 2023/11/16 15:02:29 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(double x, double y, t_fractal *fractal)
{
	int				i;
	unsigned int	colour;
	t_complex		z;
	t_complex		c;

	i = 0;
	c.re = (4 * x / 1000 - 2) * fractal->zoom;
	c.im = (-4 * y / 1000 + 2) * fractal->zoom;
	z.re = c.re;
	z.im = c.im;
	while (i < 200)
	{
		z = ft_polynomial_expansion(z);
		z = ft_add(z, c);
		if (z.re * z.re + z.im * z.im > 4)
		{
			colour = 0x76B041 * i / 50;
			draw_on_img(x, y, fractal, colour);
			return ;
		}
		i++;
	}
	draw_on_img(x, y, fractal, 0x76B041);
}

void	mandelbrot_fill(t_fractal *fractal)
{
	double	x;
	double	y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			mandelbrot(x, y, fractal);
			y++;
		}
		x++;
	}
}
