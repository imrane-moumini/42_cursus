/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/10 19:03:03 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void allocate_line(char **tab, char *file)
{
	char *p;
	int fd;
	int counter;
	int i;

	counter = 0;
	i = 0;

	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
			return;
	while (p != NULL)
	{
		while (p[i] != '\0')
		{
			if (p[i] == '\n')
				counter++;
			i++;
		}
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
	counter++;
	tab = malloc(sizeof(char *) * counter + 1);
	if (tab == NULL)
		return;
	tab[counter + 1] = NULL;
}
void allocate_column(char **tab, char *file)
{
	int counter;
	int i;
	int j;
	char *p;
	int fd;
	
	counter = 0;
	i = 0;
	j = 0;
	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
			return;
	while (p != NULL && tab[j] != NULL)
	{
		while (p[i] != '\0')
		{
			while (p[i] != '\n' && p[i] != '\0')
			{
				counter++;
				i++;
			}
			if (p[i] == '\n' || p[i] == '\0')
			{
				tab[j] = malloc(sizeof(char) * counter + 1);
				if (tab[j] == NULL)
					return;
				counter = 0;
				j++;
			}
			i++;
		}
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
}
void fill_tab(char **tab, char *file)
{
	int i;
	int j;
	int k;
	int fd;
	char *p;
	
	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
			return;
	while (p != NULL && tab[j] != NULL)
	{
		while (p[i] != '\0' && tab[j] != NULL)
		{
			while (p[i] != '\n' && p[i] != '\0')
			{
				tab[j][k] = p[i];
				i++;
				k++;
			}
			k = 0;
			j++;
			i++;
		}
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
}
int main(int argc, char *argv[])
{
	char **tab;
    (void) argc;
	int i;

	tab = NULL;
	i = 0;
	allocate_line(tab, argv[1]);
	if (tab == NULL)
		return (1);
	allocate_column(tab, argv[1]);
	if (tab == NULL)
		return (1);
	fill_tab(tab, argv[1]);
	while (tab != NULL)
	{
		ft_printf("%s", tab[i]);
		i++;
	}
}