/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:54:26 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 22:08:17 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void put_image_to_null(t_game *game)
{
	game -> img_grass = NULL;
	game -> img_house = NULL;
	game -> img_tree = NULL;
	game -> img_warrior = NULL;
	game -> img_mushroom = NULL;
}

void ft_image(t_game *game)
{
		game->img_grass = mlx_xpm_file_to_image(game->mlx_ptr, "./image/Grass.xpm", \
		&game -> img_width, &game -> img_height);
	if (!game->img_grass)
		ft_destroy_map_image_error(game);
	game->img_house = mlx_xpm_file_to_image(game->mlx_ptr, "./image/House.xpm", \
		&game->img_width, &game->img_height);
	if (!game->img_house)
		ft_destroy_map_image_error(game);
	game->img_tree = mlx_xpm_file_to_image(game->mlx_ptr, "./image/Tree.xpm", \
		&game->img_width, &game->img_height);
	if (!game->img_tree)
		ft_destroy_map_image_error(game);
	game->img_warrior = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/Warrior.xpm", &game->img_width, &game->img_height);
	if (!game->img_warrior)
		ft_destroy_map_image_error(game);
	game->img_mushroom = mlx_xpm_file_to_image(game->mlx_ptr,\
		 "./image/Mushroom_01.xpm", &game->img_width, &game->img_height);
	if (!game->img_mushroom)
		ft_destroy_map_image_error(game);
}

void ft_put_img_to_window(t_game game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game.tab[i] != NULL )
	{
		while (game.tab[i][j] != '\0')
		{
			if (game.tab[i][j] == '1')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_tree, j * 64, i * 64);
			if (game.tab[i][j] == '0')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_grass, j * 64, i * 64);
			if (game.tab[i][j] == 'P')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_warrior, j * 64, i * 64);
			if (game.tab[i][j] == 'E')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_house, j * 64, i * 64);
			if (game.tab[i][j] == 'C')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_mushroom, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}