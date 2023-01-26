/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 23:19:31 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	start;
	t_philo	*philo_tab;

	if (handle_second_error(argc, argv) == 0)
		return (0);
	start = fill_info(argc, argv);
	if (init_mutex(&start) == -1)
	{
		printf("init mutex failed\n");
		return (0);
	}
	philo_tab = create_threads(&start);
	if (philo_tab == NULL)
		return (0);
	while (1)
	{
		if (am_i_die(philo_tab, start.nbr_philo, &start) == 1 \
			|| finish_eat(0) == start.nbr_philo)
		{
			if (join_threads(&start, philo_tab) == 0)
				return (0);
			destroy_element(philo_tab, &start);
			return (0);
		}
	}
}
