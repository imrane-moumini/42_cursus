/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/25 23:52:20 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

info fill_info(int argc, char *argv[])
{
    info start;

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

int handle_error(int argc, char *argv[])
{
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("0 1 died\n");
		return (0);
	}
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


void printf_eating(philo *philosophe)
{
	// pthread_mutex_lock(&(philosophe -> start -> mutex_printf));
	// printf("%lld ", (get_time() - philosophe -> time_start));
	// printf("%i i am in printf eating\n", philosophe -> index + 1);
	// pthread_mutex_unlock(&(philosophe -> start -> mutex_printf));
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

void i_am_sleeping(philo philosophe)
{
	// pthread_mutex_lock(&(philosophe.start -> mutex_printf));
	// printf("%lld ", (get_time() - philosophe.time_start));
	// printf("%i im in i am sleeping\n", philosophe.index + 1);
	// pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
	pthread_mutex_lock(&(philosophe.start -> mutex_printf));	
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is sleeping\n", philosophe.index + 1);
	pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
	usleep(philosophe.t_sleep * 1000);
}

void i_am_thinking(philo philosophe)
{
	// pthread_mutex_lock(&(philosophe.start -> mutex_printf));
	// printf("%lld ", (get_time() - philosophe.time_start));
	// printf("%i fim in i an thinking\n", philosophe.index + 1);
	// pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
	pthread_mutex_lock(&(philosophe.start -> mutex_printf));
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is thinkig\n", philosophe.index + 1);
	pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
}

void end_of_eat(info *start)
{
		pthread_mutex_lock(&(start -> mutex_end_of_eat));
		start -> end_of_eat = 1;
		pthread_mutex_unlock(&(start -> mutex_end_of_eat));
}
int am_i_die(philo *philo_tab, int nbr_philo, info *start)
{
	int i;
	int finish;

	finish = 0;
	i = 0;
	while (i < nbr_philo)
	{
		if ((get_time() - philo_tab[i].last_time_eat >= philo_tab[i].t_die) && philo_tab[i].nbr_eat_allow != 0)
		{
			pthread_mutex_lock(&(philo_tab[i].start -> mutex_printf));
			printf("%lld ", (get_time() - philo_tab[i].time_start));
			printf("%i died\n", philo_tab[i].index + 1);
			end_of_eat(start);
			printf("IN IM DEAD, END OF EAT IS %i\n", start -> end_of_eat);
			pthread_mutex_unlock(&(philo_tab[i].start -> mutex_printf));
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

void time_to_think(philo *philosophe)
{
	int time;
	// pthread_mutex_lock(&(philosophe -> start -> mutex_printf));
	// printf("%lld ", (get_time() - philosophe -> time_start));
	// printf("%i im in time to think\n", philosophe -> index + 1);
	// pthread_mutex_unlock(&(philosophe -> start -> mutex_printf));
    pthread_mutex_lock(&(philosophe -> start -> mutex_eat_time));
	time = ((philosophe -> t_die - (philosophe -> t_eat + philosophe -> t_sleep)) / 2);
	pthread_mutex_unlock(&(philosophe -> start -> mutex_eat_time));
	if (time < 0)
		time = 0;
	if (time == 0 )
		time = 1;
	if (time > 600)
		time = 200;
	usleep(time * 1000);
}
void *action(void *arg)
{
    philo *philosophe = (philo *)arg;
	philo_wait_to_avoid_deadlock(*philosophe);
	while (1)
	{
		pthread_mutex_lock(&(philosophe -> start -> mutex_finish));
		printf("%i IN ACTION END OF EAT IS %i\n", philosophe -> index, philosophe -> start -> end_of_eat);
		if (philosophe -> start -> end_of_eat != 1)
		{
			pthread_mutex_unlock(&(philosophe -> start -> mutex_finish));
			if (philosophe -> nbr_eat_allow == 0)
			{
				finish_eat(1);
				return (NULL);
			}
			pthread_mutex_lock(&(philosophe -> start -> mutex_forks[philosophe -> left]));
			pthread_mutex_lock(&(philosophe -> start -> mutex_forks[philosophe -> right]));
			printf_eating(philosophe);
			pthread_mutex_unlock(&(philosophe -> start -> mutex_forks[philosophe -> right]));
			pthread_mutex_unlock(&(philosophe -> start -> mutex_forks[philosophe -> left]));
			i_am_sleeping(*philosophe);
			i_am_thinking(*philosophe);
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
	else
		philosophe.nbr_eat_allow = -1;
	philosophe.time_start = start -> time_start;
	philosophe.last_time_eat = get_time();
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

void	philo_wait_to_avoid_deadlock(philo philo)
{
	if (philo.index % 2)
		usleep(1000);
	else
		usleep(500);
}

void init_mutex(info *start)
{
	int i;
	i = 0;
	pthread_mutex_init(&start -> mutex_printf,NULL);
	pthread_mutex_init(&start -> mutex_eat,NULL);
	pthread_mutex_init(&start -> mutex_eat_time,NULL);
	pthread_mutex_init(&start -> mutex_finish,NULL);
	pthread_mutex_init(&start -> mutex_end_of_eat,NULL);
	while (i < start -> nbr_philo)
	{
		pthread_mutex_init(&(start -> mutex_forks[i]),NULL);
		i++;
	}
}

philo *create_threads(info *start)
{
	int i;
	philo *philo_tab;
	
	i = 0;
    philo_tab = malloc(sizeof(philo)* start -> nbr_philo);
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

int join_threads(info *start, philo *philo_tab)
{
	int i;

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

int finish_eat(int count)
{
	static int finish;

	finish = finish + count;
	return (finish);
	
}
void destroy_element(philo *philo_tab, info *start)
{
	int i;
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

int main(int argc, char *argv[])
{
    info start;
	philo *philo_tab;

	// voir pk mon thread continue a mange rapres etre mort
	// voir pk mon programme met du temps a sarreter qund un mec meurt
	// voir pk quand mange assez personne mange en plus mais quand meurt ca mange en plus
    if (handle_error(argc, argv) == 0)
        return (0);
    start = fill_info(argc, argv);
	init_mutex(&start);
    philo_tab = create_threads(&start);
	if (philo_tab == NULL)
		return (0);
	while (1)
	{
		if (am_i_die(philo_tab, start.nbr_philo, &start) == 1 || finish_eat(0) == start.nbr_philo)
		{
        	if (join_threads(&start, philo_tab) == 0)
				return (0);
			destroy_element(philo_tab, &start);
			return (0);
		}
	}
}