/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:56:22 by areheman          #+#    #+#             */
/*   Updated: 2022/07/04 16:21:18 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_free(t_main m)
{
	free(m.philo);
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
	ft_exit(&main);
	return (0);
}
