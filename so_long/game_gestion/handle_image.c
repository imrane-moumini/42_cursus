/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:54:26 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/26 14:49:32 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_to_null(t_game *game)
{
	game -> grass = NULL;
	game -> house = NULL;
	game -> tree = NULL;
	game -> warrior = NULL;
	game -> mushroom = NULL;
}

void	ft_image(t_game *game)
{
		game->grass = mlx_xpm_file_to_image(game->mlx_ptr, "./image/Grass.xpm", \
		&game -> img_width, &game -> img_height);
	if (!game->grass)
		ft_destroy_map_image_error(game);
	game->house = mlx_xpm_file_to_image(game->mlx_ptr, "./image/House.xpm", \
		&game->img_width, &game->img_height);
	if (!game->house)
		ft_destroy_map_image_error(game);
	game->tree = mlx_xpm_file_to_image(game->mlx_ptr, "./image/Tree.xpm", \
		&game->img_width, &game->img_height);
	if (!game->tree)
		ft_destroy_map_image_error(game);
	game->warrior = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/Warrior.xpm", &game->img_width, &game->img_height);
	if (!game->warrior)
		ft_destroy_map_image_error(game);
	game->mushroom = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./image/Mushroom_01.xpm", &game->img_width, &game->img_height);
	if (!game->mushroom)
		ft_destroy_map_image_error(game);
}

void	ft_put_img_to_window_while(t_game g, int i, int j)
{
	if (g.tab[i][j] == '1')
		mlx_put_image_to_window(g.mlx_ptr, \
			g.win_ptr, g.tree, j * 64, i * 64);
	if (g.tab[i][j] == '0')
		mlx_put_image_to_window(g.mlx_ptr, \
			g.win_ptr, g.grass, j * 64, i * 64);
	if (g.tab[i][j] == 'P')
		mlx_put_image_to_window(g.mlx_ptr, \
			g.win_ptr, g.warrior, j * 64, i * 64);
	if (g.tab[i][j] == 'E')
		mlx_put_image_to_window(g.mlx_ptr, \
			g.win_ptr, g.house, j * 64, i * 64);
	if (g.tab[i][j] == 'C')
		mlx_put_image_to_window(g.mlx_ptr, \
			g.win_ptr, g.mushroom, j * 64, i * 64);
}

void	ft_put_img_to_window(t_game g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g.tab[i] != NULL)
	{
		while (g.tab[i][j] != '\0')
		{
			ft_put_img_to_window_while(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
