/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/06/18 20:47:58 by imoumini         ###   ########.fr       */
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
		printf("degree  is %f\n", g->pos_pers -> degree);
		printf("i is %i\n", i);
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
	// en fait quand je fais *0.6 ça fait une boucle trop grande et affiche rien
	// lui g limpression il utilise pas le i comme x mais pour faire ses calculs
	// du coup ya une logique que g pas capté qu'il faut q'uil m'explique
	// pasque dans le tuto ca dit le prochain trait je le trace au porchain degree 
	// donc normalement à i + 1 mais ca fonctionne pas
// g capté, en faut les 1000 rayons * 0,6 je lmes lances pas dans la fonction qui trace les traits
// je les lances dans la fonction qui est censé enregistrer les murs
// comme ça j'aurais 1000 murs et je pourrais bien reporter la chose
// mais g l'impression que c'est ce que g fait quand g enregistré 1000 valeurs dans le tab
// g testé de le rajouter quand meme dans la boucle qui apple drawline (elle appelle aussi save_wall) mais rebelotte ça prend trop de temps
// de toute facon il faut lancer 1000 rayon dans 60 degré donc soit je met la le calcul soit je le met dans le truc qui met les lignes
// mais je pense que c la ou je me souvien des hauteurs, dans tous les cas ca fonctionne pas, voir avec mathieu
// je suis pas sur si ma technique pour detecter un mur est compatible avec lalgo, voir avec mathieu et si c bon voir
// si je calcule bien les murs
// en fait g l'impression que cest dans la fonction ou il dessine
// le straits qu'il calcuul la hauteur sauf que je vois pas a quel moment
// il voit un mur
// dans sa boucle il incremente un i qui represente les degré mais je comprends pas 
// ce qu'il en faitr en fait. 
// dans sa logique ca voudrait dire il a deja les hauteur des murs
// au moment de smurs mais meme ca jsuis pas sur
// bon en fait faut qu'il m'explique son code sinon je vais jamais capter
// vraiment chaque ligne
// la g vu que sa loigique est totaklmeent differernet
// il fait tout en meme temps danbs ldraw_line_dir3d
// g l'impression qu'il reutilse meme plus la map 2D
// sacahnt que la fonction draw_line_dir3D est longue de ouf et g pas tout capté