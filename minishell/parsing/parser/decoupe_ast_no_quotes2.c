/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:07:06 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/24 20:48:14 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com	**malloc_ast(t_com **ast, int nbr_pipe)
{
	if (nbr_pipe > 0)
	{
		ast = malloc(sizeof(t_com *) * ((nbr_pipe + 1) + 1));
		ast[(nbr_pipe + 1)] = NULL;
	}
	else
	{
		ast = malloc(sizeof(t_com *) * 2);
		ast[1] = NULL;
		nbr_pipe = 0;
	}
	return (ast);
}

t_com	**create_while(t_com **ast, t_ast *save_ast, t_node *ptr, int nbr_pipe)
{
	int	i;

	i = 0;
	while (nbr_pipe-- >= 0)
	{
		if (save_ast && save_ast -> save_ptr)
			save_ast = isolate_command_redir(save_ast -> save_ptr);
		else
			save_ast = isolate_command_redir(ptr);
		if (save_ast)
		{
			if (save_ast -> command)
				ast[i] = save_ast -> command;
			else
			{
				ast[i] = malloc(sizeof(t_com));
				ast[i]->txt = NULL;
			}
			if (ast[i])
				ast[i]->redir = save_ast->redir;
			free(save_ast);
			save_ast = NULL;
			i++;
		}
	}
	return (ast);
}

t_node	*return_ptr(t_redir **redir, t_node *pt)
{
	if ((pt -> next \
		&& ft_stcmp(pt->next-> txt, "<") == 1) || (pt->next \
		&& (ft_stcmp(pt -> next -> txt, ">") == 1)))
	{
		if (pt && ft_stcmp(pt -> txt, "|") != 1)
			*redir = create_redir_node(*redir, pt);
		if (pt && ft_stcmp(pt -> txt, "|") != 1)
			pt = pt -> next;
		if (pt && ft_stcmp(pt -> txt, "|") != 1)
			pt = pt -> next;
		if (pt && ft_stcmp(pt -> txt, "|") != 1)
			*redir = create_redir_node(*redir, pt);
	}
	else if (pt && ft_stcmp(pt -> txt, "|") != 1)
	{
		if (pt && ft_stcmp(pt -> txt, "|") != 1)
			*redir = create_redir_node(*redir, pt);
		if (pt)
			pt = pt -> next;
		if (pt && ft_stcmp(pt -> txt, "|") != 1)
			*redir = create_redir_node(*redir, pt);
	}
	if (pt && ft_stcmp(pt -> txt, "|") != 1)
		pt = pt -> next;
	return (pt);
}

t_ast	*return_save_ast(t_node *ptr, t_com *com, t_redir *redir)
{
	(void) redir;
	t_ast	*save_ast;

	if (ptr)
			ptr = ptr -> next;
	save_ast = malloc(sizeof(*save_ast));
	if (com)
		save_ast -> command = com;
	else
		save_ast -> command = NULL;
	if (redir)
		save_ast -> redir = redir;
	else
		save_ast -> redir = NULL;
	if (ptr)
			save_ast -> save_ptr = ptr;
	return (save_ast);
}
