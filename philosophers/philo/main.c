/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/22 16:42:22 by imoumini         ###   ########.fr       */
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
	philosophe->last_time_eat = get_time();
	usleep(philosophe -> t_eat * 1000);
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
	pthread_mutex_lock(&(philosophe.start -> mutex_printf));	
	printf("%lld ", (get_time() - philosophe.time_start));
	printf("%i is sleeping\n", philosophe.index + 1);
	pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
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
				// pthread_mutex_lock(&(philo_tab[i].start -> mutex_printf));
				// printf("philo %i, last eat time %lld, time do die %i\n", i+1, (get_time() - philo_tab[i].last_time_eat), philo_tab[i].t_die);
				// printf("get time %lld, last time eat %lld\n", get_time(), philo_tab[i].last_time_eat);
				// pthread_mutex_unlock(&(philo_tab[i].start -> mutex_printf));
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
	// while (1)
	// {
		// pthread_mutex_lock(&(philosophe.start -> mutex_forks[philosophe.left]));
		// pthread_mutex_lock(&(philosophe.start -> mutex_forks[philosophe.right]));
		// pthread_mutex_lock(&(philosophe.start -> mutex_printf));
		// printf("philo id : %i left is %i\n", philosophe.index + 1, philosophe.left);
		// printf("philo id : %i right is %i\n", philosophe.index + 1, philosophe.right);
		// pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
		// pthread_mutex_unlock(&(philosophe.start -> mutex_forks[philosophe.right]));
		// pthread_mutex_unlock(&(philosophe.start -> mutex_forks[philosophe.left]));
	// 	usleep(1000);
	// 	break;
	// }
	while (1)
	{
			//printf("thread nbr %lu, philo id : %i left is %i\n",thread_id , philosophe.index, philosophe.left);
			//printf("thread nbr %lu, philo id : %i right is %i\n",thread_id , philosophe.index, philosophe.right);
			pthread_mutex_lock(&(philosophe.start -> mutex_forks[philosophe.left]));
			pthread_mutex_lock(&(philosophe.start -> mutex_forks[philosophe.right]));
			pthread_mutex_lock(&(philosophe.start -> mutex_printf));
			printf_eating(philosophe);
			pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			is_eating(&philosophe);
			pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			pthread_mutex_unlock(&(philosophe.start -> mutex_forks[philosophe.right]));
			pthread_mutex_unlock(&(philosophe.start -> mutex_forks[philosophe.left]));
			// pthread_mutex_lock(&(philosophe.start -> mutex_printf));
			i_am_sleeping(philosophe);
			// pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			pthread_mutex_lock(&(philosophe.start -> mutex_printf));
			i_am_thinking(philosophe);
			pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			// la le pb c que certain hilo ne mangent pas en meme temps et du coup
			// avec certains argument certains vont mourrir alors quils ne devrient pas
			// doit y avoir un pb hrs de actions
			// les fourchettes semblent bien allouer du coup bizzare
			// ca rejoins le pb davant paske normalement certains auraient pun a accder a un element car il etait dispo
			// c comme si certain truc sont considerer comme indispo alors que normalement si
			
			// deadlock
				// soit jattend la ressource dun mec qui qttend la mienne et y spasse rien
				// soit jattend une ressource que g moi meme bloquer juste avant et du coup y spasse rien
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
	philosophe.last_time_eat = get_time();
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
			if (i == 0)
			{
				philo_tab[i].left = i;
				philo_tab[i].right = i + 1;
			}
			else if (i == start.nbr_philo - 1)
			{
				philo_tab[i].left = i;
				philo_tab[i].right = 0;
			}
			else
			{
				philo_tab[i].left = i;
				philo_tab[i].right = i + 1;
			}
        	i++;
    	}
	}
	if (start.nbr_philo  == 2)
	{
		philo_tab[0].left = 0;
		philo_tab[0].right = 1;
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
				while (i < start.nbr_philo)
				{
					pthread_mutex_destroy(&(start.mutex_forks[i]));
					i++;
				}
				pthread_mutex_destroy(&start.mutex_printf);
                return (0);
            }
            i++;
        }
		if (am_i_die(philo_tab, start.nbr_philo) == 1)
		{
			i = 0;
			free(ids);
            free(philo_tab);
			while (i < start.nbr_philo)
			{
				pthread_mutex_destroy(&(start.mutex_forks[i]));
				i++;
			}
			pthread_mutex_destroy(&start.mutex_printf);
            return (0);
		}
        i = 0;
        while (i < start.nbr_philo)
        {
            if (pthread_join(ids[i], NULL) != 0)
            {
				i = 0;
                free(ids);
                free(philo_tab);
                printf("can't join threade nbr %i", i);
				while (i < start.nbr_philo)
				{
					pthread_mutex_destroy(&(start.mutex_forks[i]));
					i++;
				}
				pthread_mutex_destroy(&start.mutex_printf);
                return (0);
            }
            i++;
        }
        free(ids);
        free(philo_tab);
    }
}

// comment t'as fait pour quil attendent pas touos en meme temps la meme fourchette
// comment ca se fait que meme si ils attendent la meme foruchette ils on t pas le temps de la prendre qudn c release ?