/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:44:20 by areheman          #+#    #+#             */
/*   Updated: 2022/06/25 17:10:06 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

struct	s_main;

typedef struct s_philo{
	int				id;
	int				n_eat;
	int				fork_l;
	int				fork_r;
	long long		last_time;
	struct s_main	*main;
	pthread_t		pth;
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
	pthread_mutex_t	*fork;
	pthread_mutex_t	writing;
	pthread_mutex_t	check;
}			t_main;

int			check_args(int argv, char **args);
int			ft_atoi(char *s);
int			init_main(t_main *main, char **args, int argv);
long long	ft_gettime(void);
int			ft_launch(t_main *main);
void		check_philo(t_main *main);
void		ft_exit(t_main *main);
void		ft_print(t_main *main, t_philo *philo, char *str);

#endif
