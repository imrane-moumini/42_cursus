/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/10 22:40:03 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_line(char **tab, char *file)
{
	char *p;
	int fd;
	int counter;

	counter = 0;

	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
			return(NULL);
	while (p != NULL)
	{
		p = get_next_line(fd);
		counter++;
	}
	free(p);
	close(fd);
	tab = malloc(sizeof(char *) * (counter + 1));
	if (tab == NULL)
		return(NULL);
	tab[counter] = NULL;
	return (tab);
}
char **allocate_column(char **tab, char *file)
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
			return(NULL);
	while (p != NULL)
	{
		while (p && p[i] != '\0')
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
					return(NULL);
				counter = 0;
				j++;
				i = 0;
				p = get_next_line(fd);
			}
		}
	}
	free(p);
	close(fd);
	return (tab);
}
char **fill_tab(char **tab, char *file)
{
	int i;
	int j;
	int k;
	int fd;
	char *p;
	i = 0;
	k = 0;
	
	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
			return(NULL);
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
		i = 0;
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
	return (tab);
}
int main(int argc, char *argv[])
{
	char **tab;
	int i;
	if (argc != 2)
		return(1);
	tab = NULL;
	i = 0;
	tab = allocate_line(tab, argv[1]);
	if (tab == NULL)
		return (1);
	tab = allocate_column(tab, argv[1]);
	if (tab == NULL)
		return (1);
	tab = fill_tab(tab, argv[1]);
	while (tab[i] != NULL)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}