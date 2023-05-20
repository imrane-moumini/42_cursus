/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:54:29 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/20 21:01:28 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_click(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	//ft_destroy_map(game);
	exit(0);
}

int	handle_input(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		//ft_destroy_map(game);
		exit(0);
	}
	// if (key == XK_w)
	// 	move_w(game);
	// if (key == XK_a)
	// 	move_a(game);
	// if (key == XK_s)
	// 	move_s(game);
	// if (key == XK_d)
	// 	move_d(game);
	return (0);
}

void	ft_image(t_game *g)
{
	g->img_wall.mlx_img = mlx_new_image(g->mlx_ptr, 600, 300);
	g->img_wall.addr = mlx_get_data_addr(g->img_wall.mlx_img, &g->img_wall.bpp, &g->img_wall.line_len, &g->img_wall.endian);
	g->img_perso.mlx_img = mlx_new_image(g->mlx_ptr, 600, 300);
	g->img_perso.addr = mlx_get_data_addr(g->img_perso.mlx_img, &g->img_perso.bpp, &g->img_perso.line_len, &g->img_perso.endian);
	g->img_floor.mlx_img = mlx_new_image(g->mlx_ptr, 600, 300);
	g->img_floor.addr = mlx_get_data_addr(g->img_floor.mlx_img, &g->img_floor.bpp, &g->img_floor.line_len, &g->img_floor.endian);
}


void	ft_put_img_to_window_while(t_game *g, int i, int j)
{
	if (g->tab[i][j] == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_wall.mlx_img, 0, 0);
	if (g->tab[i][j] == '0')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_floor.mlx_img, 20, 20);
	if (g->tab[i][j] == 'P')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_perso.mlx_img, 10, 10);
}

void	ft_put_img_to_window(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->tab[i] != NULL)
	{
		while (g->tab[i][j] != '\0')
		{
			ft_put_img_to_window_while(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}