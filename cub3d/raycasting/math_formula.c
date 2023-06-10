/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:53 by imoumini          #+#    #+#             */
/*   Updated: 2023/06/02 16:18:49 by imoumini         ###   ########.fr       */
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
    int dy = abs(newY - g->first_y);
    dist= sqrt( (dx *dx) + (dy * dy));
    //hauteur = (((g->column)/2)/tan(30)* 64)/dist;
    hauteur = 277/dist;
    g->wall_tab[i] = hauteur;
    //printf("hauteur is %f\n", hauteur);
    //hauteur de la colonne sur l'ecran = (dist_ecran x hauteur_mur) / dist;
}
void drawLine_angle(int x, int y, double angle,t_game *g, int i)
{
    double angleInRadians = angle * (PI / 180.0);  // Conversion degrés -> radians
    int newX = x + (int)(g->column *64 * cos(angleInRadians));
    int newY = y + (int)(g->ligne *64 * sin(angleInRadians));

    // Dessiner le trait entre les points (x, y) et (newX, newY)
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    int sx = (x < newX) ? 1 : -1;
    int sy = (y < newY) ? 1 : -1;
    int err = dx - dy;
    int ok = 0;
    //enregister la valeur du premier x et du premier y dans g 
    g->first_x = x;
    g->first_y = y;
    while ((x != newX || y != newY ) && (x < g->column * 64 && x > 0) && (y < g->ligne*64 && y > 0))
    {
        if (in_wall(x, y, g) == 0 && i<= 60)
        {
            ok = 1;
            // en fait ça c'est 60 fois max
            img_pix_put(&g->img_mini_map, x, y, RED);
        }
        if (in_wall(x, y, g) == 1 && ok && g->counter <= g->column*64)
        {
            g->last_x = x;
            g->last_y = y;
            // ça c'est width fois
            save_wall_length(g, angle * (60/(g->column*64)),g->counter++);
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

//void projection(int with_screen, int length_screen, int center, int dist_screen, int angle_2_rayon_cons)
//{

// en fqit je fqis tout ce qui este n bqs pour connaitre la taille de tous le smurs en face de moi
// jenregistre la taille de tout ces murs + les éléments important qui vont avec
// une fois que j'aurais tous ces éléménet, j'appelle ma fonction projection avec ma boucle taille width et dessine
// chque trait dans lordre du tableau
// donc le gros algo que g en ba c'est juste pour sauvegarder les tailles, c pas pour dessiner direct
// du coup le gros algo en ba je lappele direct dans la fonction qui sait que ya un mur

// du coup 2 grande fonction
    // algo poour calculer taille mur (en bas)
    // tracer les murs basé sur les tailles des murs (projection)
// repeter la même logique quand on va bouger, dabord faire quand on bouge pas

//tab[g->column];
//tab[0] = taille de la premiere colonne a tracer

// en fait le but ça va etre de calculer la hauteur d'un trait d'un mur a tracer en colonne c tout
    // murs ont la même taille
    // hauteur de la caméra = moitié taille mur
    // on va projeter sur l'écran un rayon par colonne et non un rayon par pixel
    // dès q'un mur est detecté on traite la colonne à afficher entièrement
    // il y a autant de rayon à lancer que de colonnes autrement dit que la with
    // les rayons sont projeté depuis la hauteur de la caméra
    //le rapport entre le champ de vision (fov) et la taille de l'ecrqn donne l'angle entre chaque rayon

    // algo (a mettre dqns la fonction qui voit quand g toucher un mur)
        //A partir de l’angle de rotation (ce que la caméra regarde) on retire la moitié du champ de vision (donc 30°)
        //On part de la colonne 0 et on lance un rayon (boucle while)
            //On fait avancer le rayon tant qu’il ne rencontre pas un mur dans la map
            //On enregistre la distance parcourue par le rayon pour toucher le mur
                // pour calculer la distance du mur on fait: 
                    //Dist = racine_carrée ( difX² + difY² ) => difX = dx, difY = dy 
                    //difX: différence entre l'abscisse de la caméra et l'abscisse du mur touché
                    //difY: différence entre l'ordonnée de la caméra et l'ordonnée du mur touché
                        //int dx = abs(newX - x);
                        //int dy = abs(newY - y);
                        // x et y sont les x et y de depart du premier pixel coller a la camera
                        //int newX = x + (int)(g->column *64 * cos(angleInRadians));
                        //int newY = y + (int)(g->ligne *64 * sin(angleInRadians));
                        // je remplace g colum * 64 par le x qui touche le mur
                        // je remplace g ligne * 64 par le y qui touche le mur
                    //hauteur de la colonne sur l'ecran = (dist_ecran x hauteur_mur) / dist;
                // avec ça g les elements necessaire pour tracer la ligne sur lecran puis je passe a la colonne suivant avec la meem logique
                // normalement avec ces element si je bidouille drawline angle je suis capable de tracer le trait 
            //On ajoute l’angle suivant (donne la nouvelle colonne)
        //On répète l’opération jusqu’à atteindre l’autre côté du champ visuel. (fin boucle while)
//}

void ft_fill_3Dmap(t_game *g)
{
    // la il me faut un drawline adapté auy tracage de mur en 3D
    // la ya plus denotion de map c'est juste je trace tous les traits
    // jincremente les angles de 1 * cazlcul pour tracer le trait
    double i = 0;
    int j = 0;
    // faut que je trouve le x et le y dune colonne complete et que je les mets
    // en fait normalement le traity fait la taille de la hauteur
    // du coup faut je compare les x et y dans la fonction
    // faut que je passe la hauteur en argument
    while (i <= g->column * 64)
    {
        drawLine_angle_3D(64, 64, i,g, g->wall_tab[j]);
        i = i + (60/(g->column*64));
    }
}



void drawLine_angle_3D(int x, int y, double angle,t_game *g, double hauteur)
{
    double angleInRadians = angle * (PI / 180.0);  // Conversion degrés -> radians
    int newX = x + (int)(g->column *64 * cos(angleInRadians));
    int newY = y + (int)(g->ligne *64 * sin(angleInRadians));

    // Dessiner le trait entre les points (x, y) et (newX, newY)
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    int sx = (x < newX) ? 1 : -1;
    int sy = (y < newY) ? 1 : -1;
    int err = dx - dy;
    //enregister la valeur du premier x et du premier y dans g 
    g->first_x = x;
    g->first_y = y;
    int i = 0;
    while ((x != newX || y != newY ) && (x < g->column * 64 && x > 0) && (y < g->ligne*64 && y > 0))
    {
        if (i == hauteur)
            break;
        img_pix_put(&g->cub3dmap, x, y, RED);
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
        i++;
    }
}