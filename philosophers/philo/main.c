/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:22 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/15 21:30:51 by imoumini         ###   ########.fr       */
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
    if (argv[5])
    {
        start.nbr_eat_allow = ft_atoi(argv[5]);
        start.bonus = 1;
    }
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

void *action()
{
    printf("well done\n");
    return (NULL);
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
    int i;
    i = 0;
    if (handle_error(argc, argv) == 0)
        return (0);
    start = fill_info(argc, argv);
    if (start.bonus == 0)
    {
        ids = malloc(sizeof(pthread_t) * start.nbr_philo);
        while (i < start.nbr_philo)
        {
            if (pthread_create(ids + i, NULL, &action, NULL) != 0)
            {
                free(ids);
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
                printf("can't join threade nbr %i", i);
                return (0);
            }
            i++;
        }
        free(ids);
    }
}

