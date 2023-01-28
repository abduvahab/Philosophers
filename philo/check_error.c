/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:00:43 by areheman          #+#    #+#             */
/*   Updated: 2022/06/24 17:30:11 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int	i;
	int	n;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
		return (0);
	if (s[i] == '+')
		i++;
	n = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			n = n * 10 + (s[i] - 48);
		else
			return (0);
		i++;
	}
	return (n);
}

int	check_args(int n, char **s)
{
	int	i;

	if (n == 5 || n == 6)
	{
		i = n;
		while (--i > 0)
		{
			if (!ft_atoi(s[i]))
			{
				printf("you have to enter a valid number biger then 0!\n");
				return (1);
			}
		}
		return (0);
	}
	else
	{
		printf("you have to enter 4 or 5 arguments!\n");
		return (1);
	}
}
