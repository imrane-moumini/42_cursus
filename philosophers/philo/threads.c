/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:58:03 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 23:25:21 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*create_threads(t_info *start)
{
	int		i;
	t_philo	*philo_tab;

	i = 0;
	philo_tab = malloc(sizeof(t_philo) * start -> nbr_philo);
	if (!(philo_tab))
		return (NULL);
	fill_philo_tab(philo_tab, start);
	add_pos_to_philo(philo_tab, *start);
	while (i < start -> nbr_philo)
	{
		if (pthread_create(start -> ids + i, NULL, &action, philo_tab + i) != 0)
		{
			printf("can't create threade nbr %i", i);
			destroy_element(philo_tab, start);
			return (NULL);
		}
		i++;
	}
	return (philo_tab);
}

int	join_threads(t_info *start, t_philo *philo_tab)
{
	int	i;

	i = 0;
	while (i < start -> nbr_philo)
	{
		if (pthread_join(start -> ids[i], NULL) != 0)
		{
			i = 0;
			printf("can't join threade nbr %i", i);
			destroy_element(philo_tab, start);
			return (0);
		}
		i++;
	}
	return (1);
}

void	destroy_element(t_philo *philo_tab, t_info *start)
{
	int	i;

	i = 0;
	free(philo_tab);
	while (i < start -> nbr_philo)
	{
		pthread_mutex_destroy(&(start -> mutex_forks[i]));
		i++;
	}
	pthread_mutex_destroy(&start -> mutex_printf);
	pthread_mutex_destroy(&start -> mutex_eat);
	pthread_mutex_destroy(&start -> mutex_eat_time);
	pthread_mutex_destroy(&start -> mutex_finish);
	pthread_mutex_destroy(&start -> mutex_end_of_eat);
}
