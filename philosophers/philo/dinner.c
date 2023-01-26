/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:15 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 17:05:17 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printf_eating(t_philo *philosophe)
{
	pthread_mutex_lock(&(philosophe -> start -> mutex_finish));
	if (philosophe -> start -> end_of_eat == 1)
	{
		pthread_mutex_unlock(&(philosophe -> start -> mutex_finish));
		return ;
	}
	pthread_mutex_unlock(&(philosophe -> start -> mutex_finish));
	pthread_mutex_lock(&(philosophe -> start -> mutex_eat));
	philosophe->last_time_eat = get_time();
	philosophe->nbr_eat_allow--;
	pthread_mutex_unlock(&(philosophe -> start -> mutex_eat));
	pthread_mutex_lock(&(philosophe -> start -> mutex_printf));
	printf("%lld ", (get_time() - philosophe ->time_start));
	printf("%i has taken a fork\n", philosophe ->index + 1);
	printf("%lld ", (get_time() - philosophe->time_start));
	printf("%i has taken a fork\n", philosophe->index + 1);
	printf("%lld ", (get_time() - philosophe->time_start));
	printf("%i is eating\n", philosophe->index + 1);
	pthread_mutex_unlock(&(philosophe->start -> mutex_printf));
	usleep(philosophe -> t_eat * 1000);
}

void	i_am_sleeping(t_philo philosophe)
{
	pthread_mutex_lock(&(philosophe.start -> mutex_finish));
	if (philosophe.start -> end_of_eat == 1)
	{
		pthread_mutex_unlock(&(philosophe.start -> mutex_finish));
		return ;
	}
	pthread_mutex_unlock(&(philosophe.start -> mutex_finish));
	pthread_mutex_lock(&(philosophe.start -> mutex_printf));
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is sleeping\n", philosophe.index + 1);
	pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
	usleep(philosophe.t_sleep * 1000);
}

void	i_am_thinking(t_philo philosophe)
{
	pthread_mutex_lock(&(philosophe.start -> mutex_finish));
	if (philosophe.start -> end_of_eat == 1)
	{
		pthread_mutex_unlock(&(philosophe.start -> mutex_finish));
		return ;
	}
	pthread_mutex_unlock(&(philosophe.start -> mutex_finish));
	pthread_mutex_lock(&(philosophe.start -> mutex_printf));
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is thinkig\n", philosophe.index + 1);
	pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo -> start -> mutex_forks[philo -> left]));
	pthread_mutex_lock(&(philo -> start -> mutex_forks[philo -> right]));
	printf_eating(philo);
	pthread_mutex_unlock(&(philo -> start -> mutex_forks[philo -> right]));
	pthread_mutex_unlock(&(philo -> start -> mutex_forks[philo -> left]));
	i_am_sleeping(*philo);
	i_am_thinking(*philo);
}

void	*action(void *arg)
{
	t_philo	*philosophe;

	philosophe = (t_philo *)arg;
	philo_wait_to_avoid_deadlock(*philosophe);
	while (1)
	{
		pthread_mutex_lock(&(philosophe -> start -> mutex_finish));
		if (philosophe -> start -> end_of_eat != 1)
		{
			pthread_mutex_unlock(&(philosophe -> start -> mutex_finish));
			if (philosophe -> nbr_eat_allow == 0)
			{
				finish_eat(1);
				return (NULL);
			}
			eating(philosophe);
			time_to_think(philosophe);
		}
		else
		{
			pthread_mutex_unlock(&(philosophe -> start -> mutex_finish));
			return (NULL);
		}
	}
	return (NULL);
}
