/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:02:41 by xlow              #+#    #+#             */
/*   Updated: 2023/11/16 15:03:13 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_complex	ft_polynomial_expansion(t_complex a)
{
	t_complex	b;

	b.re = a.re * a.re - a.im * a.im;
	b.im = 2 * a.re * a.im;
	return (b);
}
