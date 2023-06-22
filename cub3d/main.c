/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/06/22 21:51:27 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_get_color(t_img *data, int x, int y)
{
	// bon clairement ya un truc dans la logique ou g faux
	// pasque si je bidouiille pour as avoir des 0 bah je casse la logique du coup voir avce mathieu
	char	*dst;
	 printf("get color before calcul \n");
	 printf("x is %i\n", x);
	 printf("y is %i\n", y);
	dst = data->addr + (y * data->line_len + x * 4);
	printf("get color after calcul \n");
	return (*(unsigned int *)dst);
}

int 	ft_draw_wall_ratio(t_game *g, double hauteur, int x)
{
	// x = le pixel en longueur de la fenetre faut que ca soit pas plus grand que la fenetre
	int		color;
	double	ratio;
	double	wall_size;
	// int		x;
	// int		y;

	wall_size = hauteur;
	// x = rc->printy + rc->i;
	// y = rc->index;
	//ratio = ((double)d.y / wall_size);
	printf("wall size is %f\n", wall_size);
	printf("x is %i\n", x);
	ratio = ((double)g->warrior.heigth_y / wall_size);
	//ratio *= rc->i;
	ratio *= (x + 1);
	printf("ratio is %f\n", ratio);
	color = ft_get_color(&g->warrior, g->texture[x], ratio);
	return (color);
	//ft_my_mlx_pixel_put(&v->ig2, x, y, color);
}

// void	ft_draw_texture_and_floor(t_v *v, t_raycast *rc)
// {
// 	while (rc->i <= rc->tab[rc->index] && (rc->printy + rc->i) <= 599)
// 	{
// 		if (rc->dir[rc->index] == 'N' && (rc->printy + rc->i) > 0)
// 			ft_draw_wall_ratio(v, v->walln, rc);
// 		if (rc->dir[rc->index] == 'S' && (rc->printy + rc->i) > 0)
// 			ft_draw_wall_ratio(v, v->walls, rc);
// 		if (rc->dir[rc->index] == 'O' && (rc->printy + rc->i) > 0)
// 			ft_draw_wall_ratio(v, v->wallw, rc);
// 		if (rc->dir[rc->index] == 'E' && (rc->printy + rc->i) > 0)
// 			ft_draw_wall_ratio(v, v->walle, rc);
// 		rc->i++;
// 	}
// 	while ((rc->printy + rc->i) > rc->tab[rc->index] 
// 	&& (rc->printy + rc->i) <= 599)
// 	{
// 		ft_my_mlx_pixel_put(&v->ig2, (rc->printy + rc->i), rc->index, 
// 		ft_rgb_to_int(0, v->valfrgb[0], v->valfrgb[1], v->valfrgb[2]));
// 		rc->i++;
// 	}
// }


int	ft_rgb_to_int(int t, int r, int g, int b)
{
	int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= t << 24;
	return (color);
}

double return_degree_start(char *tab[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!tab)
		return (0);
	//printf("im here \n");
	while (tab[i])
	{
		//printf("im here 2\n");
		j = 0;
		while(tab[i][j])
		{
			//printf("im here 3\n");
			if (tab[i][j] == 'E')
				return (330);
			if (tab[i][j] == 'N')
				return (240);
			if (tab[i][j] == 'W')
				return (150);
			if (tab[i][j] == 'S')
				return (60);
			j++;
		}
		i++;
	}
	return (0);
}

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
	double degreeincr = 60.00/(double)(SCREEN_WIDTH);
	while (i <= SCREEN_WIDTH)
	{
		if (g->pos_pers -> degree == 360)
			g->pos_pers -> degree = 0;
		//drawLine_angle(g->pos_pers->x, g->pos_pers->y, g->pos_pers -> degree , g, i);
		//g->pos_pers -> degree = g->pos_pers -> degree + (60/(g->column*64));
		//printf("angle is %f\n", g->pos_pers -> degree);
		// l'angle doit pas depasser les 60 degré du coup faut je multiplie par 0,6
		drawLine_angle(g->pos_pers->x, g->pos_pers->y, g->pos_pers -> degree , g, i);
		g->pos_pers -> degree = g->pos_pers -> degree + degreeincr;
		// printf("degree  is %f\n", g->pos_pers -> degree);
		// printf("i is %i\n", i);
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
	g.win2_ptr = mlx_new_window(g.mlx_ptr, SCREEN_WIDTH, SCREEN_LENGTH, "CUB3D");
	g.pos_pers = malloc(sizeof(t_pos));
	// g.pos_pers -> degree = 330;
	g.pos_pers -> degree = return_degree_start(g.tab);
	//printf("degree at first is %f\n",g.pos_pers -> degree);
	g.pos_pers-> save.first = g.pos_pers -> degree;
    if (g.win_ptr == NULL)
	{
		free(g.win_ptr);
		return (1);
	}
	g.counter = 0;
	g.tab_length = 0;
	g.warrior.mlx_img = mlx_xpm_file_to_image(g.mlx_ptr, "./walle.xpm", \
		&g.warrior.width_x, &g.warrior.heigth_y);
	printf("main g.warrior.heigth_y is %i\n", g.warrior.heigth_y);
	printf("main g.warrior.width.x is %i\n", g.warrior.width_x);
	save_wall(&g);
	print_gnode(g.node);
	ft_image(&g);
	fill_image(&g);
	g.warrior.mlx_img = mlx_get_data_addr(g.warrior.mlx_img, &g.warrior.bpp, &g.warrior.line_len, &g.warrior.endian);
	//printf("degree at end is %f\n",g.pos_pers -> degree);
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
	mlx_hook(g.win2_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win2_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
	printf("tab length is :%i\n",g.tab_length);
	ft_put_img_to_window(&g);
    mlx_loop(g.mlx_ptr);
	mlx_destroy_window(g.mlx_ptr, g.win_ptr);
    mlx_destroy_display(g.mlx_ptr);
    free(g.mlx_ptr);
}

// eyefish
// texture
// determiner la direction pour savoir quel mur mettre
// ciel et sol
// valgrind


// g faiut le debut de la logique 3D
// pour le moment je bosse sur move_D
// la quand hje fais ,le 3D sisncrit sur la fenetre 2D
// ca normalement c quand je vaistrop loin bah il ecrit sur la 2D