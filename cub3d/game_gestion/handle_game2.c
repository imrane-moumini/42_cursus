/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:59:09 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/27 16:49:50 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_d(t_game *g)
{
	t_rect rect;
	mlx_destroy_image(g -> mlx_ptr, g->img_mini_map.mlx_img);
	// j'avamce de 10
	ft_image(g);
	ft_render_mini_map_without_perso(g); 
	if (g->pos_pers->x + 10 < g->column *64)
	g->pos_pers->x = g->pos_pers->x + 10;
	rect.x = g->pos_pers->x;
	rect.y = g->pos_pers->y;
	rect.color = WHITE;
	// quand je bouge normal pas bouger les degree
	// en fait quand j'appelle render_perso_rect faut que je lui envoi le premier pixel du coup pixel actuel -60
	// c meem plus precis que ca pasque si je tourne en vriter bah je vais pas faire -60 bref
	// en gros faut que qund je bouge je reste au dernier degreer de depart
	render_perso_rect(g, rect, &g->img_mini_map);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
}

void move_a(t_game *g)
{
	t_rect rect;
	mlx_destroy_image(g -> mlx_ptr, g->img_mini_map.mlx_img);
	// j'avamce de 10
	ft_image(g);
	ft_render_mini_map_without_perso(g); 
	if (g->pos_pers->x - 10 > 0)
	g->pos_pers->x = g->pos_pers->x - 10;
	rect.x = g->pos_pers->x;
	rect.y = g->pos_pers->y;
	rect.color = WHITE;
	render_perso_rect(g, rect, &g->img_mini_map);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
}

void move_w(t_game *g)
{
	t_rect rect;
	mlx_destroy_image(g -> mlx_ptr, g->img_mini_map.mlx_img);
	// j'avamce de 10
	ft_image(g);
	ft_render_mini_map_without_perso(g); 
	if (g->pos_pers->y - 10 > 0)
		g->pos_pers->y = g->pos_pers->y - 10;
	rect.x = g->pos_pers->x;
	rect.y = g->pos_pers->y;
	rect.color = WHITE;
	render_perso_rect(g, rect, &g->img_mini_map);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
}

void move_s(t_game *g)
{
	t_rect rect;
	mlx_destroy_image(g -> mlx_ptr, g->img_mini_map.mlx_img);
	// j'avamce de 10
	ft_image(g);
	ft_render_mini_map_without_perso(g);
	if (g->pos_pers->y + 10 < g->ligne *64)
		g->pos_pers->y = g->pos_pers->y + 10;
	rect.x = g->pos_pers->x;
	rect.y = g->pos_pers->y;
	rect.color = WHITE;
	render_perso_rect(g, rect, &g->img_mini_map);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
}
// en vrai c facile g juste a faire + 1 jusqa arriver a 360 et revenir a 0;
// em fait faut que je donne les degree dans la fonction meme appelant 
// a chaque fois aue je le rappelle je met a jour langle dans lequel je me trouve


// je trace des degreee et jincremente le compteur
// jobtien la valeur du dernier degree, ya 60 rayon tracer
// je dois tjr avoir une vue a 60 degree


// x = ligne
// y = column
// comme ils inversent column et igne bah moi ausi dans mon t_game je fois inverser
void	trace_line(t_game *g)
{
	// tracer toutes les 64 y et toutes les 64 ligne jusquq qrriver dans les taille slimites
	int i;
	int j;

	i = 0; // ligne
	j = 0; // column
	while (i*64 < g->ligne *64)
	{
		j = 0;
		while(j < g->column *64)
		{
			img_pix_put(&g->img_mini_map, j, i*64 , GREEN);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (j*64 < g->column *64)
	{
		i = 0;
		while(i < g->ligne *64)
		{
			img_pix_put(&g->img_mini_map, j*64, i , GREEN);
			i++;
		}
		j++;
	}
}

