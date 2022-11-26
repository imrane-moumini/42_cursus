/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:53:57 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/26 14:26:58 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_destroy_map(t_game *game)
{
	mlx_destroy_image(game -> mlx_ptr, game -> house);
	mlx_destroy_image(game -> mlx_ptr, game -> grass);
	mlx_destroy_image(game -> mlx_ptr, game -> tree);
	mlx_destroy_image(game -> mlx_ptr, game -> warrior);
	mlx_destroy_image(game -> mlx_ptr, game -> mushroom);
	mlx_destroy_display(game -> mlx_ptr);
	ft_free_map(*game, game -> tab_copy);
	free(game -> mlx_ptr);
	exit(1);
}

void	ft_free_map_before_path(t_game game)
{
	while (game.ligne >= 0)
	{
		free(game.tab[game.ligne]);
		game.ligne--;
	}
	free(game.tab);
}

void	ft_free_map(t_game game, char **tab)
{
	int	save;

	save = game.ligne;
	while (game.ligne >= 0)
	{
		free(game.tab[game.ligne]);
		game.ligne--;
	}
	free(game.tab);
	while (save >= 0)
	{
		free(tab[save]);
		save--;
	}
	free(tab);
}
