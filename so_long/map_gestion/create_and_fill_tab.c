/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_fill_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:34:21 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/25 19:39:35 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**allocate_line(char **tab, char *file)
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
		return (NULL);
	}
	while (p != NULL)
	{
		free(p);
		p = get_next_line(fd);
		counter++;
	}
	free(p);
	close(fd);
	tab = ft_calloc((counter + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[counter] = NULL;
	return (tab);
}

char	*allocate_column_while(char **tab, char *p, int fd)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (p)
	{
		while (p[i] != '\n' && p[i] != '\0')
			i++;
		if (p[i] == '\n' || p[i] == '\0')
		{
			tab[j] = ft_calloc(i + 1, sizeof(char));
			if (tab[j] == NULL)
				return (NULL);
			j++;
			i = 0;
			free(p);
			p = get_next_line(fd);
		}
	}
	return (p);
}

char	**allocate_column(char **tab, char *file)
{
	char	*p;
	int		fd;

	fd = open(file, O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	p = allocate_column_while(tab, p, fd);
	free(p);
	close(fd);
	return (tab);
}

char	*fill_tab_while(char **tab, char *p, int fd)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (p != NULL && tab[j] != NULL )
	{
		while (p[i] != '\0' && tab[j] != NULL )
		{
			while (p[i] != '\n' && p[i] != '\0' && tab[j] != NULL)
			{
				tab[j][k++] = p[i++];
			}
			k = 0;
			j++;
			if (p[i] != '\0')
				i++;
		}
		i = 0;
		free(p);
		p = get_next_line(fd);
	}
	return (p);
}

char	**fill_tab(char **tab, char *file)
{
	int		fd;
	char	*p;

	fd = open(file, O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	p = fill_tab_while(tab, p, fd);
	free(p);
	close(fd);
	return (tab);
}
