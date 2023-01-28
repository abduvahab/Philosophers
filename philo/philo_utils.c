/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:45:44 by areheman          #+#    #+#             */
/*   Updated: 2022/06/27 14:28:54 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettime(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + (val.tv_usec / 1000));
}

void	ft_print(t_main *m, t_philo *ph, char *s)
{
	pthread_mutex_lock(&(m->writing));
	if (!(m->nb_die) && !(m->all_eat))
		printf("%lli %d %s\n", ft_gettime() - m->time, ph->id + 1, s);
	pthread_mutex_unlock(&(m->writing));
}
