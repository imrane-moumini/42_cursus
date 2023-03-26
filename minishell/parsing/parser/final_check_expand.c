/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:48:42 by imoumini          #+#    #+#             */
/*   Updated: 2023/03/26 17:58:27 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void final_expand(t_final *final)
{
	t_final *follow;
	t_redir *follow_redir;
	char **save;
	int i;
	int j;
	
	i = 0;
	if (!final)
		return ;
	follow = final;
	while (follow)
	{
		if (double_tab_as_space(follow -> cmds) == 1)
		{
			save = follow -> cmds;
			follow -> cmds = recreate_tab_without_space(follow -> cmds);
			free_double_tab(save);
		}
		follow = follow -> next_sibling;
	}
}

int double_tab_as_space(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while(tab[i][j])
		{
			if (tab[i][j] == ' ' || tab[i][j] == '\t' || tab[i][j] == '-' )
				return (1);
			j++;
		}
		i++;
	}
	return (0)
}

int tab_as_space(char *tab)
{
	int i;
	i = 0;
	
	while (tab[i])
	{
		if (tab[i] == ' ' || tab[i] == '\t' || tab[i] == '-' )
				return (1);
		i++;
	}
	return (0);
}


void free_double_tab(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] == NULL;
		}
		i++;
	}
}
int nbr_space(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;

	while (tab[i])
	{
		if (tab[i] == ' ' || tab[i] == '\t' || tab[i] == '-' )
			count++;
		i++;
	}
	return (count);
}

char *return_right_tab(char *str, int begin, int end)
{
	char *tab;
	int i;
	i = 0;
	
	if (begin - 1 > end)
	{
		tab = malloc(sizeof(char) * (((begin - 1)- end) + 1));
		while (begin - 1 > end)
		{
			tab[i] = str[end];
			i++;
			end++;
		}
	}
	else
	{
		tab = malloc(sizeof(char) * ((end - begin) + 1));
		while (end > begin)
		{
			tab[i] = str[begin];
			i++;
			begin++;
		}
	}
	
	tab[i] = '\0';
	return (tab);
}

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
	// je prcours le str 
	// jisole la partie de pas despace jusquq espace
	// je copie et kevoi dans tab[i]
	// je i++
	// je suis er vais encore jusquq dernier point jusauq ce que str[i] exuste plus
	// en fiat je joue avec les curseurs end et begin
	//ls-a-b-c
	//-a-la
	//ls-a
	while (nbr > 0)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '-' )
		{
			begin = i;
			// ok ca faut que je le fasse quune fois
			// faut je me souvienne de la partie juste avant espace et que je la copie dans tab[j]
			if (j == 0)
			{
				tab[j] = return_right_tab(str, begin, end);
				// je save de str[end] a str[begin- 1];
				// faut que je compte ya cb de car entre end et begin
				// je malloc ce count
				// je copie entre end et begin
				// ok je fais ca dans une fonction
				j++;
			}
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '-')
				i++;
			end = i-1;
			// ok la g isoler la partie a couper
			tab[j] = return_right_tab(str, begin, end);
			// je save str[begin] a str[end]
			j++;
			// faut que je copie aussi partie qui est avant
		}
		// en fait faut jisole toutes les parties avant et apres 
		i++;
		nbr--;
	}
	tab[j] = NULL:
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
	new_tab[j] = NULL;
	
	return (new_tab);
}