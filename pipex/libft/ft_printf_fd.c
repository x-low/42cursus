/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 04:39:10 by xlow              #+#    #+#             */
/*   Updated: 2024/02/08 21:55:23 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	placeholder(int fd, const char *str, va_list *args, int *count)
{
	char	c;

	if (*str == 'c')
	{
		c = va_arg(*args, int);
		*count += write(fd, &c, 1);
	}
	if (*str == 's')
		pf_fd_putstr(fd, va_arg(*args, char *), count);
	if (*str == 'p')
		pf_fd_puthex(fd, va_arg(*args, void *), count);
	if (*str == 'd' || *str == 'i')
		pf_fd_putint(fd, va_arg(*args, int), count);
	if (*str == 'u')
		pf_fd_putuint(fd, va_arg(*args, unsigned int), count);
	if (*str == 'x')
		pf_fd_dectohex(fd, va_arg(*args, int), "0123456789abcdef", count);
	if (*str == 'X')
		pf_fd_dectohex(fd, va_arg(*args, int), "0123456789ABCDEF", count);
	if (*str == '%')
		*count += write(fd, "%", 1);
}

void	pf_fd_ullhex(int fd, unsigned long long num, char *base, int *count)
{
	if (num > 15)
		pf_fd_ullhex(fd, num / 16, base, count);
	*count += write(fd, &base[num % 16], 1);
}

int	ft_printf_fd(int fd, const char *str, ...)
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
			placeholder(fd, &str[i + 1], &args, &count);
			i++;
		}
		else
			count += write(fd, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
