/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:28 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/17 20:27:58 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct philo{
	int index;
	long long time_start;
	int t_die;
	int t_eat;
	int t_sleep;
	int nbr_eat_allow;
	int is_eating;
} philo;

typedef struct info{
	int nbr_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int nbr_eat_allow;
	int bonus;
	long long time_start;
} info;

int ft_atoi(const char *nptr);
int handle_error(int argc, char *argv[]);
int ft_nbr(char c);
info fill_info(int argc, char *argv[]);
void *action(void *arg);
void fill_philo_tab(philo *philo_tab, info start);