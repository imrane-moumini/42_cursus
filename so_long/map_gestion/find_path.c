/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:33:51 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/19 17:51:40 by imoumini         ###   ########.fr       */
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

t_game	initialize_flood_position_count(char **t, t_game g, t_game *result)
{
	t_game	flood;

	flood.ligne = g.ligne;
	flood.column = g.column;
	flood.nb_of_c = g.nb_of_c;
	if (g.y - 1 >= 0 && t[g.y - 1][g.x] == 'E')
		result -> is_an_exit = 1;
	if (g.y + 1 < g.ligne && t[g.y + 1][g.x] == 'E')
		result -> is_an_exit = 1;
	if (g.x - 1 >= 0 && t[g.y][g.x - 1] == 'E')
		result -> is_an_exit = 1;
	if (g.x + 1 < g.column && t[g.y][g.x + 1] == 'E')
		result -> is_an_exit = 1;
	if (t[g.y][g.x] == 'C')
		result -> map_nb_of_c = result -> map_nb_of_c + 1;
	t[g.y][g.x] = '1';
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
