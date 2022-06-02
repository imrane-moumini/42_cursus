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
#include <unistd.h>
#include "libft.h"

int number_of_tab(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;

	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i] != '\0'))
		{
			count++;
			i++;
		}
		while ((s[i] != c) && (s[i] != '\0'))
		{
			i++;
		}
		while ((s[i] == c) && (s[i] != '\0'))
		{
			i++;
		}
	}
	printf("count %d\n", count);
	return (count);
} 
void	fill_tab(char const *s, char c, char **p, int l)
{
	int	i;
	int j;
	int	k;

	j = 0;
	i = 0;
	k = 0;

	while (s[i] != '\0')
	{
		while ((s[i] == c) && (i <= l))
		{
			i++;
		}
		while ((s[i] != c) && (i <= l))
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
	j++;
	p[j] = NULL;
}

char    **ft_split(char const *s, char c)
{
	int i;
	int j;
	int	number_of_tabs;
	int count;
	int lenght;
	printf("test\n");
	lenght = ft_strlen(s);
	number_of_tabs = number_of_tab(s,c);
	i = 0;
	j = 0;
	count = 0;
	// creer un pointeur qui enreistre l'adresse memoire d'un autre pointeur de type char (une collection d eppinteur en loccurence)
	char **p;
	// definir la taille de cette collection depointeur (le nbr de pointeur present dans ce tableau de pointeur)
	p = (char **)malloc(sizeof(char *) * number_of_tabs + 1);
	if (number_of_tabs == 0)
	{
		p = NULL;
		return (p);
	}
	// definir le nbr delement de caque tableau individuellement
	while (i <= lenght - 1)
	{
		while (((s[i] == c) && (i <= lenght - 1)))
		{
			i++;
		}
		while ((s[i] != c) && (i <= lenght -1))
		{
			count++;
			i++;
		}
		printf("%d\n", count);
		p[j] = malloc((char) sizeof(char) *count + 1);
		j++;
		count = 0;
		i++;
	}
	fill_tab(s,c, p, lenght);
	return (p);
}

int		main(void)
{
	char	**tabstr;
	int		i;
	

	i = 0;
	if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
		printf("NULL");
	else
	{
		while (tabstr[i] != NULL)
		{
			printf("%s\n", tabstr[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}

// int main(void)

// {
// 	int i;
// 	char s[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
// 	char c = ' ';
// 	char **p;
	
// 	i = 0;
// 	p = ft_split(s, c);

// 	while (i <= number_of_tab(s,c))
// 	{
// 		//printf("%s\n", p[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i <= number_of_tab(s,c))
// 	{
// 		if (p[12] == NULL)
// 		{
// 			printf("TRUE\n");
// 		}
// 		else
// 		{
// 			printf("FALSE\n");
// 		}
// 		//printf("%s", p[1]);
// 		i++;
// 	}

// }
