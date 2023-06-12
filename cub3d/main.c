/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/06/02 16:06:14 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}


int render_rect(t_game *g, t_rect rect, t_img *img)
{
	int	i;
	int j;

	if (g->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < 64 && (i + rect.y < g->ligne *64))
	{
		j = 0;
		while (j < 64 && (j + rect.x < g->column *64))
		{
			img_pix_put(img, j + rect.x , i + rect.y , rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int render_perso_rect(t_game *g, t_rect rect, t_img *img)
{
	int	i;
	int j;
	if (g->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < 10 && (i + rect.y < g->ligne *64))
	{
		j = 0;
		while (j < 10 && (j + rect.x < g->column *64))
		{
			img_pix_put(img, j + rect.x , i + rect.y , rect.color);
			j++;
		}
		i++;
	}
	g->pos_pers->x = rect.x;
	g->pos_pers->y = rect.y;
	g->pos_pers -> degree = g->pos_pers-> save.first;
	g->pos_pers-> save.first = g->pos_pers -> degree;
	i = 0;
	while (i <= g-> column * 64)
	{
		if (g->pos_pers -> degree == 360)
			g->pos_pers -> degree = 0;
		//drawLine_angle(g->pos_pers->x, g->pos_pers->y, g->pos_pers -> degree , g, i);
		//g->pos_pers -> degree = g->pos_pers -> degree + (60/(g->column*64));
		//printf("angle is %f\n", g->pos_pers -> degree);
		// l'angle doit pas depasser les 60 degré du coup faut je multiplie par 0,6
		drawLine_angle(g->pos_pers->x, g->pos_pers->y, g->pos_pers -> degree++ , g, i);
		//printf("i is %i\n", i);
		i++;
	}
	//if (g->counter > g->column*64)
		//g->counter = 0;
	//printf("g column is %d\n",g-> column * 64);
	g->pos_pers-> save.last = g->pos_pers -> degree;
	return (0);
}

int	fill_image(t_game *g)
{
	ft_render_mini_map(g);
	ft_fill_3Dmap(g);
	return (0);
}
int main(int argc, char *argv[])
{
    t_game g;
    if (argc < 1)
		return (0);
	g.tab = NULL;
	g.tab = allocate_line(g.tab, argv[1]);
	if (g.tab == NULL)
	{
		free(g.tab);
		exit(1);
	}
	g.tab = allocate_column(g.tab, argv[1]);
	if (g.tab == NULL)
	{
		free(g.tab);
		exit(1);
	}
	g.tab = fill_tab(g.tab, argv[1]);
	print_double_tab(g.tab);
	g.column = nb_column(g.tab);
	g.ligne = nb_ligne(argv[1]);
    g.mlx_ptr = mlx_init();
    if (g.mlx_ptr == NULL)
		return (1);
    g.win_ptr = mlx_new_window(g.mlx_ptr, 64 * g.column, 64 * g.ligne, "Minimap");
	g.win2_ptr = mlx_new_window(g.mlx_ptr, 64 * g.column, 64 * g.ligne, "CUB3D");
	g.pos_pers = malloc(sizeof(t_pos));
	g.pos_pers -> degree = 330;
	g.pos_pers-> save.first = g.pos_pers -> degree;
    if (g.win_ptr == NULL)
	{
		free(g.win_ptr);
		return (1);
	}
	g.counter = 0;
	g.tab_length = 0;
	save_wall(&g);
	print_gnode(g.node);
	ft_image(&g);
	fill_image(&g);
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
	printf("tab length is :%i\n",g.tab_length);
	ft_put_img_to_window(&g);
    mlx_loop(g.mlx_ptr);
	mlx_destroy_window(g.mlx_ptr, g.win_ptr);
    mlx_destroy_display(g.mlx_ptr);
    free(g.mlx_ptr);
}
// mathieu doit m'expliquer son code sur comment il a calculer les murs
// regler l'histoire de normalement le 60 degré et du coup les 60 traits doit
// etre sur une vue a g->column*64 n(du coup multiplier le 1 par 0.6) pour eviter les repetitions
//voir pk ça ça fait que rien ne saffiche dans les 2 fenetres => i = i + (60/(g->column*64));