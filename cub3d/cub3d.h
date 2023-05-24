/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:46 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/24 18:19:30 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

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

#define BLUE 0x0000FF
#define BLACK 0x000000
#define VIOLET 0x7f00ff
#define RED 0xFF0000
#define GREEN 0x00FF00

typedef struct s_rect
{
	int	x;
	int	y;
	int color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len; /*nbr de bytes que represente une ligne sur notre image*/
	int		endian;
}	t_img;

typedef struct s_game
{
	/* ptr de minilibx et window*/
	void	*mlx_ptr;
	void	*win_ptr;
	/* img property*/
	t_img	img_mini_map;

	int x;
	int y;
	int ligne;
	int column;
	char **tab;
	
}				t_game;

/* game gestion*/
int	handle_click(t_game *game);
int	handle_input(int key, t_game *game);

/*fill double tab*/
void	print_double_tab(char **str);
char	**allocate_line(char **tab, char *file);
char	*allocate_column_while(char **tab, char *p, int fd);
char	**allocate_column(char **tab, char *file);
char	*fill_tab_while(char **tab, char *p, int fd);
char	**fill_tab(char **tab, char *file);
int		nb_column(char **tab);
int		nb_ligne(char *file);

/*img gestion*/
void	ft_image(t_game *g);
void	ft_put_img_to_window(t_game *g);
void	ft_render_mini_map(t_game *g);
void	ft_render_mini_map_while(t_game *g, int i, int j);
void	img_pix_put(t_img *img, int x, int y, int color);
int 	render_rect(t_game *g, t_rect rect, t_img *img);
int 	render_line(t_game *g, t_rect rect, t_img *img);
int		fill_image(t_game *g);
void	trace_line(t_game *g);
/*mouvement*/
void move_d(t_game *g);

#endif