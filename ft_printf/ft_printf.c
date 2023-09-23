/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 04:39:10 by xlow              #+#    #+#             */
/*   Updated: 2023/09/21 13:25:23 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	checkplaceholder(const char *str, va_list *args, int *count)
{
	char	c;

	if (*str == 'c')
	{
		c = va_arg(*args, int);
		*count += write(1, &c, 1);
	}
	if (*str == 's')
		ft_putstr(va_arg(*args, char *), count);
	if (*str == 'p')
		ft_puthex(va_arg(*args, void *), count);
	if (*str == 'd' || *str == 'i')
		ft_putint(va_arg(*args, int), count);
	if (*str == 'u')
		ft_putuint(va_arg(*args, unsigned int), count);
	if (*str == 'x')
		ft_dectohex(va_arg(*args, int), "0123456789abcdef", count);
	if (*str == 'X')
		ft_dectohex(va_arg(*args, int), "0123456789ABCDEF", count);
	if (*str == '%')
		*count += write(1, "%", 1);
}

void	ft_ulldectohex(unsigned long long number, char *base, int *count)
{
	if (number > 15)
		ft_ulldectohex(number / 16, base, count);
	*count += write(1, &base[number % 16], 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			checkplaceholder(&str[i + 1], &args, &count);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
