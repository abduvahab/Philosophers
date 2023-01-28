/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:25:33 by areheman          #+#    #+#             */
/*   Updated: 2022/07/04 16:26:01 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		ph[i].main = m;
		ph[i].n_eat = 0;
		i++;
	}
	return (ph);
}

static int	ft_init_sem(t_main *m)
{
	sem_unlink("/ph_fork");
	sem_unlink("/ph_writing");
	sem_unlink("/ph_check");
	sem_unlink("/ph_room");
	m->fork = sem_open("/ph_fork", O_CREAT, 0666, 1);
	m->room = sem_open("/ph_room", O_CREAT, 0666, m->nphilo / 2);
	m->writing = sem_open("/ph_writing", O_CREAT, 0666, 1);
	m->check = sem_open("/ph_check", O_CREAT, 0666, 1);
	if (!m->fork || !m->writing || !m->check)
		return (0);
	return (1);
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
	if (!(m->philo))
	{
		free(m->philo);
		return (0);
	}
	if (!ft_init_sem(m))
		return (0);
	return (1);
}
