/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:12:58 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 22:27:21 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_nbr(char c)
{
	int	nbr;

	nbr = c - 48;
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while ((nptr[i] >= 48) && (nptr[i] <= 57))
	{
		nbr = ft_nbr(nptr[i]) + (nbr * 10);
		i++;
	}
	return (nbr * sign);
}

long long	get_time(void)
{
	long long		milliseconds;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (milliseconds);
}

void	philo_wait_to_avoid_deadlock(t_philo philo)
{
	if (philo.index % 2)
		usleep(1000);
	else
		usleep(500);
}

void	time_to_think(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&(philo -> start -> mutex_eat_time));
	time = ((philo -> t_die - (philo -> t_eat + philo -> t_sleep)) / 2);
	pthread_mutex_unlock(&(philo -> start -> mutex_eat_time));
	if (time < 0)
		time = 0;
	if (time == 0)
		time = 1;
	if (time > 600)
		time = 200;
	usleep(time * 1000);
}
