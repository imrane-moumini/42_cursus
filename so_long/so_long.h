/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:37:49 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/17 23:24:55 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



typedef struct	s_point
{
	int			ps_x;
	int			ps_y;
	int			nb_of_c;
	int			is_an_exit;
	int 		tab_nbligne;
	int 		tab_nbcolumn;
	char **		tab;
}				s_game;

char **tab_copy(char **tab, int number_of_column, int number_of_ligne);
int is_path_valid(char **t, s_game g);
s_game initialize_flood_and_position_and_count(char **tab, s_game game, int *count_c);
void initialize_position(char **tab, s_game game, int *count_c);
s_game ft_right(s_game flood, s_game game);
s_game ft_left(s_game flood, s_game game);
s_game ft_down(s_game flood, s_game game);
s_game ft_up(s_game flood, s_game game);
void nbr_of_collectible(char **tab, s_game *game);
void find_start_position(char **tab, s_game *game);
int nb_ligne(char *file);
int nb_column(char **tab);
int is_car_path_valid(char **tab);
int is_car_rect(char **tab, int number_of_ligne, int number_of_column);
int is_car_close(char **tab, int number_of_ligne, int number_of_column);
int is_car_ok(char **tab);
char **fill_tab(char **tab, char *file);
char **allocate_column(char **tab, char *file);
char **allocate_line(char **tab, char *file);
#endif 
