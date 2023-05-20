/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:46 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/20 19:19:51 by imoumini         ###   ########.fr       */
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

#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define VIOLET 0x7f00ff
#define RED 0xFF0000

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
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
	t_img	img_wall;
	t_img	img_floor;
	t_img	img_perso;
	t_img	img_laser;
	t_img	img_view;

	int x;
	int y;
	
}				t_game;

/* game gestion*/
int	handle_click(t_game *game);
int	handle_input(int key, t_game *game);

#endif