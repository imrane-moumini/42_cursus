/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:14:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/23 18:32:03 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	car_is_here(char **tab)
{
	if (ft_one(tab) == 0)
		return (0);
	if (ft_c(tab) == 0 || ft_e(tab) == 0 || ft_p(tab) == 0)
		return (0);
	return (1);
}

int	count_car(char **tab)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	i = 0;
	j = 0;
	count_e = 0;
	count_p = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'E')
				count_e++;
			if (tab[i][j] == 'P')
				count_p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count_e > 1 || count_p > 1)
		return (0);
	return (1);
}

int	is_car_ok(char **tab)
{
	if (right_car(tab) == 0)
		return (0);
	if (car_is_here(tab) == 0)
		return (0);
	if (count_car(tab) == 0)
		return (0);
	return (1);
}

int	first_ligne(char **tab)
{
	int	j;

	j = 0;
	if (tab[1] != NULL)
	{
		while (tab[0][j] != '\0')
		{
			if (tab[0][j] != '1')
				return (0);
			j++;
		}	
	}
	return (1);
}

int	last_ligne(char **tab, int number_of_ligne)
{
	int	j;

	j = 0;
	if (tab[number_of_ligne -1] != NULL)
	{
		while (tab[number_of_ligne -1][j] != '\0')
		{
			if (tab[number_of_ligne -1][j] != '1')
				return (0);
			j++;
		}	
	}
	return (1);
}
