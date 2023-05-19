/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/19 21:36:12 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int render_rect_wall(t_game *g, t_rect rect)
{
	int	i;
	int j;

	if (g->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(&g->img_wall, j++, i, rect.color);
		++i;
	}
	return (0);
}
int render_rect_perso(t_game *g, t_rect rect)
{
	int	i;
	int j;

	if (g->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(&g->img_perso, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_game *g)
{
		render_rect_wall(g, (t_rect){g->x_wall, g->y_wall, 10, 10, WHITE});
		render_rect_perso(g, (t_rect){g->x_perso,g->y_perso , 10, 10, RED});
		render_rect_floor(g, (t_rect){g->x_floor, g->y_floor, 10, 10, WHITE});
		render_rect_laser(g, (t_rect){g->x_laser,g->y_laser , 10, 10, RED});
		render_rect_view(g, (t_rect){g->x_view,g->y_view , 10, 10, RED});
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_wall.mlx_img, 0, 0);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_perso.mlx_img, 0, 0);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_floor.mlx_img, 0, 0);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_laser.mlx_img, 0, 0);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_view.mlx_img, 0, 0);
	return (0);
}
int main(int argc, char *argv[])
{
    t_game g;
	//char	**tab;
    (void)argc;
    (void)argv;
    
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
	mlx_loop_hook(g.mlx_ptr, &render, &g);
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
    mlx_loop(g.mlx_ptr);
	mlx_destroy_window(g.mlx_ptr, g.win_ptr);
    mlx_destroy_display(g.mlx_ptr);
    free(g.mlx_ptr);
    printf("everything is ok\n");
}
