/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:01:58 by xlow              #+#    #+#             */
/*   Updated: 2024/04/22 15:54:45 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_table	table;
	t_print	print;
	t_philo	*philos;

	args = process_args(argc, argv);
	if (args.meals == -2)
		return (printf("Invalid arguments\n"));
	if (!args.meals)
		return (0);
	if (args.diners == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(args.ttd * 1000);
		printf("%d 1 has died\n", args.ttd);
		return (0);
	}
	if (!init_mutex_structs(args, &table, &print))
		return (1);
	philos = init_philos(args, &table, &print);
	monitoring(args, philos, &print);
	cleanup(args, philos, &table, &print);
	return (0);
}
