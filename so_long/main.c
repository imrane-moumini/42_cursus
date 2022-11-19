/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/19 19:58:52 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// check maps in main
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
int ft_result_false(t_game game, char** tab, t_game testvalidpath)
{
	if (game.testcar == 0 || game.testrect == 0 || game.testclose == 0 
		|| testvalidpath.map_nb_of_c != game.nb_of_c || testvalidpath.is_an_exit != 1 )
	{
		ft_printf("error\n");
		ft_free_map(game, tab);
		return (0);
	}
	return (1);
	
}

void ft_test(t_game game, char **tab)
{
	int i;

	i = 0;
	ft_printf("the real one is :\n");
	while (game.tab[i] != NULL)
	{
		ft_printf("%s\n", game.tab[i]);
		i++;
	}
	ft_printf("------------------------------\n");
	ft_printf("the copy is :\n");
	i = 0;
	while (tab[i] != NULL)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
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
// lancer le jeux in main


int main(int argc, char *argv[])
{
	char **tab;
	t_game testvalidpath;
	t_game	game;
	
	if (argc != 2)
		return(1);
	game = check_map_part(argv[1]);
	find_start_position(game.tab, &game);
	nbr_of_collectible(game.tab, &game);
	tab = tab_copy(game.tab, game.column, game.ligne);
	testvalidpath = is_path_valid(tab, game);
	if (ft_result_false(game, tab, testvalidpath) == 0)
		return(1);
	ft_test(game, tab);
	ft_free_map(game, tab);
}