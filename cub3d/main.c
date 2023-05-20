/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/20 20:26:32 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	//printf("pix 1\n");
	// ca veut dire que le x ou le y est trop grand
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	//printf("pix 2\n");
	//printf("pix 3\n");
	*(int *)pixel = color;
	//printf("pix 4\n");
}


int render_rect(t_game *g, t_rect rect, t_img *img)
{
	int	i;
	int j;

	if (g->win_ptr == NULL)
		return (1);
	i = rect.y;
	//printf("--------------------------------------------------\n");
	//printf("y is %i\n", rect.y);
	//printf("x is %i\n", rect.x);
	//printf("c4\n");
	while (i < rect.y + rect.height)
	{
		//printf("c5\n");
		j = rect.x;
		//printf("c6\n");
		while (j < rect.x + rect.width)
		{
			//printf("c7\n");
			//printf("i is :%i\n", i);
			//printf("j is :%i\n", j);
			//printf("rect.x + rect.width is :%i\n",rect.x + rect.width );
			img_pix_put(img, j++, i, rect.color);
		}
		++i;
	}
	return (0);
}

int	render(t_game *g)
{
	//printf("c1\n");
	render_rect(g, (t_rect){0,0, 10, 10, WHITE}, &g->img_wall);
	//printf("c2\n");
	render_rect(g, (t_rect){0,0, 10, 10, RED}, &g->img_perso);
	//printf("c3\n");
	render_rect(g, (t_rect){0,0, 10, 10, VIOLET}, &g->img_floor);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_wall.mlx_img, 0, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_perso.mlx_img, 10, 10);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_floor.mlx_img, 20, 20);
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
    g.win_ptr = mlx_new_window(g.mlx_ptr, 600, 300, "CUB3D");
    if (g.win_ptr == NULL)
	{
		free(g.win_ptr);
		return (1);
	}

	g.img_wall.mlx_img = mlx_new_image(g.mlx_ptr, 600, 300);
	g.img_wall.addr = mlx_get_data_addr(g.img_wall.mlx_img, &g.img_wall.bpp, &g.img_wall.line_len, &g.img_wall.endian);
	g.img_perso.mlx_img = mlx_new_image(g.mlx_ptr, 600, 300);
	g.img_perso.addr = mlx_get_data_addr(g.img_perso.mlx_img, &g.img_perso.bpp, &g.img_perso.line_len, &g.img_perso.endian);
	g.img_floor.mlx_img = mlx_new_image(g.mlx_ptr, 600, 300);
	g.img_floor.addr = mlx_get_data_addr(g.img_floor.mlx_img, &g.img_floor.bpp, &g.img_floor.line_len, &g.img_floor.endian);
	mlx_loop_hook(g.mlx_ptr, &render, &g);
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
    mlx_loop(g.mlx_ptr);
	mlx_destroy_window(g.mlx_ptr, g.win_ptr);
    mlx_destroy_display(g.mlx_ptr);
    free(g.mlx_ptr);
    //printf("everything is ok\n");
}

// recuperer la map
// afficher la map a lecran avec technique so long +  new tech
