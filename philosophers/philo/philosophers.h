/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:28 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/21 17:57:52 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct info{
	int nbr_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int nbr_eat_allow;
	int bonus;
	long long time_start;
	pthread_mutex_t mutex_forks[300];
	pthread_mutex_t mutex_printf;
} info;

typedef struct philo{
	int index;
	long long time_start;
	int t_die;
	int t_eat;
	int t_sleep;
	int nbr_eat_allow;
	int is_eating;
	long long last_time_eat;
	int left;
	int right;
	int as_eaten_one;
	int am_i_die;
	info *start;
} philo;



int ft_atoi(const char *nptr);
int handle_error(int argc, char *argv[]);
int ft_nbr(char c);
info fill_info(int argc, char *argv[]);
void *action(void *arg);
void fill_philo_tab(philo *philo_tab, info *start);
long long get_time();
void add_pos_to_philo(philo *philo_tab, info start);
void is_eating(philo *philosophe);
void printf_eating(philo philosophe);
int am_i_die(philo *philo_tab, int nbr_philo);
void i_am_sleeping(philo philosophe);
void i_am_thinking(philo philosophe);