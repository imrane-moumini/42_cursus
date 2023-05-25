/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:53 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/25 21:41:56 by imoumini         ###   ########.fr       */
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

void drawLine_angle(t_img *img, int x, int y, double angle, int length,t_game *g)
{
    double angleInRadians = angle * (PI / 180.0);  // Conversion degrés -> radians
    int newX = x + (int)(length * cos(angleInRadians));
    int newY = y + (int)(length * sin(angleInRadians));

    // Dessiner le trait entre les points (x, y) et (newX, newY)
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    int sx = (x < newX) ? 1 : -1;
    int sy = (y < newY) ? 1 : -1;
    int err = dx - dy;
	printf("c1\n");
    while ((x != newX || y != newY ) && x < g->column *64 && y < g->ligne*64)
    {
        img_pix_put(img, x, y, RED);
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
		printf("c2\n");
    }
	printf("im here\n");
}
