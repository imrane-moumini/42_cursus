/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/23 18:26:26 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	printf("c4\n");
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	printf("c5\n");
	*(int *)pixel = color;
	printf("c6\n");
}


int render_rect(t_game *g, t_rect rect, t_img *img)
{
	int	i;
	int j;

	if (g->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img_pix_put(img, j + rect.x , i + rect.y , rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int render_line(t_game *g, t_rect rect, t_img *img)
{
	// int	i;
	// int j;
	if (g->win_ptr == NULL)
		return (1);
	// i = rect.y;
	// while (i < rect.y + rect.height)
	// {
	// 	j = rect.x;
	// 	while (j < rect.x + rect.width)
			img_pix_put(img, rect.x, rect.y, rect.color);
	// 	++i;
	// }
	// j = 32;
	return (0);
}
// int render_line_up(t_rect rect, t_img *img)
// {
// 	int	i;
// 	int j;
	
// 	j = rect.x;
// 	while (j < (rect.x) + (rect.width/6))
// 	{
// 		i = rect.y;
// 		while (i < rect.y + (rect.height+5))
// 		{
// 			img_pix_put(img, j, i++, rect.color);
// 		}
// 		j++;
// 	}
// 	return (0);
// }

int	fill_image(t_game *g)
{
	ft_render_mini_map(g);
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
    g.win_ptr = mlx_new_window(g.mlx_ptr, 64 * g.column, 64 * g.ligne, "CUB3D");
    if (g.win_ptr == NULL)
	{
		free(g.win_ptr);
		return (1);
	}
	ft_image(&g);
	fill_image(&g);
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
	ft_put_img_to_window(&g);
    mlx_loop(g.mlx_ptr);
	mlx_destroy_window(g.mlx_ptr, g.win_ptr);
    mlx_destroy_display(g.mlx_ptr);
    free(g.mlx_ptr);
}
// faire cadrilage au debut
// faire juste un pixel pour le personnage
// faire deplacement du personnage
	// avancer, reculer, rotation
// ajout laser tout droit
// ajout laser vu devant lui
// faire ray casting
