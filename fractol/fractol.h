/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:36 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 15:42:00 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	c_re;
	double	c_im;
	double	zoom;
	int		type;
}				t_fractal;

void		fractal_selection(int type, t_fractal *fractal);
void		woopsies(void);
t_complex	ft_add(t_complex a, t_complex b);
t_complex	ft_polynomial_expansion(t_complex a);
void		mandelbrot_fill(t_fractal *fractal);
void		mandelbrot(double x, double y, t_fractal *fractal);
void		draw_on_img(double x, double y,
				t_fractal *fractal, unsigned int color);
void		julia(double x, double y, t_fractal *fractal);
void		julia_fill(t_fractal *fractal);
int			type_assignment(int argc, char **argv, t_fractal *fractal);
void		explode(t_fractal	*fractal);
double		prandom_number_generator(unsigned int seed);
int			exit_button(t_fractal *fractal);
int			mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int			key_hook(int keysym, t_fractal *fractal);

#endif
