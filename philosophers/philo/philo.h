/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:14:01 by xlow              #+#    #+#             */
/*   Updated: 2024/04/18 20:41:24 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int	diners;
	int	ttd;
	int	tte;
	int	tts;
	int	meals;
}	t_args;

typedef struct s_print
{
	int				stop;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	print_lock;
}	t_print;

typedef struct s_full
{
	int				full;
	pthread_mutex_t	full_lock;
}	t_full;

typedef struct s_table
{
	int				*forks;
	t_full			*belly;
	pthread_mutex_t	*fork_lock;
}	t_table;

typedef struct s_philo
{
	int					id;
	int					dead;
	unsigned long long	start_time;
	unsigned long long	last_ate;
	t_args				args;
	t_full				*belly;
	t_print				*print;
	pthread_t			tid;
	pthread_mutex_t		*fork_lock[2];
	pthread_mutex_t		ate_lock;
}	t_philo;

// PHILO_ARGS
t_args				process_args(int argc, char **argv);

// PHILO_INIT
int					init_mutex_structs(t_args args, t_table *table,
						t_print *print);
t_philo				*init_philos(t_args args, t_table *table,
						t_print *printing);

// PHILO_LIFE
void				*life(void *philo);

// PHILO_UTILS
void				sleep_properly(int ms);
unsigned long long	time_now(void);

// PHILO_MONITOR
void				monitoring(t_args args, t_philo *philos, t_print *printing);
void				cleanup(t_args args, t_philo *philos, t_table *table,
						t_print *print);
#endif
