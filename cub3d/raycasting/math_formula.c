/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:53 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/27 20:05:30 by imoumini         ###   ########.fr       */
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

void drawLine_angle(int x, int y, double angle,t_game *g)
{
    // 30 et 330
    // if (angle < 0)
    //     angle = angle * -1;
    // if (angle > 0)
    //     angle = 360 - angle;
    double angleInRadians = angle * (PI / 180.0);  // Conversion degrés -> radians
    int newX = x + (int)(g->column *64 * cos(angleInRadians));
    int newY = y + (int)(g->ligne *64 * sin(angleInRadians));

    // Dessiner le trait entre les points (x, y) et (newX, newY)
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    int sx = (x < newX) ? 1 : -1;
    int sy = (y < newY) ? 1 : -1;
    int err = dx - dy;
    while ((x != newX || y != newY ) && (x < g->column * 64 && x > 0) && (y < g->ligne*64 && y > 0))
    {
        // printf("c2\n");
	    // printf("c1 x %i y %i\n", x, y);
        if (in_wall(x, y, g) == 0)
            img_pix_put(&g->img_mini_map, x, y, RED);
        // printf("c3\n");
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
		// printf("c2\n");
    }
	// printf("im here\n");
}
