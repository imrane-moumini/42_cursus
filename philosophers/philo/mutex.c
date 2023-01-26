/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:50 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 17:06:20 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutex(t_info *start)
{
	int	i;

	i = 0;
	pthread_mutex_init(&start -> mutex_printf, NULL);
	pthread_mutex_init(&start -> mutex_eat, NULL);
	pthread_mutex_init(&start -> mutex_eat_time, NULL);
	pthread_mutex_init(&start -> mutex_finish, NULL);
	pthread_mutex_init(&start -> mutex_end_of_eat, NULL);
	while (i < start -> nbr_philo)
	{
		pthread_mutex_init(&(start -> mutex_forks[i]), NULL);
		i++;
	}
}
