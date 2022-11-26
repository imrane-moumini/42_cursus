/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:54:08 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/26 15:12:19 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_game *g)
{
	find_start_position(g -> tab, g);
	if (g -> y - 1 >= 0 && g -> tab[g -> y - 1][g -> x] == 'E'\
		&& g -> nb_of_c == 0)
		handle_click(g);
	if (g -> y - 1 >= 0 && g -> tab[g -> y - 1][g -> x] == 'C')
		g -> nb_of_c = g -> nb_of_c - 1;
	if (g -> y - 1 >= 0 && g -> tab[g -> y - 1][g -> x] != '1'\
		&& g -> tab[g -> y - 1][g -> x] != 'E')
	{
		g -> tab[g -> y - 1][g -> x] = 'P';
		g -> tab[g -> y][g -> x] = '0';
		g -> walk = g -> walk + 1;
		ft_printf("Tu as fait %i coups\n", g -> walk);
		ft_put_img_to_window(*g);
	}
}

void	move_a(t_game *g)
{
	find_start_position(g -> tab, g);
	if (g -> x - 1 >= 0 \
		&& g -> tab[g -> y][g -> x - 1] == 'E' && g -> nb_of_c == 0)
		handle_click(g);
	if (g -> x - 1 >= 0 && g -> tab[g -> y][g -> x - 1] == 'C')
		g -> nb_of_c = g -> nb_of_c - 1;
	if (g -> x - 1 >= 0 && g -> tab[g -> y][g -> x - 1] != '1'\
		&& g -> tab[g -> y][g -> x - 1] != 'E')
	{
		g -> tab[g -> y][g -> x -1] = 'P';
		g -> tab[g -> y][g -> x] = '0';
		g -> walk = g -> walk + 1;
		ft_printf("Tu as fait %i coups\n", g -> walk);
		ft_put_img_to_window(*g);
	}
}

void	move_s(t_game *g)
{
	find_start_position(g -> tab, g);
	if (g -> y + 1 < g -> ligne \
		&& g -> tab[g -> y + 1][g -> x] == 'E' && g -> nb_of_c == 0)
		handle_click(g);
	if (g -> y + 1 < g -> ligne && g -> tab[g -> y + 1][g -> x] == 'C')
		g -> nb_of_c = g -> nb_of_c - 1;
	if (g -> y + 1 < g -> ligne && g -> tab[g -> y + 1][g -> x] != '1'\
		&& g -> tab[g -> y + 1][g -> x] != 'E')
	{
		g -> tab[g -> y + 1][g -> x] = 'P';
		g -> tab[g -> y][g -> x] = '0';
		g -> walk = g -> walk + 1;
		ft_printf("Tu as fait %i coups\n", g -> walk);
		ft_put_img_to_window(*g);
	}
}

void	move_d(t_game *g)
{
	find_start_position(g -> tab, g);
	if (g -> x + 1 < g -> column \
		&& g -> tab[g -> y][g -> x + 1] == 'E' && g -> nb_of_c == 0)
		handle_click(g);
	if (g -> x + 1 < g -> column && g -> tab[g -> y][g -> x + 1] == 'C')
		g -> nb_of_c = g -> nb_of_c - 1;
	if (g -> x + 1 < g -> column && g -> tab[g -> y][g -> x + 1] != '1' \
		&& g -> tab[g -> y][g -> x + 1] != 'E')
	{
		g -> tab[g -> y][g -> x + 1] = 'P';
		g -> tab[g -> y][g -> x] = '0';
		g -> walk = g -> walk + 1;
		ft_printf("Tu as fait %i coups\n", g -> walk);
		ft_put_img_to_window(*g);
	}
}
