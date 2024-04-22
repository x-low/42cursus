/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:43:54 by xlow              #+#    #+#             */
/*   Updated: 2024/04/18 20:39:55 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	while (size > 0)
	{
		((unsigned char *)res)[size - 1] = '\0';
		size--;
	}
	return (res);
}

int	init_mutex_structs(t_args args, t_table *table, t_print *print)
{
	int	i;

	i = 0;
	table->forks = ft_calloc(args.diners, sizeof(int));
	if (!table->forks)
		return (0);
	table->fork_lock = ft_calloc(args.diners, sizeof(pthread_mutex_t));
	if (!table->fork_lock)
	{
		free(table->forks);
		return (0);
	}
	print->stop = 0;
	pthread_mutex_init(&print->stop_lock, NULL);
	pthread_mutex_init(&print->print_lock, NULL);
	while (i < args.diners)
	{
		table->forks[i] = 0;
		pthread_mutex_init(&table->fork_lock[i], NULL);
		i++;
	}
	table->belly = ft_calloc(args.diners, sizeof(t_full));
	return (1);
}

static t_philo	*create_philos(t_args args, t_philo *philo, t_table *table)
{
	int		i;

	i = -1;
	while (++i < args.diners)
	{
		if (!(i % 2))
		{
			philo[i].fork_lock[0] = &table->fork_lock[(i + 1) % args.diners];
			philo[i].fork_lock[1] = &table->fork_lock[i % args.diners];
		}
		else
		{
			philo[i].fork_lock[0] = &table->fork_lock[i % args.diners];
			philo[i].fork_lock[1] = &table->fork_lock[(i + 1) % args.diners];
		}
		pthread_mutex_init(&table->belly[i].full_lock, NULL);
		philo[i].belly = &table->belly[i];
	}
	return (philo);
}

t_philo	*init_philos(t_args args, t_table *table, t_print *print)
{
	int					i;
	t_philo				*philo;
	unsigned long long	starttime;

	i = -1;
	philo = ft_calloc(args.diners, sizeof(t_philo));
	while (++i < args.diners)
	{
		philo[i].id = i + 1;
		philo[i].dead = 0;
		philo[i].args = args;
		philo[i].print = print;
		pthread_mutex_init(&philo[i].ate_lock, NULL);
	}
	philo = create_philos(args, philo, table);
	i = -1;
	starttime = time_now();
	while (++i < args.diners)
	{
		philo[i].start_time = starttime;
		philo[i].last_ate = starttime;
		pthread_create(&philo[i].tid, NULL, &life, (void *)&(philo[i]));
	}
	return (philo);
}
