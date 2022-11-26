/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/26 15:10:08 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**tab;
	t_game	testvalidpath;
	t_game	g;

	ft_check_first(argc, argv);
	g = check_map_part(argv[1]);
	find_start_position(g.tab, &g);
	nbr_of_collectible(g.tab, &g);
	ft_result_false_before_path(g);
	tab = tab_copy(g.tab, g.column, g.ligne);
	g.tab_copy = tab;
	testvalidpath = is_path_valid(tab, g);
	ft_result_false_after_path(g, tab, testvalidpath);
	g.mlx_ptr = mlx_init();
	ft_check_mlx_ptr(&g);
	g.win_ptr = mlx_new_window(g.mlx_ptr, 64 * g.column, 64 * g.ligne, "M");
	ft_check_win_ptr(&g);
	g.walk = 0;
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, &handle_input, &g);
	mlx_hook(g.win_ptr, DestroyNotify, StructureNotifyMask, &handle_click, &g);
	put_image_to_null(&g);
	ft_image(&g);
	ft_put_img_to_window(g);
	mlx_loop(g.mlx_ptr);
}
