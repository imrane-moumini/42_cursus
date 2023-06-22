/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:53 by imoumini          #+#    #+#             */
/*   Updated: 2023/06/22 20:46:50 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double degree_to_radian(double degree)
{
	return ((degree * PI) / 180);
}

int draw_line(t_game *g, int x, int y)
{
	int j;
	if (g->win_ptr == NULL)
		return (1);
	j = 0;
	while (j + x < g->column *64)
	{
		// faut que je rajoute une notion de degre
		// en gros avce un angle il faut que jadapte les coordonnee x et y pour avoir le bon angle
		// le x reste fixe, le y je le bouge mais pas en 1 ou 2 en un truc plus pr2cis
		img_pix_put(&g->img_mini_map, j + x, y, RED);
		j++;
	}
	return (0);
}
// je rempli la fonction puis je gère le bail pour qu'il le fasse autnt de fois que width ecran
void save_wall_length(t_game *g, double angle, int i)
{
    // faut que jajoute dans la fonction qui appelle celle quiu lappelle la notion i++ taille width
    
    double dist;
    double hauteur;
    double angleInRadians = angle * (PI / 180.0);
    int newX = g->first_x + (int)(g->last_x * cos(angleInRadians));
    int newY = g->first_y + (int)(g->last_y* sin(angleInRadians));
    int dx = abs(newX - g->first_x);
    if (dx < 0)
        dx = dx * -1;
    int dy = abs(newY - g->first_y);
    if (dy < 0)
    {
        dy = dy * -1;
    }
    g->texture[i] = (int)g->last_y % g->warrior.heigth_y;

	double distx = ((double)g->first_x - g->last_x);
	if (distx < 0)
		distx *= -1;
    
	double disty = ((double)g->first_y - g->last_y);
	if (disty < 0)
		disty *= -1;
        
    dist= sqrt( (distx * distx) + (disty * disty));
    // dist= sqrt( (dx *dx) + (dy * dy));
    //hauteur = (((g->column)/2)/tan(30)* 64)/dist;
    //printf("hauteur AVANT : %f\n", dist);
    hauteur = ((277 * 3) * 64)/dist;
    // hauteur = (64 / dist * 277);
    //printf("hauteur APRES : %f\n", hauteur);
    //printf("i is %i\n", i);
    g->wall_tab[i] = hauteur;
    
    g->tab_length++;
    //printf("hauteur is %f\n", hauteur);
    //hauteur de la colonne sur l'ecran = (dist_ecran x hauteur_mur) / dist;
}
void drawLine_angle(int x, int y, double angle,t_game *g, int i)
{
    (void)i;
    //printf("angle is %f\n", angle);
    double angleInRadians = angle * (PI / 180.0);  // Conversion degrés -> radians
    int newX = x + (int)(g->column *64 * cos(angleInRadians));
    int newY = y + (int)(g->ligne *64 * sin(angleInRadians));
    //static int e = 0;
    //static int f = 0;
    //static int h = 0;
    // Dessiner le trait entre les points (x, y) et (newX, newY)
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    int sx = (x < newX) ? 1 : -1;
    int sy = (y < newY) ? 1 : -1;
    int err = dx - dy;
    //enregister la valeur du premier x et du premier y dans g 
    g->first_x = x;
    g->first_y = y;
    // deja dans la boucle den dessous jy suis pleins de fopis donc faut pas se dire une fois par appel
    // ok je rentre dans la fonction 2561 fois mais seulement 121 fois dans in wall
    

    while ((x != newX || y != newY ) && (x < g->column * 64) && (y < g->ligne*64))
    {
        // normalement je dois avoir 1000 trait et me souvenir de 1000 truc
        if (x > 0 && y > 0 && in_wall(x, y, g) == 0 /*&& i<= 60*/)
        {

            img_pix_put(&g->img_mini_map, x, y, RED);
            //printf("h is :%i\n",h);
            //h++;
            //printf("i is %i\n",i);
        }
        //printf("f is %i\n", f);
        //f++;
        //printf("counter is %i\n",g->counter);
        // counter retourne a 0 c'est pour ça que ca recommence
        if (in_wall(x, y, g) == 1)
        {
            g->last_x = x;
            g->last_y = y;
            
            //printf("e is %i\n", e);
            //e++;
            if (g->counter <= SCREEN_WIDTH)
                save_wall_length(g, angle * (60/(SCREEN_WIDTH)),g->counter++);
            //printf("%i\n",g->counter);
            //projection(g->column * 64, g->ligne *64, (g->column)/2, ((g->column)/2)/tan(30), 60/g->column);
            break;
        }
        int err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}
void print_gnode(t_coor *head)
{
    if (!head)
        return;
    t_coor *ptr;
    ptr = head;
    int count;
    count = 0;
    while (ptr)
    {
        count++;
        ptr = ptr -> next;
    }
    printf("%i\n", count);
}



void ft_fill_3Dmap(t_game *g)
{
    double i = 0;
    int j = 0;
    while (i <= SCREEN_WIDTH)
    {
        drawLine_angle_3D2(i, g, g->wall_tab[j]);
        if (j < g->tab_length)
            j++;
        i++;
    }
 
}


void drawLine_angle_3D2(int x, t_game *g, double hauteur)
{
    double	i;
    int color;
    //x = x + (60/(g->column*64));
    // printf("hauteur avant : %f\n", hauteur);
    double debut_mur = ((SCREEN_LENGTH)/2) - (hauteur/2); 
    // debut_mur = hauteur;
    // double taille_mur = // rc.printy = (Y_3D / 2) - (rc.tab[rc.index] / 2);
    // printf("hauteur apres : %f\n", debut_mur);
    /* debut mur est inverse donc c'est bon*/
    if (debut_mur < 0)
    {
        debut_mur = 0;
    }
	if (g->win_ptr == NULL)
		return;
	i = 0;
    //printf("x is :%i\n", x);
    
    //printf("hauteur is: %f, ", hauteur);
    //printf("%f\n", i);
    color = ft_draw_wall_ratio(g, hauteur, x);
	while (i < SCREEN_LENGTH)
	{
        
        //printf("debut mur = %f\n", debut_mur);
        // printf("i :%f ; debut mur : %f, (debut_mur + hauteur) : %f\n", i, debut_mur, (debut_mur + hauteur));
        if (i >= debut_mur && i < (debut_mur + hauteur))
        {
            // printf("c1 : x %i, i %i\n", x, (int)i);
            img_pix_put(&g->cub3dmap, x, i, color);
        }
        i++;
	}
    //printf("i :%f ; debut mur : %f, (debut_mur + hauteur) : %f\n", i, debut_mur, (debut_mur + hauteur));
}
