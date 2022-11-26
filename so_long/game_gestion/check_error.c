/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:53:44 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/26 14:26:27 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_first(int argc, char *argv[])
{
	if (argc != 2)
		exit (1);
	if (check_ber(argv[1]) == 0)
		exit (1);
}

void	ft_check_mlx_ptr(t_game *game)
{
	if (game -> mlx_ptr == NULL)
		ft_free_mlx_error(game -> mlx_ptr);
}

void	ft_check_win_ptr(t_game *game)
{
	if (game -> win_ptr == NULL)
		ft_free_mlx_error(game -> win_ptr);
}

void	ft_destroy_map_image_error(t_game *game)
{
	ft_printf("image error, wrong path\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game -> house)
		mlx_destroy_image(game -> mlx_ptr, game -> house);
	if (game -> grass)
		mlx_destroy_image(game -> mlx_ptr, game -> grass);
	if (game -> tree)
		mlx_destroy_image(game -> mlx_ptr, game -> tree);
	if (game -> warrior)
		mlx_destroy_image(game -> mlx_ptr, game -> warrior);
	if (game -> mushroom)
		mlx_destroy_image(game -> mlx_ptr, game -> mushroom);
	mlx_destroy_display(game -> mlx_ptr);
	ft_free_map(*game, game -> tab_copy);
	free(game -> mlx_ptr);
	exit(1);
}

int	check_ber(char *str)
{
	char	*ber;
	int		i;

	i = 0;
	ber = ".ber";
	if (check_dot(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (ft_strcmp(str + i, ber) != 0)
				return (0);
		}
		i++;
	}
	return (1);
}
