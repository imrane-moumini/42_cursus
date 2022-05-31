/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:28:54 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/27 19:28:58 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int number_of_tab(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count + 1);
} 
void	fill_tab(char const *s, char c, char **p)
{
	int	i;
	int j;
	int	k;

	j = 0;
	i = 0;
	k = 0;

	while (s[i] != '\0')
	{
		while ((s[i] != c) && (s[i] != '\0'))
		{
			p[j][k] = s[i];
			k++;
			i++;
		}
		p[j][k] = '\0';
		if (s[i] == c)
		{
			k = 0;
			j++;
		}
		i++;
	}
}

char    **ft_split(char const *s, char c)
{
	int i;
	int j;
	int	number_of_tabs;
	int count;
	int lenght;
	
	number_of_tabs = number_of_tab(s,c);
	i = 0;
	j = 0;
	count = 0;
	// creer un pointeur qui enreistre l'adresse memoire d'un autre pointeur de type char (une collection d eppinteur en loccurence)
	char **p;
	// definir la taille de cette collection depointeur (le nbr de pointeur present dans ce tableau de pointeur)
	p = (char **)malloc(sizeof(char *) * number_of_tabs);
	// definir le nbr delement de caque tableau individuellement
	lenght = ft_strlen(s);
	while (i <= lenght)
	{
		if (s[i] == c || i == lenght)
		{
			p[j] = malloc((char) sizeof(char) *count + 1);
			j++;
			count = 0;
		}
		if (s[i] != c && i != lenght)
	        {
	          count++;
	        }
		i++;
	}
	fill_tab(s,c, p);
	return (p);

}
/*int main(void)
{
	int i;
	char s[] = "je suis un bg";
	char c = ' ';
	char **p;

	i = 0;
	p = ft_split(s, c);

	while (i < number_of_tab(s,c))
	{
		printf("%s\n", p[i]);
		i++;
	}

}*/
