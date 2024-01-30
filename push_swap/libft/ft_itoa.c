/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:03:02 by xlow              #+#    #+#             */
/*   Updated: 2023/09/14 21:46:56 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static int	ft_offset(long n, int len)
{
	len--;
	while (len)
	{
		n = n / 10;
		len--;
	}
	return (n % 10);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	long	num;
	char	*res;

	num = n;
	i = 0;
	len = ft_numlen(num);
	res = malloc(len + 1);
	if (!res)
		return (0);
	if (num < 0)
	{
		res[i++] = '-';
		num = -num;
		len--;
	}
	while (len)
		res[i++] = ft_offset(num, len--) + 48;
	res[i] = '\0';
	return (res);
}
