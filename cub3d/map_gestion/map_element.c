/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:23:40 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/20 20:28:34 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
