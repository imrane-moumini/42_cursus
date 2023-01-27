/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:42 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/27 20:13:06 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	fill_info(int argc, char *argv[])
{
	t_info	start;

	(void) argc;
	start.nbr_philo = ft_atoi(argv[1]);
	start.t_die = ft_atoi(argv[2]);
	start.t_eat = ft_atoi(argv[3]);
	start.t_sleep = ft_atoi(argv[4]);
	start.bonus = 0;
	start.end_of_eat = 0;
	if (argv[5])
	{
		start.nbr_eat_allow = ft_atoi(argv[5]);
		start.bonus = 1;
	}
	start.time_start = get_time();
	return (start);
}

void	fill_philo_tab(t_philo *philo_tab, t_info *start)
{
	int		i;
	t_philo	philosophe;

	i = 0;
	philosophe.t_die = start -> t_die;
	philosophe.t_eat = start -> t_eat;
	philosophe.t_sleep = start -> t_sleep;
	if (start -> bonus == 1)
		philosophe.nbr_eat_allow = start -> nbr_eat_allow;
	else
		philosophe.nbr_eat_allow = -1;
	philosophe.time_start = start -> time_start;
	philosophe.last_time_eat = get_time();
	while (i < start -> nbr_philo)
	{
		philo_tab[i] = philosophe;
		i++;
	}
	i = 0;
	while (i < start -> nbr_philo)
	{
		philo_tab[i].index = i;
		philo_tab[i].start = start;
		i++;
	}
}

void	add_pos_to_philo(t_philo *philo_tab, t_info start)
{
	int	i;

	i = 0;
	while (i < start.nbr_philo)
	{
		philo_tab[i].left = i;
		philo_tab[i].right = (i + 1) % start.nbr_philo;
		if (philo_tab[i].index % 2)
		{
			philo_tab[i].left = (philo_tab[i].index + 1) % start.nbr_philo;
			philo_tab[i].right = philo_tab[i].index;
		}
		i++;
	}
}
