/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:53 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/25 20:49:29 by imoumini         ###   ########.fr       */
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
		// faut que jenvoi a 60 degre a partir de ce trait
		img_pix_put(&g->img_mini_map, j + x, y, RED);
		j++;
	}
	return (0);
}