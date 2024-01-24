/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:13:03 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 19:54:57 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi_with_counter(const char *nptr, int *i, int *sign)
{
	int	res;

	res = 0;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while ((nptr[*i] >= '0' && nptr[*i] <= '9') && nptr[*i])
	{
		res *= 10;
		res += (nptr[*i] - '0');
		(*i)++;
	}
	return (res);
}

double	ft_atof(const char *s)
{
	int		i;
	int		sign;
	double	res;
	double	dp;

	sign = 1;
	i = 0;
	dp = 1;
	res = atoi_with_counter(s, &i, &sign);
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			dp /= 10;
			res += (s[i] - 48) * dp;
			i++;
		}
	}
	return (res * sign);
}
