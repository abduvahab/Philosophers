/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:00:12 by areheman          #+#    #+#             */
/*   Updated: 2022/07/04 16:27:40 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_gettime(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + (val.tv_usec / 1000));
}

void	ft_print(t_main *m, t_philo *ph, char *s)
{
	sem_wait((m->writing));
	if (!(m->nb_die) && !(m->all_eat))
		printf("%lli %d %s\n", ft_gettime() - m->time, ph->id + 1, s);
	sem_post((m->writing));
}
