/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:33:51 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/18 20:53:46 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_start_position(char **tab, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'P')
			{
				game -> x = j;
				game -> y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	nbr_of_collectible(char **tab, t_game *game)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'C')
			{
				counter++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	game -> nb_of_c = counter;
}

void	initialize_position(char **tab, t_game game, int *count_c)
{
	if (tab[game.y][game.x] == 'C')
		*count_c = *count_c +1;
	tab[game.y][game.x] = '1';
}

t_game	initialize_flood_position_count(char **tab, t_game game, int *count_c)
{
	t_game	flood;

	flood.ligne = game.ligne;
	flood.column = game.column;
	flood.nb_of_c = game.nb_of_c;
	initialize_position(tab, game, count_c);
	return (flood);
}

char	**tab_copy(char **tab, int number_of_column, int number_of_ligne)
{
	char	**tab_copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_copy = ft_calloc(number_of_ligne + 1, sizeof(char *));
	tab_copy[number_of_ligne] = NULL;
	while (i < number_of_ligne)
		tab_copy[i++] = ft_calloc(number_of_column + 1, sizeof(char));
	i = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			tab_copy[i][j] = tab[i][j];
			j++;
		}
		tab_copy[i][j] = '\0';
		j = 0;
		i++;
	}
	return (tab_copy);
}
