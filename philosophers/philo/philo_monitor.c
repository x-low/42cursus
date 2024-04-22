/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:34:11 by xlow              #+#    #+#             */
/*   Updated: 2024/04/18 21:36:13 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	everyones_full(t_args args, t_philo *philos)
{
	int	i;

	i = -1;
	if (args.meals > -1)
	{
		while (++i < args.diners)
		{
			pthread_mutex_lock(&philos[i].belly->full_lock);
			if (!philos[i].belly->full)
			{
				pthread_mutex_unlock(&philos[i].belly->full_lock);
				return (0);
			}
			pthread_mutex_unlock(&philos[i].belly->full_lock);
		}
	}
	else
		return (0);
	return (1);
}

static int	someone_died(t_args args, t_philo *philos, t_print *printing)
{
	int	i;

	i = -1;
	while (++i < args.diners)
	{
		pthread_mutex_lock(&philos[i].ate_lock);
		if (time_now() - philos[i].last_ate >= (unsigned long long)args.ttd)
		{
			pthread_mutex_unlock(&philos[i].ate_lock);
			pthread_mutex_lock(&printing->stop_lock);
			printing->stop = 1;
			pthread_mutex_unlock(&printing->stop_lock);
			pthread_mutex_lock(&printing->print_lock);
			printf("%lld %d died\n", time_now() - philos[i].start_time,
				philos[i].id);
			pthread_mutex_unlock(&printing->print_lock);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].ate_lock);
	}
	return (0);
}

void	monitoring(t_args args, t_philo *philos, t_print *printing)
{
	while (1)
	{
		if (everyones_full(args, philos))
		{
			pthread_mutex_lock(&printing->stop_lock);
			printing->stop = 1;
			pthread_mutex_unlock(&printing->stop_lock);
			return ;
		}
		if (someone_died(args, philos, printing))
			return ;
	}
}

void	cleanup(t_args args, t_philo *philos, t_table *table, t_print *print)
{
	int	i;

	i = -1;
	while (++i < args.diners)
		pthread_join(philos[i].tid, NULL);
	free(table->forks);
	i = -1;
	while (++i < args.diners)
		pthread_mutex_destroy(&table->fork_lock[i]);
	free(table->fork_lock);
	pthread_mutex_destroy(&print->stop_lock);
	pthread_mutex_destroy(&print->print_lock);
	i = -1;
	while (++i < args.diners)
		pthread_mutex_destroy(&philos[i].ate_lock);
	i = -1;
	while (++i < args.diners)
		pthread_mutex_destroy(&table->belly[i].full_lock);
	free(table->belly);
	free(philos);
}
