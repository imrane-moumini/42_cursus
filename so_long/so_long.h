/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:37:49 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/19 18:31:42 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		nb_of_c;
	int		map_nb_of_c;
	int		is_an_exit;
	int		ligne;
	int		column;
	int		testcar;
	int		testrect;
	int		testclose;
	char	**tab;
}				t_game;

char	**tab_copy(char **tab, int number_of_column, int number_of_ligne);
t_game	is_path_valid(char **t, t_game g);
t_game	initialize_flood_position_count(char **t, t_game g, t_game *result);
t_game	ft_right(t_game flood, t_game game);
t_game	ft_left(t_game flood, t_game game);
t_game	ft_down(t_game flood, t_game game);
t_game	ft_up(t_game flood, t_game game);
void	nbr_of_collectible(char **tab, t_game *game);
void	find_start_position(char **tab, t_game *game);
int		nb_ligne(char *file);
int		nb_column(char **tab);
int		is_car_path_valid(char **tab);
int		is_car_rect(char **tab, int number_of_ligne, int number_of_column);
int		is_car_close(char **tab, int number_of_ligne, int number_of_column);
int		last_ligne(char **tab, int number_of_ligne);
int		first_ligne(char **tab);
int		is_car_ok(char **tab);
char	**fill_tab(char **tab, char *file);
char	**allocate_column(char **tab, char *file);
char	**allocate_line(char **tab, char *file);
int		column(char **tab, int number_of_column);
int		right_car(char **tab);
int		car_is_here(char **tab);
int		count_car(char **tab);
int		ft_c(char **tab);
int		ft_p(char **tab);
int		ft_e(char **tab);
int		ft_one(char **tab);
int		ft_zero(char **tab);
int		right_car(char **tab);
char 	*fill_tab_while(char **tab, char *p, int fd);
char	*allocate_column_while(char **tab, char *p, int fd);
#endif 
