/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:54:29 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/23 18:28:31 by imoumini         ###   ########.fr       */
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
	g->img_mini_map.mlx_img = mlx_new_image(g->mlx_ptr, 64 * g->column, 64 * g->ligne);
	g->img_mini_map.addr = mlx_get_data_addr(g->img_mini_map.mlx_img, &g->img_mini_map.bpp, &g->img_mini_map.line_len, &g->img_mini_map.endian);
}


void	ft_render_mini_map_while(t_game *g, int i, int j)
{
	if (g->tab[i][j] == '1')
	{
		printf("c1\n");
		printf("i is =>%i, j is =>%i\n", i, j);
		printf("olumn =>%i, ligne =>%i\n\n", g->column, g->ligne);
		printf("column*64 =>%i, ligne*64 =>%i\n", 64 * g->column, 64 * g->ligne);
		render_rect(g, (t_rect){64*i,64*j,WHITE}, &g->img_mini_map);
		printf("c1 bis\n");
		// exit(0);
	}
	if (g->tab[i][j] == '0')
	{
		printf("c2\n");
		render_rect(g, (t_rect){64*i,64*j,BLACK}, &g->img_mini_map);
	}
	if (g->tab[i][j] == 'P')
	{
		printf("c3\n");
		render_line(g, (t_rect){i*64,j*64, RED}, &g->img_mini_map);
		//render_line_up((t_rect){i*40,j*31, 32 * g->column, 1 * g->ligne, RED}, &g->img_mini_map);
	}
}

void	ft_render_mini_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->tab[i] != NULL)
	{
		printf("c0\n");
		while (g->tab[i][j] != '\0')
		{
			printf("c0 bis\n");
			ft_render_mini_map_while(g, i, j);
			if (j == 2)
				return ;
			printf("c0 bi bis\n");
			j++;
		}
		j = 0;
		i++;
	}
}


void	ft_put_img_to_window(t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
}