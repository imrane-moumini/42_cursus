/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:34:05 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/17 23:34:56 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int is_car_ok(char **tab)
{
	int i;
	int j;
	int c = 0;
	int zero = 0;
	int one = 0;
	int e = 0;
	int p = 0;
	int count_p;
	int count_e;

	i = 0;
	j = 0;
	count_e = 0;
	count_p = 0;
	while (tab[i] != NULL)
	{
			while(tab[i][j] != '\0')
			{
				if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'C' && tab[i][j] != 'E' && tab[i][j] != 'P'  )
					return (0);
				j++;	
			}
			j = 0;
			i++;
	}
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
			while(tab[i][j] != '\0')
			{
				if (tab[i][j] == '0')
					zero = 1;
				if (tab[i][j] == '1')
					one = 1;
				if (tab[i][j] == 'C')
					c = 1;
				if (tab[i][j] == 'E')
				{	e = 1;
					count_e++;
				}
				if (tab[i][j] == 'P')
				{
					p = 1;
					count_p++;
				}
				j++;	
			}
			j = 0;
			i++;
	}
	if (zero == 0 || one == 0 || c == 0 || e == 0 || p == 0)
		return (0);
	if (count_e > 1 || count_p > 1)
		return (0);
	return (1);
}

int is_car_close(char **tab, int number_of_ligne, int number_of_column)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab[1] != NULL)
	{
		while (tab[0][j] != '\0')
		{
			if (tab[0][j] != '1')
			{
				return 0;
			}
			j++;
		}	
	}
	j = 0;
	if (tab[number_of_ligne -1] != NULL)
	{
		while (tab[number_of_ligne -1][j] != '\0' )
		{
			if (tab[number_of_ligne -1][j] != '1')
			{
				return 0;
			}
			j++;
		}	
	}
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (j == 0)
			{
				if (tab[i][j] != '1')
				{
					return (0);
				}	
			}
			if (j == number_of_column - 1)
			{
				if (tab[i][j] != '1')
				{
						return (0);
				}	
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int is_car_rect(char **tab, int number_of_ligne, int number_of_column)
{
	int i;
	int j;
	

	i = 0;
	j = 0;
	if (number_of_column == number_of_ligne)
		return (0);
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			j++;
		}
		if (j != number_of_column)
		{
				return (0);
		}
		j = 0;
		i++;
	}
	if (i != number_of_ligne)
	{
			return (0);
	}
	return (1);	
}

int nb_column(char **tab)
{
	int i;
	int j;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '\0')
				return (counter);
			counter++;
			j++;
		}
		i++;	
	}
	return(counter);
}

int nb_ligne(char *file)
{
	char *p;
	int fd;
	int counter;

	counter = 0;

	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
		{
			free(p);
			return(0);
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


