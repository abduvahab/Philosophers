/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:59:15 by areheman          #+#    #+#             */
/*   Updated: 2022/07/04 16:21:04 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *ph)
{
	t_main		*m;
	long long	tmp;

	m = ph->main;
	sem_wait(m->room);
	sem_wait(m->fork);
	ft_print(m, ph, "has take a fork");
	sem_post((m->fork));
	sem_wait(m->fork);
	ft_print(m, ph, "has take a fork");
	sem_post(m->fork);
	sem_wait(m->check);
	ph->last_time = ft_gettime();
	ft_print(m, ph, "is eating");
	sem_post((m->check));
	tmp = ft_gettime() + (long long)m->tteat;
	while (!(m->nb_die))
	{
		if (ft_gettime() >= tmp)
			break ;
		usleep(100);
	}
	ph->n_eat++;
	sem_post(m->room);
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
	sem_wait((m->fork));
	ft_print(m, ph, "take a fork");
	sem_post((m->fork));
	while (ft_gettime() <= ph->last_time + m->ttdie)
	{
		usleep(100);
	}
}

static void	*ft_philo(t_main *m, t_philo *philo)
{
	pthread_create(&(philo->death_c), NULL, check_philo, (void *)(philo));
	if (m->nphilo == 1)
	{
		philo_one(m, philo);
		return (NULL);
	}
	if (philo->id % 2)
		usleep(1000);
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
	pthread_join((philo->death_c), NULL);
	return (NULL);
}

int	ft_launch(t_main *m)
{
	int	i;

	i = 0;
	while ((i < m->nphilo))
	{
		m->philo[i].pro_id = fork();
		if (m->philo[i].pro_id < 0)
		{
			printf("problem when creat process!\n");
			free(m->philo);
			return (0);
		}
		else if (m->philo[i].pro_id == 0)
		{
			m->philo[i].id = i;
			m->philo[i].last_time = ft_gettime();
			ft_philo(m, &m->philo[i]);
		}
		i++;
	}
	return (1);
}
