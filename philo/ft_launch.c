/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:30:04 by areheman          #+#    #+#             */
/*   Updated: 2022/06/27 15:52:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *ph)
{
	t_main		*m;
	long long	tmp;

	m = ph->main;
	pthread_mutex_lock(&(m->fork[ph->fork_r]));
	ft_print(m, ph, "has take a fork");
	pthread_mutex_lock(&(m->fork[ph->fork_l]));
	ft_print(m, ph, "has take a fork");
	pthread_mutex_lock(&(m->check));
	ft_print(m, ph, "is eating");
	ph->last_time = ft_gettime();
	pthread_mutex_unlock(&(m->check));
	tmp = ft_gettime() + (long long)m->tteat;
	while (!(m->nb_die))
	{
		if (ft_gettime() >= tmp)
			break ;
		usleep(100);
	}
	ph->n_eat++;
	pthread_mutex_unlock(&(m->fork[ph->fork_l]));
	pthread_mutex_unlock(&(m->fork[ph->fork_r]));
}

static void	philo_sleep(t_philo *ph, t_main *m)
{
	long long	tmp;

	ft_print(m, ph, "is sleeping");
	tmp = ft_gettime() + (long long)m->ttslp;
	while (!(m->nb_die) && !(m->all_eat))
	{
		if (ft_gettime() >= tmp)
			break ;
		usleep(100);
	}
}

static void	philo_one(t_main *m, t_philo *ph)
{
	pthread_mutex_lock(&(m->fork[0]));
	ft_print(m, ph, "take a fork");
	pthread_mutex_unlock(&(m->fork[0]));
	while (ft_gettime() <= ph->last_time + m->ttdie)
	{
		usleep(100);
	}
}

static void	*ft_philo(void *v_ph)
{
	t_philo	*philo;
	t_main	*m;

	philo = (t_philo *)v_ph;
	m = philo->main;
	if (m->nphilo == 1)
	{
		philo_one(m, philo);
		return (NULL);
	}
	if (philo->id % 2)
		usleep(10000);
	while (!(m->nb_die))
	{
		philo_eat(philo);
		if ((m->all_eat))
			break ;
		philo_sleep(philo, m);
		if (m->nb_die)
			break ;
		ft_print(m, philo, "is thinking");
	}
	return (NULL);
}

int	ft_launch(t_main *m)
{
	int	i;

	i = 0;
	while ((i < m->nphilo))
	{
		if (pthread_create(&(m->philo[i].pth), \
				NULL, ft_philo, (void *)&(m->philo[i])))
		{
			printf("problem when creat thread!\n");
			free(m->philo);
			free(m->fork);
			return (0);
		}
		m->philo[i].last_time = ft_gettime();
		usleep(50);
		i++;
	}
	return (1);
}
