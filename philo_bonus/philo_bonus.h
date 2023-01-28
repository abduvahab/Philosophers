/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:56:50 by areheman          #+#    #+#             */
/*   Updated: 2022/07/04 16:08:17 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <signal.h>

struct	s_main;

typedef struct s_philo{
	int				id;
	int				n_eat;
	long long		last_time;
	struct s_main	*main;
	pid_t			pro_id;
	pthread_t		death_c;
}			t_philo;

typedef struct s_main{
	int				nphilo;
	int				ttslp;
	int				ttdie;
	int				tteat;
	int				nteat;
	int				nb_die;
	int				all_eat;
	long long		time;
	t_philo			*philo;
	sem_t			*room;
	sem_t			*fork;
	sem_t			*writing;
	sem_t			*check;
}			t_main;

int			check_args(int argv, char **args);
int			ft_atoi(char *s);
int			init_main(t_main *main, char **args, int argv);
long long	ft_gettime(void);
int			ft_launch(t_main *main);
void		*check_philo(void *main);
void		ft_exit(t_main *main);
void		ft_print(t_main *main, t_philo *philo, char *str);

#endif
