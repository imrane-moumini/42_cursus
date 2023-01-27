/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:28 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/27 21:56:31 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H 
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct info{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				end_of_eat;
	int				nbr_eat_allow;
	int				stop;
	int				bonus;
	long long		time_start;
	pthread_t		ids[300];
	pthread_mutex_t	mutex_forks[300];
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_eat_time;
	pthread_mutex_t	mutex_end_of_eat;
	pthread_mutex_t	mutex_finish;
	pthread_mutex_t	mutex_finish_eat;
}	t_info;

typedef struct philo{
	int			index;
	long long	time_start;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			nbr_eat_allow;
	long long	last_time_eat;
	int			left;
	int			right;
	t_info		*start;
}	t_philo;

int			ft_atoi(const char *nptr);
int			ft_atoi_parsing(const char *nptr);
long		ft_atoi_long_parsing(char *str);
int			handle_first_error(int argc, char *argv[]);
int			handle_second_error(int argc, char *argv[]);
int			ft_nbr(char c);
t_info		fill_info(int argc, char *argv[]);
void		*action(void *arg);
void		fill_philo_tab(t_philo *philo_tab, t_info *start);
long long	get_time(void);
void		add_pos_to_philo(t_philo *philo_tab, t_info start);
void		printf_eating(t_philo *philosophe);
int			am_i_die(t_philo *philo_tab, int nbr_philo, t_info *start);
void		i_am_sleeping(t_philo philosophe);
void		i_am_thinking(t_philo philosophe);
void		philo_wait_to_avoid_deadlock(t_philo philo);
int			init_mutex(t_info *start);
t_philo		*create_threads(t_info *start);
int			join_threads(t_info *start, t_philo *philo_tab);
void		destroy_element(t_philo *philo_tab, t_info *start);
int			finish_eat(int count);
void		eating(t_philo *philo);
void		time_to_think(t_philo *philo);
void		died(t_philo philosophe, t_info *start);
int			count_nbr_of_car(long nb);
int			check_only_number(char *str);
int			check_int_limit(char **argv);
int			check_negative(int argc, char *argv[]);
int			has_finished_eat(t_philo *philosophe);
#endif