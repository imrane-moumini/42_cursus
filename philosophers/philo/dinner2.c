/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:54:37 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/27 21:55:26 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	has_finished_eat(t_philo *philosophe)
{
	if (philosophe -> nbr_eat_allow == 0)
	{
		pthread_mutex_lock(&(philosophe -> start ->mutex_finish_eat));
		finish_eat(1);
		pthread_mutex_unlock(&(philosophe->start->mutex_finish_eat));
		return (1);
	}
	return (0);
}
