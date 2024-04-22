/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:58:50 by xlow              #+#    #+#             */
/*   Updated: 2024/02/08 21:56:25 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_fd_putstr(int fd, char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count += write(fd, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*count += write(fd, &str[i], 1);
		i++;
	}
}

void	pf_fd_putint(int fd, int number, int *count)
{
	char	c;
	long	nombor;

	nombor = number;
	if (nombor < 0)
	{
		*count += write(fd, "-", 1);
		nombor *= -1;
	}
	if (nombor > 9)
		pf_fd_putint(fd, nombor / 10, count);
	c = nombor % 10 + 48;
	*count += write(fd, &c, 1);
}

void	pf_fd_putuint(int fd, unsigned int number, int *count)
{
	char	c;

	if (number > 9)
		pf_fd_putuint(fd, number / 10, count);
	c = number % 10 + 48;
	*count += write(fd, &c, 1);
}

void	pf_fd_puthex(int fd, void *ptr, int *count)
{
	if (!ptr)
		*count += write(fd, "(nil)", 5);
	else
	{
		*count += write(fd, "0x", 2);
		pf_fd_ullhex(fd, (unsigned long long)ptr, "0123456789abcdef", count);
	}
}

void	pf_fd_dectohex(int fd, unsigned int number, char *base, int *count)
{
	if (number > 15)
		pf_fd_dectohex(fd, number / 16, base, count);
	*count += write(fd, &base[number % 16], 1);
}
