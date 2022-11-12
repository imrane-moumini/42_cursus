/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/12 17:31:05 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"






int main(int argc, char *argv[])
{
	int i;
	int save;
	char **tab;
	int number_of_ligne;
	int number_of_column;
	int testcar;
	int testrect;
	int testclose;
	int testvalidpath;
	s_game	game;
	
	game.tab = NULL;
	i = 0;
	if (argc != 2)
		return(1);
	game.tab = allocate_line(game.tab, argv[1]);
	if (game.tab == NULL)
		return (1);
	game.tab = allocate_column(game.tab, argv[1]);
	if (game.tab == NULL)
		return (1);
	game.tab = fill_tab(game.tab, argv[1]);
	
	
	testcar = is_car_ok(game.tab);
	number_of_column = nb_column(game.tab);
	number_of_ligne = nb_ligne(argv[1]);
	game.tab_number_of_column = number_of_column;
	game.tab_number_of_ligne = number_of_ligne;
	testrect = is_car_rect(game.tab, number_of_ligne, number_of_column);
	testclose = is_car_close(game.tab, number_of_ligne, number_of_column);
	find_start_position(game.tab, &game);
	nbr_of_collectible(game.tab, &game);
	tab = tab_copy(game.tab, number_of_column, number_of_ligne);
	testvalidpath = is_path_valid(tab, game);

	if (testcar == 0 || testrect == 0 || testclose == 0 || testvalidpath == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	
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

	save = number_of_ligne;
	while (number_of_ligne  >= 0)
	{
		free(game.tab[number_of_ligne]);
		number_of_ligne--;
	}
	free(game.tab);

 	while (save  >= 0)
 	{
 		free(tab[save]);
 		save--;
 	}
 	free(tab);
}