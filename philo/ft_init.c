/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:21:20 by areheman          #+#    #+#             */
/*   Updated: 2022/06/25 17:13:57 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*init_philo(t_main *m)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = (t_philo *)malloc(sizeof(t_philo) * m->nphilo +1);
	if (!ph)
		return (0);
	while (i < m->nphilo)
	{
		ph[i].id = i;
		ph[i].fork_l = i;
		ph[i].fork_r = (i + 1) % m->nphilo;
		ph[i].main = m;
		ph[i].last_time = ft_gettime();
		i++;
	}
	return (ph);
}

static pthread_mutex_t	*init_fork(t_main *m)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * m->nphilo + 1);
	if (!fork)
		return (0);
	while (i < m->nphilo)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return (0);
		i++;
	}
	return (fork);
}

int	init_main(t_main *m, char **s, int n)
{
	m->nphilo = ft_atoi(s[1]);
	m->ttdie = ft_atoi(s[2]);
	m->tteat = ft_atoi(s[3]);
	m->ttslp = ft_atoi(s[4]);
	if (n == 6)
		m->nteat = ft_atoi(s[5]);
	else
		m->nteat = -1;
	m->nb_die = 0;
	m->all_eat = 0;
	m->time = ft_gettime();
	m->philo = init_philo(m);
	m->fork = init_fork(m);
	if (!(m->philo) || !(m->fork))
	{
		free(m->philo);
		free(m->fork);
		return (0);
	}
	if (pthread_mutex_init(&(m->writing), NULL))
		return (0);
	if (pthread_mutex_init(&(m->check), NULL))
		return (0);
	return (1);
}
