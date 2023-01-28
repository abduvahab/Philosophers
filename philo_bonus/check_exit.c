/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:59:54 by areheman          #+#    #+#             */
/*   Updated: 2022/07/04 16:20:21 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	check_all_eat(t_philo *philo)
{
	int		i;
	t_main	*m;

	m = philo->main;
	if (m->nteat != -1)
	{
		i = 0;
		while (philo->n_eat >= m->nteat)
		{
			i++;
			if (i == m->nphilo)
			{
				sem_wait(m->check);
				m->all_eat++;
				exit(1);
			}
		}
	}
}

void	*check_philo(void *s)
{
	t_main	*m;
	t_philo	*philo;
	int		i;

	philo = (t_philo *)s;
	m = philo->main;
	while (!(m->nb_die) && !(m->all_eat))
	{
		i = 0;
		while (i < m->nphilo)
		{
			sem_wait((m->check));
			if ((ft_gettime() - philo->last_time) > m->ttdie)
			{
				ft_print(m, philo, "died");
				m->nb_die++;
				exit(1);
			}
			sem_post((m->check));
			i++;
		}
		if (!(m->nb_die))
			check_all_eat(philo);
	}
	return (NULL);
}

void	ft_exit(t_main *m)
{
	pid_t	pd;
	int		i;
	int		ret;

	pd = waitpid(-1, &ret, 0);
	if (ret != 0)
	{
		i = 0 ;
		while (i < m->nphilo)
		{
			kill(m->philo[i].pro_id, 15);
			i++;
		}
	}
	sem_close(m->room);
	sem_close(m->fork);
	sem_close(m->writing);
	sem_close(m->check);
	sem_unlink("/ph_room");
	sem_unlink("/ph_fork");
	sem_unlink("/ph_writing");
	sem_unlink("/ph_check");
	free(m->philo);
}
