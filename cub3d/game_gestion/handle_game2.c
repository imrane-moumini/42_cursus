/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:59:09 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/24 20:00:49 by imoumini         ###   ########.fr       */
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
	g->pos_pers.x = g->pos_pers.x + 10;
	rect.x = g->pos_pers.x;
	rect.y = g->pos_pers.y;
	render_perso(g, rect, &g->img_mini_map);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_mini_map.mlx_img, 0, 0);
	// je peux pas juste inverser les cases dams le tab ca ferait de trop grand boom
	// je dois effacer le point rouge dans limage et raficher a nouveau limage par dessus
}
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

