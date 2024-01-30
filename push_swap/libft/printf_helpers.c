/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:58:50 by xlow              #+#    #+#             */
/*   Updated: 2023/09/23 20:50:53 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putint(int number, int *count)
{
	char	c;
	long	nombor;

	nombor = number;
	if (nombor < 0)
	{
		*count += write(1, "-", 1);
		nombor *= -1;
	}
	if (nombor > 9)
		ft_putint(nombor / 10, count);
	c = nombor % 10 + 48;
	*count += write(1, &c, 1);
}

void	ft_putuint(unsigned int number, int *count)
{
	char	c;

	if (number > 9)
		ft_putuint(number / 10, count);
	c = number % 10 + 48;
	*count += write(1, &c, 1);
}

void	ft_puthex(void *ptr, int *count)
{
	if (!ptr)
		*count += write(1, "(nil)", 5);
	else
	{
		*count += write(1, "0x", 2);
		ft_ulldectohex((unsigned long long)ptr, "0123456789abcdef", count);
	}
}

void	ft_dectohex(unsigned int number, char *base, int *count)
{
	if (number > 15)
		ft_dectohex(number / 16, base, count);
	*count += write(1, &base[number % 16], 1);
}
