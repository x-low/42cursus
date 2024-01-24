/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:38:27 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 18:47:58 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(double x, double y, t_fractal *fractal)
{
	int				i;
	unsigned int	colour;
	t_complex		z;
	t_complex		c;

	i = 0;
	z.re = (4 * x / 1000 - 2) * fractal->zoom;
	z.im = (-4 * y / 1000 + 2) * fractal->zoom;
	c.re = fractal->c_re;
	c.im = fractal->c_im;
	while (i < 100)
	{
		z = ft_polynomial_expansion(z);
		z = ft_add(z, c);
		if (z.re * z.re + z.im * z.im > 4)
		{
			colour = 0xE63946 * i / 10000;
			draw_on_img(x, y, fractal, colour);
			return ;
		}
		i++;
	}
	draw_on_img(x, y, fractal, 0xE63946);
}

void	julia_fill(t_fractal *fractal)
{
	double	x;
	double	y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			julia(x, y, fractal);
			y++;
		}
		x++;
	}
}
