/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:53 by imoumini          #+#    #+#             */
/*   Updated: 2023/06/18 20:49:36 by imoumini         ###   ########.fr       */
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
    

	double distx = ((double)g->first_x - g->last_x);
	if (distx < 0)
		distx *= -1;
    
	double disty = ((double)g->first_y - g->last_y);
	if (disty < 0)
		disty *= -1;
        
    dist= sqrt( (distx * distx) + (disty * disty));
    // dist= sqrt( (dx *dx) + (dy * dy));
    //hauteur = (((g->column)/2)/tan(30)* 64)/dist;
    // hauteur = (277 * 64)/dist;
    hauteur = (64 / dist * 277);
    g->wall_tab[i] = hauteur;
    
    /*
    double pi = 3.1415926535897932384626433832;
    double resultx = 10 * sin((angle) * pi / 180);
    double resulty = 10 * cos((angle) * pi / 180);
    double pixelx = g->first_x; 
	double pixely = g->first_y;
    int pixels = sqrt((resultx * resultx) + (resulty * resulty));
	resultx /= pixels;
	resulty /= pixels;
    double distx = ((double)g->first_x - pixelx);
	if (distx < 0)
		distx *= -1;
	double disty = ((double)g->first_y - pixely);
	if (disty < 0)
		disty *= -1;
    g->wall_tab[i] = sqrt((distx * distx) + (disty * disty));
    */
    printf("debut mur = %f\n", ((g->ligne * 64)/2) - (sqrt(hauteur)/2));
    printf("i is %i\n",i);
    
    g->tab_length++;
    printf("hauteur is %f\n", hauteur);
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
    //printf("width is %i\n", g->column * 64);
    while (i <= SCREEN_WIDTH )
    {
        //drawLine_angle_3D(64, 64, i,g, g->wall_tab[j++]);
        
        drawLine_angle_3D2(i, g, g->wall_tab[j]);
        if (j < g->tab_length)
            j++;
        //projection(g->column * 64, g->ligne *64, (g->column)/2, ((g->column)/2)/tan(30), 60/g->column);
        //i = i + (60/(g->column*64));
        //printf("i is :%f\n", i);
        //printf("j is :%i\n", j);
        i++;
        // faut avancer jusqua la fin de la width
        // faut avancer le j de telle sorte a ce que ca fasse tout le tab
        // faut aussi que je modifie le y de debut pour donner cette impression


    }
    printf("i is :%f\n", i);
    /*
    while (j <= g->tab_length)
    {
        //drawLine_angle_3D(64, 64, i,g, g->wall_tab[j++]);
        
        drawLine_angle_3D2(i, g, g->wall_tab[j]);
        
        //projection(g->column * 64, g->ligne *64, (g->column)/2, ((g->column)/2)/tan(30), 60/g->column);
        i = i + (60/(g->column*64));
        //printf("i is :%f\n", i);
        //printf("j is :%i\n", j);
        j++;
        // faut avancer jusqua la fin de la width
        // faut avancer le j de telle sorte a ce que ca fasse tout le tab
        // faut aussi que je modifie le y de debut pour donner cette impression


    }
    */
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
    //printf("im here\n");
}

void drawLine_angle_3D2(int x, t_game *g, double hauteur)
{
    double	i;
    //x = x + (60/(g->column*64));
    printf("hauteur avant : %f\n", hauteur);
    double debut_mur = ((SCREEN_LENGTH)/2) - (hauteur/2); // CONVERSION
    // debut_mur = hauteur;
    // double taille_mur = // rc.printy = (Y_3D / 2) - (rc.tab[rc.index] / 2);
    printf("hauteur apres : %f\n", debut_mur);
    /* debut mur est inverse donc c'est bon*/
    if (debut_mur < 0)
    {
        debut_mur = 0;
    }
	if (g->win_ptr == NULL)
		return;
	i = 0;
    // tu commence a (g->ligne/2) - (hauteur/2) et tu dessine pixel
    // un mur qui prend tout lecranb prend toute la longeur de lecran
    // pk entre ici et la boucle while le x diminue
    //printf("x is :%i\n", x);
    
    //printf("hauteur is: %f, ", hauteur);
    //printf("%f\n", i);
    // i et hauteur = 0 donc rentre pqs dedqns
    
	while (i < SCREEN_LENGTH)
	{
        
        //printf("debut mur = %f\n", debut_mur);
        // printf("i :%f ; debut mur : %f, (debut_mur + hauteur) : %f\n", i, debut_mur, (debut_mur + hauteur));
        if (i >= debut_mur && i < (debut_mur + hauteur))
        {
            // printf("c1 : x %i, i %i\n", x, (int)i);
            img_pix_put(&g->cub3dmap, x, i, RED);
        }
        i++;
	}
    //printf("i :%f ; debut mur : %f, (debut_mur + hauteur) : %f\n", i, debut_mur, (debut_mur + hauteur));

    //printf("put pixel in 3D\n");
    /*  il faut diviser par deux au milieu */
}

//void projection(int with_screen, int length_screen, int center, int dist_screen, int angle_2_rayon_cons)
//{

//}