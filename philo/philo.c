/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:51:30 by areheman          #+#    #+#             */
/*   Updated: 2022/06/27 15:49:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_free(t_main m)
{
	free(m.philo);
	free(m.fork);
}

int	main(int argv, char **args)
{
	t_main	main;

	if (check_args(argv, args))
		return (0);
	if (!init_main(&main, args, argv))
	{
		printf("there are problem during initialize!\n");
		ft_free(main);
		return (0);
	}
	if (!ft_launch(&main))
		return (0);
	check_philo(&main);
	ft_exit(&main);
	return (0);
}
