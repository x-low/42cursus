/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:31:22 by xlow              #+#    #+#             */
/*   Updated: 2023/11/16 14:34:26 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	woopsies(void)
{
	ft_printf("Input parameters are incorrect!\n");
	ft_printf("Refer to supported formats as follows:\n");
	ft_printf("For Mandelbrot: Run program with 'mandelbrot'\n");
	ft_printf("For Julia: Run program with 'julia' ");
	ft_printf("followed by real and complex parts of C\n");
	exit(1);
}

void	explode(t_fractal *fractal)
{
	if (fractal->img_ptr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
}
