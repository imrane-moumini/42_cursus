/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check_expand3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:28 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/14 15:25:57 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


char **tab_without_space(char *str, int nbr)
{
	char **tab;
	int begin;
	int end;
	printf("c8.5.7.3.1\n");
	begin = 0;
	end = 0;
	tab = malloc(sizeof(char *) * (nbr + 1 + 1));
	tab[0] = NULL;
	printf("c8.5.7.3.2\n");
	tab = tab_without_space_while(str, begin, end, tab);
	return (tab);
}
char **tab_without_space_while(char *str, int begin, int end, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("c8.5.7.3.2.1\n");
	while (str[i] != '\0')
	{
		printf("c8.5.7.3.2.2\n");
		if (str[i] == '-' )
		{
			printf("c8.5.7.3.2.3\n");
			begin = i;
			if(begin != end)
			{
				printf("c8.5.7.3.2.4\n");
				tab[j++] = return_right_tab(str, begin, end);
			}
			i++;
			while (str[i] /*&& str[i] != ' ' && str[i] != '\t' */&& str[i] != '-')
			{
				printf("c8.5.7.3.2.5\n");
				i++;
			}
			end = i;
			if(begin != end)
			{
				printf("c8.5.7.3.2.6\n");
				tab[j++] = return_right_tab(str, begin, end);
			}
		}
		if (str[i] /*&& str[i] != ' ' && str[i] != '\t' */&& str[i] != '-' )
		{
			printf("c8.5.7.3.2.7\n");
			i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char **recreate_tab_without_space_while(char **tab, char **new_tab, int i, int j)
{
	char **broken_tab;
	int tab_i;
	printf("c8.5.7.1\n");
	while (tab[i])
	{
		printf("c8.5.7.2\n");
		if(tab_as_space(tab[i]) == 1)
		{
			printf("c8.5.7.3\n");
			tab_i = 0;
			broken_tab = tab_without_space(tab[i], nbr_space(tab[i]));
			printf("c8.5.7.4\n");
			while (broken_tab && broken_tab[tab_i])
			{
				printf("c8.5.7.5\n");
				printf("broken tab is :%s\n",broken_tab[tab_i] );
				new_tab[j] = ft_strcpy(broken_tab[tab_i]);
				printf("c8.5.7.6\n");
				tab_i++;
				j++;
			}
			printf("c8.5.7.7\n");
			free_double_tab(broken_tab);
		}
		else
		{
			printf("c8.5.7.7\n");
			new_tab[j] = ft_strcpy(tab[i]);
		}
		printf("c8.5.7.8\n");
		i++;
		j++;
	}
	new_tab[j - 1] = NULL;
	printf("c8.5.7.9\n");
	return (new_tab);
}


char **recreate_tab_without_space(char **tab)
{
	int i;
	int count;
	int j;
	char **new_tab;
	
	printf("c8.5.1\n");
	i = 0;
	j = 0;
	count = 0;
	printf("c8.5.2\n");
	while (tab[i])
	{
		printf("c8.5.3\n");
		if(tab_as_space(tab[i]) == 1)
		{
			printf("c8.5.4\n");
			j--;
			count = nbr_space(tab[i]) + count;
			printf("c8.5.5\n");
		}
		i++;
		j++;
		printf("c8.5.6\n");
	}
	new_tab = malloc(sizeof(char *) *(count + 1 + j + 1));
	new_tab[1] = NULL; 
	printf("c8.5.7\n");
	i = 0;
	j = 0;
	return (recreate_tab_without_space_while(tab, new_tab, i, j));
}