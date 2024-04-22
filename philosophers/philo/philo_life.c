/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:41:46 by xlow              #+#    #+#             */
/*   Updated: 2024/04/18 17:05:55 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->print->print_lock);
	pthread_mutex_lock(&philo->print->stop_lock);
	if (philo->print->stop)
	{
		pthread_mutex_unlock(&philo->print->print_lock);
		pthread_mutex_unlock(&philo->print->stop_lock);
		philo->dead = 1;
		return ;
	}
	pthread_mutex_unlock(&philo->print->stop_lock);
	printf("%lld %d %s\n", time_now() - philo->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->print->print_lock);
}

static void	print_eat(t_philo *philo)
{
	unsigned long long	now;

	pthread_mutex_lock(&philo->print->print_lock);
	pthread_mutex_lock(&philo->print->stop_lock);
	if (philo->print->stop)
	{
		pthread_mutex_unlock(&philo->print->print_lock);
		pthread_mutex_unlock(&philo->print->stop_lock);
		philo->dead = 1;
		return ;
	}
	pthread_mutex_unlock(&philo->print->stop_lock);
	now = time_now() - philo->start_time;
	printf("%lld %d has taken a fork\n%lld %d has taken a fork\n\
%lld %d is eating\n", now, philo->id, now, philo->id, \
			now, philo->id);
	pthread_mutex_unlock(&philo->print->print_lock);
}

static void	finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->ate_lock);
	philo->last_ate = time_now();
	pthread_mutex_unlock(&philo->ate_lock);
	sleep_properly(philo->args.tte);
	pthread_mutex_unlock(philo->fork_lock[0]);
	pthread_mutex_unlock(philo->fork_lock[1]);
}

void	*life(void *philo)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = (t_philo *)philo;
	if (p->id % 2 == 1)
		sleep_properly(2);
	while (!p->dead)
	{
		pthread_mutex_lock(p->fork_lock[0]);
		pthread_mutex_lock(p->fork_lock[1]);
		print_eat(philo);
		if (i != p->args.meals && p->args.meals != -1
			&& ++i == p->args.meals)
		{
			pthread_mutex_lock(&p->belly->full_lock);
			p->belly->full++;
			pthread_mutex_unlock(&p->belly->full_lock);
		}
		finish_eating(p);
		print(p, "is sleeping");
		sleep_properly(p->args.tts);
		print(p, "is thinking");
	}
	return (NULL);
}
