/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:56 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 17:28:00 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_of_eat(t_info *start)
{
	pthread_mutex_lock(&(start -> mutex_end_of_eat));
	start -> end_of_eat = 1;
	pthread_mutex_unlock(&(start -> mutex_end_of_eat));
}

void	died(t_philo philosophe, t_info *start)
{
	pthread_mutex_lock(&(philosophe.start -> mutex_printf));
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i died\n", philosophe.index + 1);
	end_of_eat(start);
	pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
}

int	am_i_die(t_philo *philo_tab, int nbr_philo, t_info *start)
{
	int	i;
	int	finish;

	finish = 0;
	i = 0;
	while (i < nbr_philo)
	{
		if ((get_time() - philo_tab[i].last_time_eat >= philo_tab[i].t_die) \
			&& philo_tab[i].nbr_eat_allow != 0)
		{
			died(philo_tab[i], start);
			return (1);
		}
		if (philo_tab[i].nbr_eat_allow == 0)
			finish++;
		if (philo_tab[i].nbr_eat_allow != 0)
			finish = 0;
		if (finish == nbr_philo)
			return (1);
		i++;
	}
	i = 0;
	return (0);
}

int	finish_eat(int count)
{
	static int	finish;

	finish = finish + count;
	return (finish);
}
