/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:53:57 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 22:07:59 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_destroy_map(t_game *game)
{
	mlx_destroy_image(game -> mlx_ptr, game -> img_house);
	mlx_destroy_image(game -> mlx_ptr, game -> img_grass);
	mlx_destroy_image(game -> mlx_ptr, game -> img_tree);
	mlx_destroy_image(game -> mlx_ptr, game -> img_warrior);
	mlx_destroy_image(game -> mlx_ptr, game -> img_mushroom);
	mlx_destroy_display(game -> mlx_ptr);
	ft_free_map(*game, game -> tab_copy);
	free(game -> mlx_ptr);
	exit(1);
}

void ft_free_map_before_path(t_game game)
{
	while (game.ligne  >= 0)
	{
		free(game.tab[game.ligne]);
		game.ligne--;
	}
	free(game.tab);
}
void ft_free_map(t_game game, char **tab)
{
	int save;
	
	save = game.ligne;
	while (game.ligne  >= 0)
	{
		free(game.tab[game.ligne]);
		game.ligne--;
	}
	free(game.tab);
 	while (save  >= 0)
 	{
 		free(tab[save]);
 		save--;
 	}
 	free(tab);
}