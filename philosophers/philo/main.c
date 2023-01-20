/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/20 20:57:01 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

info fill_info(int argc, char *argv[])
{
    info start;
	struct timeval tv;
	long long milliseconds;
	
	(void) argc;
    start.nbr_philo = ft_atoi(argv[1]);
    start.t_die = ft_atoi(argv[2]);
    start.t_eat = ft_atoi(argv[3]);
    start.t_sleep = ft_atoi(argv[4]);
    start.bonus = 0;
    if (argv[5])
    {
        start.nbr_eat_allow = ft_atoi(argv[5]);
        start.bonus = 1;
    }
	if (gettimeofday(&tv, NULL) == -1)
		return (start);
	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	start.time_start = milliseconds;
    return (start);
}

int handle_error(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("wrong nummber of arguments\n");
        return (0);
    }
    if (ft_atoi(argv[1]) == 0)
    {
        printf("parsing error\n");
        return (0);
    }
    return (1);   
}
long long get_time()
{
	long long milliseconds;
	struct timeval tv;
	
	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (milliseconds);
}

void is_eating(philo *philosophe)
{
	usleep(philosophe -> t_eat * 1000);
	philosophe -> last_time_eat = get_time();
	philosophe -> as_eaten_one = 1;
}

void printf_eating(philo philosophe)
{
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i has taken a fork\n", philosophe.index + 1);
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i has taken a fork\n", philosophe.index + 1);
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is eating\n", philosophe.index + 1);
}

void i_am_sleeping(philo philosophe)
{
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is sleeping\n", philosophe.index + 1);
	usleep(philosophe.t_sleep * 1000);
}

void i_am_thinking(philo philosophe)
{
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is thinkig\n", philosophe.index + 1);
}

int am_i_die(philo *philo_tab, int nbr_philo)
{
	int i;
	i = 0;
	while (1)
	{
		while (i < nbr_philo)
		{
			if (get_time() - philo_tab[i].last_time_eat >= philo_tab[i].t_die)
			{
				philo_tab[i].am_i_die = 1;
				pthread_mutex_lock(&(philo_tab[i].start -> mutex_printf));
				printf("%lld ", (get_time() - philo_tab[i].time_start));
				printf("%i died\n", philo_tab[i].index + 1);
				pthread_mutex_unlock(&(philo_tab[i].start -> mutex_printf));
				return (1);
			}
			i++;
		}
		i = 0;
	}
	return (0);
}

void *action(void *arg)
{
    philo philosophe = *(philo *)arg;
	//pthread_t thread_id = pthread_self();
	while (1)
	{
			//printf("thread nbr %lu, philo id : %i left is %i\n",thread_id , philosophe.index, philosophe.left);
			//printf("thread nbr %lu, philo id : %i right is %i\n",thread_id , philosophe.index, philosophe.right);
			pthread_mutex_lock(&(philosophe.start -> mutex_forks[philosophe.left]));
			pthread_mutex_lock(&(philosophe.start -> mutex_forks[philosophe.right]));
			pthread_mutex_lock(&(philosophe.start -> mutex_printf));
			printf_eating(philosophe);
			is_eating(&philosophe);
			i_am_sleeping(philosophe);
			i_am_thinking(philosophe);
			pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			pthread_mutex_unlock(&(philosophe.start -> mutex_forks[philosophe.right]));
			pthread_mutex_unlock(&(philosophe.start -> mutex_forks[philosophe.left]));
			// seul le premier thread mange
			// ca veut dire que je change pas de lock ou bien de philosophe a chaque thread
			// commebeter code et aficher index ddes philo avec index thread et voir si ca change bien
			// puis si ca change voir si index des left right change bien a chaque fois
	}
    return (NULL);
}

void fill_philo_tab(philo *philo_tab, info *start)
{
    int i;
    philo philosophe;
    
    i = 0;
    philosophe.t_die = start -> t_die;
    philosophe.t_eat = start -> t_eat;
    philosophe.t_sleep = start -> t_sleep;
    if (start -> bonus == 1)
        philosophe.nbr_eat_allow = start -> nbr_eat_allow;
    philosophe.is_eating = 0;
	philosophe.time_start = start -> time_start;
	philosophe.last_time_eat = 0;
	philosophe.as_eaten_one = 0;
	philosophe.am_i_die = 0;
    while(i < start -> nbr_philo)
    {
        philo_tab[i] = philosophe;
        i++;
    }
    i = 0;
    while(i < start -> nbr_philo)
    {
        philo_tab[i].index = i;
		philo_tab[i].start = start;
        i++;
    }
}

void add_pos_to_philo(philo *philo_tab, info start)
{
    int i;
    i = 0;
	if (start.nbr_philo > 2)
    {
		while (i < start.nbr_philo)
    	{
			if (i + 1 <= start.nbr_philo - 1)
				philo_tab[i].left = i + 1;
			else
				philo_tab[i].left = 0;
			if (i - 1 < 0)
				philo_tab[i].right = start.nbr_philo - 1;
			else
				philo_tab[i].right =  i - 1;
        	i++;
    	}
	}
	if (start.nbr_philo  == 2)
	{
		philo_tab[0].left = 1;
		philo_tab[0].right = 0;
		philo_tab[1].left = 0;
		philo_tab[1].right = 1;
	}
}
int main(int argc, char *argv[])
{
	
    info start;
    pthread_t *ids;
    philo *philo_tab;
    int i;
	
    i = 0;
    if (handle_error(argc, argv) == 0)
        return (0);
    start = fill_info(argc, argv);
	if (start.nbr_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("0 1 died\n");
		return (0);
	}
	pthread_mutex_init(&start.mutex_printf,NULL);
	while (i < start.nbr_philo)
	{
			pthread_mutex_init(&(start.mutex_forks[i]),NULL);
			i++;

	}
	i = 0;
    if (start.bonus == 0)
    {
        ids = malloc(sizeof(pthread_t) * start.nbr_philo);
        philo_tab = malloc(sizeof(philo)* start.nbr_philo);
        fill_philo_tab(philo_tab, &start);
        add_pos_to_philo(philo_tab, start);
        while (i < start.nbr_philo)
        {
            if (pthread_create(ids + i, NULL, &action, philo_tab + i) != 0)
            {
                free(ids);
                free(philo_tab);
                printf("can't create threade nbr %i", i);
                return (0);
            }
            i++;
        }
		if (am_i_die(philo_tab, start.nbr_philo) == 1)
		{
			free(ids);
            free(philo_tab);
            return (0);
		}
        i = 0;
        while (i < start.nbr_philo)
        {
            if (pthread_join(ids[i], NULL) != 0)
            {
                free(ids);
                free(philo_tab);
                printf("can't join threade nbr %i", i);
                return (0);
            }
            i++;
        }
        free(ids);
        free(philo_tab);
    }
}

