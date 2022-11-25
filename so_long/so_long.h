/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:37:49 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 22:07:32 by imoumini         ###   ########.fr       */
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
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# define WIDTH 64 * game.column
# define LENGTH 64 * game.line
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
	void	*mlx_ptr;
	void	*win_ptr;
	char	**tab;
	void	*img_grass;
	void	*img_house;
	void	*img_tree;
	void	*img_warrior;
	void	*img_mushroom;
	int		img_width;
	int		img_height;
	int		walk;
	char	**tab_copy;
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
int		right_car(char **tab);
char 	*fill_tab_while(char **tab, char *p, int fd);
char	*allocate_column_while(char **tab, char *p, int fd);
void	ft_free_map(t_game game, char **tab);
void	ft_test(t_game game, char **tab);
t_game	check_map_part(char *argv);
void ft_put_img_to_window(t_game game);
int	handle_input(int key, t_game *game);
void move_d(t_game *game);
void move_s(t_game *game);
void move_a(t_game *game);
void move_w(t_game *game);
void ft_free_mlx_error(void *ptr);
int	check_dot(char *str);
int check_ber(char *str);
int	ft_strcmp(char *s1, char *s2);
void ft_destroy_map(t_game *game);
int ft_result_false_after_path(t_game game, char** tab, t_game testvalidpath);
int ft_result_false_before_path(t_game game);
void ft_destroy_map_image_error(t_game *game);
int handle_click(t_game *game);
void put_image_to_null(t_game *game);
void ft_check_mlx_ptr(t_game *game);
void ft_check_win_ptr(t_game *game);
void ft_check_first(int argc, char *argv[]);
void ft_image(t_game *game);
void ft_free_map_before_path(t_game game);
#endif 
