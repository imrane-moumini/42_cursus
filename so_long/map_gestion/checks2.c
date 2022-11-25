/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:13:29 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 19:56:25 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	column(char **tab, int number_of_column)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (j == 0)
			{
				if (tab[i][j] != '1')
					return (0);
			}
			if (j == number_of_column - 1)
			{
				if (tab[i][j] != '1')
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_car_close(char **tab, int number_of_ligne, int number_of_column)
{
	if (first_ligne(tab) == 0)
		return (0);
	if (last_ligne(tab, number_of_ligne) == 0)
		return (0);
	if (column(tab, number_of_column) == 0)
		return (0);
	return (1);
}

int	is_car_rect(char **tab, int number_of_ligne, int number_of_column)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (number_of_column == number_of_ligne)
		return (0);
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
			j++;
		if (j != number_of_column)
			return (0);
		j = 0;
		i++;
	}
	if (i != number_of_ligne)
		return (0);
	return (1);
}

int	nb_column(char **tab)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '\n')
				return (counter);
			counter++;
			j++;
		}
	return (counter);
}

int	nb_ligne(char *file)
{
	char	*p;
	int		fd;
	int		counter;

	counter = 0;
	fd = open(file, O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return (0);
	}
	while (p != NULL)
	{
		free(p);
		p = get_next_line(fd);
		counter++;
	}
	free(p);
	close(fd);
	return (counter);
}
