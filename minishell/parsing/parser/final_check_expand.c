/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:48:42 by imoumini          #+#    #+#             */
/*   Updated: 2023/03/30 18:29:41 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void print_double_tab(char **str)
{
	int i;

	i = 0;
	if (!str)
	{
		ft_printf("double tab is empty\n");
		return ;
	}
	ft_printf("double tab is \n");
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
	
}
void final_expand(t_final *final)
{
	t_final *follow;
	char **save;

	printf("c6.1\n");
	if (!final)
		return ;
	follow = final;
	printf("c6.2\n");
	while (follow)
	{
		printf("c6.3\n");
		if (double_tab_as_space(follow -> cmds) == 1)
		{
			printf("c6.4\n");
			save = follow -> cmds;
			printf("c6.5\n");
			follow -> cmds = recreate_tab_without_space(follow -> cmds);
			print_double_tab(follow -> cmds);
			printf("c6.6\n");
			free_double_tab(save);
			printf("c6.7\n");
		}
		follow = follow -> next_sibling;
		printf("c6.8\n");
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
	return (0);
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



	i = 0;
	
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
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

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '-' )
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
	
	printf("c6.5.7.5.1\n");
	if (begin > end)
	{
		printf("c6.5.7.5.2\n");
		tab = malloc(sizeof(char) * (((begin - 1)- end) + 1));
		while (begin > end)
		{
			printf("c6.5.7.5.3\n");
			if (str[end])
				tab[i] = str[end];
			printf("tab de i is=>%c\n", tab[i]);
			printf("c6.5.7.5.4\n");
			i++;
			end++;
		}
		printf("c6.5.7.5.5\n");
	}
	else if (begin < end)
	{
		printf("c6.5.7.5.6\n");
		tab = malloc(sizeof(char) * ((end - begin) + 1));
		printf("c6.5.7.5.7\n");
		while (end > begin)
		{
			printf("c6.5.7.5.8\n");
			if (str[begin])
				tab[i] = str[begin];
			printf("c6.5.7.5.9\n");
			i++;
			begin++;
		}
	}
	else
		return (NULL);
	printf("c6.5.7.5.10\n");
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
	
	printf("c6.5.7.1\n");
	
	i = 0;
	j = 0;
	end = 0;
	tab = malloc(sizeof(char *) * (nbr + 1 + 1));
	//ls-a-b-c
	//-a-la
	//ls-a
	//lsaaaaaaaaaaaa-bhfl-Duu
	printf("c6.5.7.2\n");
	while (str[i] != '\0')
	{
		printf("c6.5.7.3\n");
		printf("str[i] is :=>%c\n", str[i]);
		// la maintenant le b c que ya un NULL en plein milieu et diu coup ca va sareter avant
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '-' )
		{
			printf("c6.5.7.4\n");
			begin = i;
			printf("c6.5.7.5\n");
			printf("begin :%i, end: %i\n", begin, end);
			printf("str[begin] =>%c, str[end] =>%c\n", str[begin], str[end]);
			if(begin != end)
			{
				tab[j] = return_right_tab(str, begin, end);
				printf("right tab is =>%s\n", tab[j]);
				j++;
			}
			printf("c6.5.7.6\n");
		
			i++;
		
			printf("c6.5.7.7\n");
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '-')
			{
				printf("str[i] is =>%c\n", str[i]);
				printf("c6.5.7.8\n");
				i++;
				printf("c6.5.7.9\n");
			}
			end = i;
			printf("c6.5.7.10\n");
			// ok la g isoler la partie a couper
			printf("begin :%i, end: %i\n", begin, end);
			printf("str[begin] =>%c, str[end] =>%c\n", str[begin], str[end]);
			if(begin != end)
			{
				tab[j] = return_right_tab(str, begin, end);
				printf("right tab is =>%s\n", tab[j]);
				j++;
			}
			printf("c6.5.7.11\n");
		}
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '-' )
			i++;
		printf("c6.5.7.12\n");
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
	printf("c6.5.1\n");
	while (tab[i])
	{
		
		printf("c6.5.2\n");
		if(tab_as_space(tab[i]) == 1)
		{
			j--;
			printf("tab before transform is %s\n", tab[i]);
			count = nbr_space(tab[i]) + count;
			printf("c6.5.3\n");
			printf("nbr space is :%i\n", count);
		}
		i++;
		j++;
	}
	printf("c6.5.4\n");
	new_tab = malloc(sizeof(char *) *(count + 1 + j + 1));
	printf("c6.5.5\n");
	printf("nbr allocated is :%i\n", count + 1 + j + 1);
	i = 0;
	j = 0;
	count = 0;
	while (tab[i])
	{
		printf("c6.5.6\n");
		if(tab_as_space(tab[i]) == 1)
		{
			printf("c6.5.7\n");
			tab_i = 0;
			broken_tab = tab_without_space(tab[i], nbr_space(tab[i]));
			printf("c6.5.8\n");
			printf("broken tab is :\n");
			print_double_tab(broken_tab);
			while (broken_tab[tab_i])
			{
				printf("c6.5.9\n");
				new_tab[j] = ft_strcpy(broken_tab[tab_i]);
				printf("c6.5.10\n");
				printf("new_tab[j] is=>%s\n", new_tab[j]);
				tab_i++;
				j++;
			}
			printf("c6.5.11\n");
			free_double_tab(broken_tab);
			printf("c6.5.12\n");
		}
		else
		{
			printf("c6.5.13\n");
			new_tab[j] = ft_strcpy(tab[i]);
			printf("new_tab[j] is=>%s\n", new_tab[j]);
		}
	
		printf("c6.5.14\n");
		i++;
		j++;
	}
	new_tab[j - 1] = NULL;
	
	return (new_tab);
}

// quna ya le moins jaffiche rien, voir pk
// en plus quqnd ca a pas fonctionner g relancer une commnd normal et ca a segfault, voir pk
