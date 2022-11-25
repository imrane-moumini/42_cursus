/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:54:08 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 22:08:13 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_w(t_game *game)
{
	find_start_position(game -> tab, game);
	if (game -> y - 1 >= 0 && game -> tab[game -> y - 1][game -> x] == 'E' && game -> nb_of_c == 0)
		handle_click(game);
	if (game -> y - 1 >= 0 && game -> tab[game -> y - 1][game -> x] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}
	if (game -> y - 1 >= 0 && game -> tab[game -> y - 1][game -> x] != '1' && game -> tab[game -> y - 1][game -> x] != 'E')
	{
			game -> tab[game -> y - 1][game -> x] = 'P';
			game -> tab[game -> y][game -> x] = '0';
			game -> walk = game -> walk + 1;
			ft_printf("Tu as fait %i coups\n", game -> walk);
			ft_put_img_to_window(*game);	
	}
}
void move_a(t_game *game)
{
	find_start_position(game -> tab, game);
	if (game -> x - 1 >= 0 &&  game -> tab[game -> y][game -> x - 1] == 'E' && game -> nb_of_c == 0)
		handle_click(game);
	if(game -> x - 1 >= 0 && game -> tab[game -> y][game -> x - 1] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}	
	if (game -> x - 1 >= 0 && game -> tab[game -> y][game -> x - 1] != '1' && game -> tab[game -> y][game -> x - 1] != 'E')
	{
		
		game -> tab[game -> y][game -> x -1 ] = 'P';
		game -> tab[game -> y][game -> x] = '0';
		game -> walk = game -> walk + 1;
		ft_printf("Tu as fait %i coups\n", game -> walk);
		ft_put_img_to_window(*game);	
	}
	
}
void move_s(t_game *game)
{
	find_start_position(game -> tab, game);
	if(game -> y + 1 < game -> ligne && game -> tab[game -> y + 1][game -> x] == 'E' && game -> nb_of_c == 0 )
		handle_click(game);
	if(game -> y + 1 < game -> ligne && game -> tab[game -> y + 1][game -> x] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}
	if(game -> y + 1 < game -> ligne && game -> tab[game -> y + 1][game -> x] != '1' && game -> tab[game -> y + 1][game -> x] != 'E')
	{
		game -> tab[game -> y + 1][game -> x] = 'P';
		game -> tab[game -> y][game -> x] = '0';
		game -> walk = game -> walk + 1;
		ft_printf("Tu as fait %i coups\n", game -> walk);
		ft_put_img_to_window(*game);	
	}
}
void move_d(t_game *game)
{
	find_start_position(game -> tab, game);
	if (game -> x + 1 < game -> column && game -> tab[game -> y][game -> x + 1] == 'E' && game -> nb_of_c == 0)
		handle_click(game);
	if (game -> x + 1 < game -> column  && game -> tab[game -> y][game -> x + 1] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}
	if (game -> x + 1 < game -> column && game -> tab[game -> y][game -> x + 1] != '1' && game -> tab[game -> y][game -> x + 1] != 'E')
	{
		game -> tab[game -> y][game -> x + 1 ] = 'P';
		game -> tab[game -> y][game -> x] = '0';
		game -> walk = game -> walk + 1;
		ft_printf("Tu as fait %i coups\n", game -> walk);
		ft_put_img_to_window(*game);
	}

}