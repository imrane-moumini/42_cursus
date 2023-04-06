/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check_expand2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:44:38 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/06 17:46:26 by imoumini         ###   ########.fr       */
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

int double_tab_as_export(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (ft_stcmp(tab[i], "export") == 1)
			return (1);
		i++;
	}
	
	return (0);
}
void final_expand(t_final *final)
{
	t_final *follow;
	char **save;

	if (!final)
		return ;
	follow = final;
	while (follow)
	{
		if (double_tab_as_export(follow -> cmds) == 0)
		{
			if (double_tab_as_space(follow -> cmds) == 1)
			{
				save = follow -> cmds;
				follow -> cmds = recreate_tab_without_space(follow -> cmds);
				print_double_tab(follow -> cmds);
				free_double_tab(save);
			}	
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
	if (!tab)
		return (0);
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