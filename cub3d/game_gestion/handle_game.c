/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:54:29 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/27 19:25:58 by imoumini         ###   ########.fr       */
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
	if (key == XK_w)
		move_w(game);
	if (key == XK_a)
		move_a(game);
	if (key == XK_s)
		move_s(game);
	if (key == XK_d)
		move_d(game);
	if (key == XK_Left)
		move_left(game);
	if (key == XK_Right)
		move_right(game);
	return (0);
}

void	ft_image(t_game *g)
{
	g->img_mini_map.mlx_img = mlx_new_image(g->mlx_ptr, 64 * g->column, 64 * g->ligne);
	g->img_mini_map.addr = mlx_get_data_addr(g->img_mini_map.mlx_img, &g->img_mini_map.bpp, &g->img_mini_map.line_len, &g->img_mini_map.endian);
	g->cub3dmap.mlx_img = mlx_new_image(g->mlx_ptr, 64 * g->column, 64 * g->ligne);
	g->cub3dmap.addr = mlx_get_data_addr(g->cub3dmap.mlx_img, &g->cub3dmap.bpp, &g->cub3dmap.line_len, &g->cub3dmap.endian);
}


void	ft_render_mini_map_while(t_game *g, int i, int j)
{
	if (g->tab[i][j] == '1')
		render_rect(g, (t_rect){64*j,64*i,BLUE}, &g->img_mini_map);
	if (g->tab[i][j] == '0')
		render_rect(g, (t_rect){64*j,64*i,BLACK}, &g->img_mini_map);
	if (g->tab[i][j] == 'P')
		render_perso_rect(g, (t_rect){64*j,64*i,WHITE}, &g->img_mini_map);
}

void	ft_render_mini_map_while_without_perso(t_game *g, int i, int j)
{
	if (g->tab[i][j] == '1')
		render_rect(g, (t_rect){64*j,64*i,BLUE}, &g->img_mini_map);
	if (g->tab[i][j] == '0')
		render_rect(g, (t_rect){64*j,64*i,BLACK}, &g->img_mini_map);
}

void	ft_render_mini_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->tab[i] != NULL)
	{
		while (g->tab[i][j] != '\0')
		{
			ft_render_mini_map_while(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	trace_line(g);
	i = 0;
	g->pos_pers -> degree = g->pos_pers-> save.first;
	g->pos_pers-> save.first = g->pos_pers -> degree;
	// en fait faut que je fasse width fois mais 
	// drawline angle c que 60 pasque jecris que 60 rayon

	while (i <= g-> column * 64)
	{
		if (g->pos_pers -> degree == 360)
			g->pos_pers -> degree = 0;
		drawLine_angle(g->pos_pers->x, g->pos_pers->y, g->pos_pers -> degree++ , g, i);
		i++;
	}
	if (g->counter > g->column*64)
		g->counter = 0;
	g->pos_pers-> save.last = g->pos_pers -> degree;
}

void	ft_render_mini_map_without_perso(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->tab[i] != NULL)
	{
		while (g->tab[i][j] != '\0')
		{
			ft_render_mini_map_while_without_perso(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	trace_line(g);
}

void	ft_put_img_to_window(t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
	printf("no\n");
	mlx_put_image_to_window(g->mlx_ptr, g->win2_ptr, g->cub3dmap.mlx_img, 0, 0);
	printf("yes\n");
}
