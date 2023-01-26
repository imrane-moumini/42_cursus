/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:50 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 23:21:29 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_info *start)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&start -> mutex_printf, NULL))
		return (-1);
	if (pthread_mutex_init(&start -> mutex_eat, NULL))
		return (-1);
	if (pthread_mutex_init(&start -> mutex_eat_time, NULL))
		return (-1);
	if (pthread_mutex_init(&start -> mutex_finish, NULL))
		return (-1);
	if (pthread_mutex_init(&start -> mutex_end_of_eat, NULL))
		return (-1);
	while (i < start -> nbr_philo)
	{
		if (pthread_mutex_init(&(start -> mutex_forks[i]), NULL))
			return (-1);
		i++;
	}
	return (0);
}
