/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:53:16 by imoumini          #+#    #+#             */
/*   Updated: 2023/03/18 22:41:51 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_final *create_final_ast(t_com **ast)
{
	t_final *final;
	int i;

	final = NULL;
	i = 0;
	while (ast[i])
	{
		final = create_list_final_ast(final, ast[i]);
		i++;
	}
	return (final);
}

t_final create_list_final_ast(t_final *final, t_com *ast)
{
	t_final *ptr;
	t_final *follow;
	ptr = malloc(sizeof(t_final));
	if (!ast)
		return (NULL);
	if (!final)
	{
		ptr -> cmds = break_linked_list_in_double_tab(ast -> command);
		ptr -> redir = ast -> redir
		ptr -> next_sibling = NULL;
		final = ptr;
	}
	else
	{
		follow = final;
		while (follow -> next_sibling != NULL)
			follow = follow -> next_sibling;
		follow -> next_sibling = ptr;
		ptr -> cmds = break_linked_list_in_double_tab(ast -> command);
		ptr -> redir = ast -> redir
		ptr -> next_sibling = NULL;
	}
	return (final);
}

char **break_linked_list_in_double_tab(t_com *com)
{
	char **tab;
	t_com *follow;
	int i;
	
	i = 0;
	// taille du tab = command + argument duene command
	// nbr argument = taille de la linked list
	// tailldes tab[i] = nbr de car de command ou arg
	if (!com)
		return (NULL);
	follow = com;
	tab = malloc(sizeof(char *) * (ft_com_len(com) + 1))
	while (follow)
	{
		tab[i] = malloc(sizeof(char) * (ft_strlen(follow -> command -> txt) + 1));
		tab[i] = ft_strlcpy(tab[i], follow -> command -> txt, (ft_strlen(follow -> command -> txt) + 1));
		follow = follow -> next_sibling;
	}
	return (tab);
}

int ft_com_len(t_com *com)
{
	t_com *follow;
	int i;

	i = 0;
	follow = com;
	while (follow)
	{
		i++;
		follow = follow -> next_sibling;
	}
	return (i);
}