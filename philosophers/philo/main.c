/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/19 21:41:38 by imoumini         ###   ########.fr       */
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
		return;
	*milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (milliseconds);
}

void is_eating(philo *philosophe)
{
	usleep(philosophe -> t_eat * 1000);
	philosophe -> last_time_eat = get_time();
	philosophe -> as_eaten_one = 1;
}

void printf_eating(long long milliseconds, philo philosophe)
{
	printf("%i ", (get_time() - philosophe.time_start));
	printf("%i has taken a fork\n", philosophe.index);
	printf("%i ", (get_time() - philosophe.time_start));
	printf("%i has taken a fork\n", philosophe.index);
	printf("%i ", (get_time() - philosophe.time_start));
	printf("%i is eating\n", philosophe.index);
}

void am_i_die(philo *philosophe)
{
	while (1)
	{
		if (last_time_eat - t_die == 0)
		{
			philosophe -> am_i_die = 1;
			break;
		}
	}
}
void *action(void *arg)
{
	long long milliseconds;
    philo philosophe = *(philo *)arg;
	while (1)
	{
		// finir qund premiere fois je mange
		// finir qund g deja mange une fois
		if (philosophe_as_eaten_one == 0)
		{
			// utiliser un lock (mutex) different par fourchette
			// cela permet de les differncier et de savoir si oui ou non on peut les toucher
			// pour ne pas epnpecher les autre thread d'avancer leur excecuion
			// il suffit de differencier les locks 
			// un lock par resssource qu'on souhaite proteger
			pthread_mutex_lock(&(philosophe.start -> mutex_fork[philosophe.left]));
			pthread_mutex_lock(&(philosophe.start -> mutex_fork[philosophe.right]));
			pthread_mutex_lock(&(philosophe.start -> mutex_printf));
			printf_eating(milliseconds ,philosophe);
			is_eating(&philosophe);
			pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			pthread_mutex_unlock(philosophe.start -> mutex_fork[philosophe.right]);
			pthread_mutex_unlock(philosophe.start -> mutex_fork[philosophe.left]);
			//philo_printf(arg, philo->id, "is sleeping");
			//pass_time((long long)arg->sleep_time, arg);
			//philo_printf(arg, philo->id, "is thinking");
			
		}
		if (philosophe.am_i_die == 1)
			return ((void *)&philosophe.am_i_die)
		if (philosophe_as_eaten_one == 1)
		{
			// utiliser un lock (mutex) different par fourchette
			// cela permet de les differncier et de savoir si oui ou non on peut les toucher
			// pour ne pas epnpecher les autre thread d'avancer leur excecuion
			// il suffit de differencier les locks 
			// un lock par resssource qu'on souhaite proteger
			pthread_mutex_lock(&(philosophe.start -> mutex_fork[philosophe.left]));
			pthread_mutex_lock(&(philosophe.start -> mutex_fork[philosophe.right]));
			pthread_mutex_lock(&(philosophe.start -> mutex_printf));
			printf_eating(milliseconds ,philosophe);
			is_eating(&philosophe);
			pthread_mutex_unlock(&(philosophe.start -> mutex_printf));
			pthread_mutex_unlock(philosophe.start -> mutex_fork[philosophe.right]);
			pthread_mutex_unlock(philosophe.start -> mutex_fork[philosophe.left]);
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
		while (i < start.nbr_philo)
    	{
			if (i + 1 <= start.nbr_philo - 1)
				philo_tab[i].left = i + 1;
			else
				philo_tab[i].left = 0;
			if (i - 1 < 0)
				philo_tab[i].right = start.nbr_philo - 1;
			else
				philo_tab[i].right =  0;
        	i++;
    	}
	}
}
int main(int argc, char *argv[])
{
	
    info start;
    pthread_t *ids;
	pthread_mutex_t mutex;
    philo *philo_tab;
	void *result;
    int i;
    i = 0;
    if (handle_error(argc, argv) == 0)
        return (0);
    start = fill_info(argc, argv);
	start.mutex = &mutex;
	if (start.nbr_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("0 died\n");
		return (0);
	}
    if (start.bonus == 0)
    {
        ids = malloc(sizeof(pthread_t) * start.nbr_philo);
        philo_tab = malloc(sizeof(philo) * start.nbr_philo);
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
		am_i_die()
        i = 0;
        while (i < start.nbr_philo)
        {
            if (pthread_join(ids[i], &result) != 0)
            {
                free(ids);
                free(philo_tab);
                printf("can't join threade nbr %i", i);
                return (0);
            }
            i++;
        }
		if ((int)result == 1)
		{
			free(ids);
			free(philo_tab);
			return (0);
		}
        free(ids);
        free(philo_tab);
    }
}

