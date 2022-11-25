/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:54:02 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 22:08:03 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int handle_click(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_destroy_map(game);
	return (0);
}


int	handle_input(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		ft_destroy_map(game);
	}
	if (key == XK_w)
		move_w(game);
	if (key == XK_a)
		move_a(game);
	if (key == XK_s)
		move_s(game);
	if (key == XK_d)
		move_d(game);
	return (0);
}