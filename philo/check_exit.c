/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:18:49 by areheman          #+#    #+#             */
/*   Updated: 2022/06/27 15:53:47 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_all_eat(t_main *m)
{
	int	i;

	if (m->nteat != -1)
	{
		i = 0;
		while (m->philo[i].n_eat >= m->nteat)
		{
			i++;
			if (i == m->nphilo)
			{
				m->all_eat++;
				break ;
			}
		}
	}
}

void	check_philo(t_main *m)
{
	int	i;

	while (!(m->nb_die) && !(m->all_eat))
	{
		i = 0;
		while (i < m->nphilo)
		{
			pthread_mutex_lock(&(m->check));
			if (ft_gettime() - m->philo[i].last_time > m->ttdie)
			{
				ft_print(m, &(m->philo[i]), "died");
				m->nb_die++;
			}
			pthread_mutex_unlock(&(m->check));
			if (m->nb_die)
				break ;
			i++;
		}
		if (!(m->nb_die))
			check_all_eat(m);
	}
}

void	ft_exit(t_main *m)
{
	int	i;

	i = -1;
	while (++i < m->nphilo)
		pthread_join((m->philo[i].pth), NULL);
	i = -1;
	while (++i < m->nphilo)
		pthread_mutex_destroy(&(m->fork[i]));
	pthread_mutex_destroy(&(m->writing));
	pthread_mutex_destroy(&(m->check));
	free(m->philo);
	free(m->fork);
}
