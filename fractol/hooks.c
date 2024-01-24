/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:58:22 by xlow              #+#    #+#             */
/*   Updated: 2023/11/16 14:58:30 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_button(t_fractal *fractal)
{
	explode(fractal);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		fractal->zoom *= 0.9;
	if (mousecode == 5)
		fractal->zoom *= 1.1;
	fractal_selection(fractal->type, fractal);
	return (0);
}

int	key_hook(int keysym, t_fractal *fractal)
{
	if (keysym == 65307)
		explode(fractal);
	return (0);
}
