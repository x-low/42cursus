/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:43:49 by xlow              #+#    #+#             */
/*   Updated: 2024/04/18 21:43:56 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
	{
		res *= 10;
		res += (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

static int	ft_isnumber(const char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (!(ptr[i] >= '0' && ptr[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	assign_arg(char *argv)
{
	long	res;

	if (!ft_isnumber(argv))
		return (-2);
	res = ft_atol(argv);
	if (res < 0 || res > 2147483647)
		return (-2);
	return (res);
}

t_args	process_args(int argc, char **argv)
{
	t_args	args;

	args.meals = -1;
	if (argc != 5 && argc != 6)
	{
		args.meals = -2;
		return (args);
	}
	args.diners = assign_arg(argv[1]);
	args.ttd = assign_arg(argv[2]);
	args.tte = assign_arg(argv[3]);
	args.tts = assign_arg(argv[4]);
	if (args.diners == -2 || args.ttd == -2
		|| args.tte == -2 || args.tts == -2 || !args.diners)
		args.meals = -2;
	if (args.meals == -2)
		return (args);
	if (argc == 6)
		args.meals = assign_arg(argv[5]);
	return (args);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	t	_args	args;

	args = process_args(argc, argv);
	printf("%d\n", args.diners);
	printf("%d\n", args.ttd);
	printf("%d\n", args.tte);
	printf("%d\n", args.tts);
	printf("%d\n", args.meals);
	if (args.meals == -2)
	{
		printf("huh?\n");
		return (-1);
	}
	return (0);
}
*/
