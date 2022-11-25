/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:16:20 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 22:02:24 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	right_car(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != '0' && tab[i][j] != '1'
				&& tab[i][j] != 'C' && tab[i][j] != 'E'
				&& tab[i][j] != 'P')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int ft_result_false_before_path(t_game game)
{
	if (game.testcar == 0 )
	{
		ft_printf("error false caracter\n");
		ft_free_map_before_path(game);
		exit (1);
	}
	if ( game.testrect == 0)
	{
		ft_printf("error map is not a rectangle\n");
		ft_free_map_before_path(game);
		exit (1);
	}
	if (game.testclose == 0  )
	{
		ft_printf("error map is not close\n");
		ft_free_map_before_path(game);
		exit (1);
	}
	return (1);
	
}

int ft_result_false_after_path(t_game game, char** tab, t_game testvalidpath)
{
	if (testvalidpath.map_nb_of_c != game.nb_of_c)
	{
		ft_printf("error no valid path\n");
		ft_free_map(game, tab);
		exit (1);
	}
	
	if (testvalidpath.is_an_exit != 1)
	{
		ft_printf("error no valid path\n");
		ft_free_map(game, tab);
		exit (1);
	}
	return (1);
	
}

t_game check_map_part(char *argv)
{
	t_game game;

	game.tab = NULL;
	game.tab = allocate_line(game.tab, argv);
	if (game.tab == NULL)
	{
		free(game.tab);	
		exit(1);
	}
	game.tab = allocate_column(game.tab, argv);
	if (game.tab == NULL)
	{
		free(game.tab);	
		exit(1);
	}
	game.tab = fill_tab(game.tab, argv);
	game.testcar = is_car_ok(game.tab);
	game.column = nb_column(game.tab);
	game.ligne = nb_ligne(argv);
	game.testrect = is_car_rect(game.tab, game.ligne, game.column);
	game.testclose = is_car_close(game.tab, game.ligne, game.column);
	return (game);
}

