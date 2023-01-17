/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/17 20:47:30 by imoumini         ###   ########.fr       */
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
void get_time(long long *milliseconds)
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == -1)
		return;
	*milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
void *action(void *arg)
{
	long long milliseconds;
	
    get_time(&milliseconds);
    philo philosophe = *(philo *)arg;
	printf("time : %lld ", milliseconds - philosophe.time_start);
    printf("my index is %i\n", philosophe.index);
    // passer le philo en param avec ttes ses infos
    // afficher l'index du philosophe
    return (NULL);
}

void fill_philo_tab(philo *philo_tab, info start)
{
    int i;
    philo philosophe;
    
    i = 0;
    philosophe.t_die = start.t_die;
    philosophe.t_eat = start.t_eat;
    philosophe.t_sleep = start.t_sleep;
    if (start.bonus == 1)
        philosophe.nbr_eat_allow = start.nbr_eat_allow;
    philosophe.is_eating = 0;
	philosophe.time_start = start.time_start;
    while(i < start.nbr_philo)
    {
        philo_tab[i] = philosophe;
        i++;
    }
    i = 0;
    while(i < start.nbr_philo)
    {
        philo_tab[i].index = i + 1;
        i++;
    }
}
int main(int argc, char *argv[])
{
    // convertir chaque argument en chiffre
    // creer le nombre de philosophe suffisant
    // enregistrer les inbfos de chaque philosophe
    // recuperer le temps
    // afficher dans un premier temps ce que chqaue philosophe fait

    // un thread = un philosophe
    // une fonction qui comtient toutes les actions
    info start;
    pthread_t *ids;
    philo *philo_tab;
    int i;
    i = 0;
    if (handle_error(argc, argv) == 0)
        return (0);
    start = fill_info(argc, argv);
    if (start.bonus == 0)
    {
        ids = malloc(sizeof(pthread_t) * start.nbr_philo);
        philo_tab = malloc(sizeof(philo) * start.nbr_philo);
        fill_philo_tab(philo_tab, start);
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

