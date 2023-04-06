/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check_expand3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:28 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/06 17:48:05 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


char **tab_without_space(char *str, int nbr)
{
	char **tab;
	int begin;
	int end;
	int i;
	int j;

	i = 0;
	j = 0;
	end = 0;
	tab = malloc(sizeof(char *) * (nbr + 1 + 1));
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '-' )
		{
			begin = i;
			if(begin != end)
			{
				tab[j] = return_right_tab(str, begin, end);
				j++;
			}
			i++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '-')
				i++;
			end = i;
			if(begin != end)
			{
				tab[j] = return_right_tab(str, begin, end);
				j++;
			}
		}
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '-' )
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char **recreate_tab_without_space(char **tab)
{
	int i;
	int count;
	int tab_i;
	int j;
	char **new_tab;
	char **broken_tab;
	
	i = 0;
	j = 0;
	count = 0;
	while (tab[i])
	{
		if(tab_as_space(tab[i]) == 1)
		{
			j--;
			count = nbr_space(tab[i]) + count;
		}
		i++;
		j++;
	}
	new_tab = malloc(sizeof(char *) *(count + 1 + j + 1));
	i = 0;
	j = 0;
	count = 0;
	while (tab[i])
	{
		if(tab_as_space(tab[i]) == 1)
		{
			tab_i = 0;
			broken_tab = tab_without_space(tab[i], nbr_space(tab[i]));
			while (broken_tab[tab_i])
			{
				new_tab[j] = ft_strcpy(broken_tab[tab_i]);
				tab_i++;
				j++;
			}
			free_double_tab(broken_tab);
		}
		else
			new_tab[j] = ft_strcpy(tab[i]);
	
		i++;
		j++;
	}
	new_tab[j - 1] = NULL;
	
	return (new_tab);
}