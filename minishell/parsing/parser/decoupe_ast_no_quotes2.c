/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:07:06 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/06 17:26:52 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com ** malloc_ast(t_com **ast, int nbr_pipe)
{
	if (nbr_pipe > 0)
	{
		ast = malloc(sizeof(t_com *) * ((nbr_pipe + 1) + 1));
		ast[(nbr_pipe + 1)] = NULL;
	}
	else
	{
		ast = malloc(sizeof(t_com *) + 1);
		ast[1] = NULL;
		nbr_pipe = 0;
	}
	return (ast);
}

t_com **create_ast_command_redir_while(t_com **ast, t_ast *save_ast, t_node *ptr, int nbr_pipe)
{
	int i;

	i = 0;
	printf("c2.2.1\n");
	while (nbr_pipe >= 0)
	{
		printf("c2.2.2\n");
		if (save_ast)
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
				ast[i] -> txt = NULL;
			}
			if (ast[i])
				ast[i] -> redir = save_ast -> redir;
			free(save_ast);
			i++;
		}
		nbr_pipe--;
	}
	return (ast);
}

t_node *return_ptr(t_redir **redir, t_node *ptr)
{
	if ((ptr -> next_sibling  && ft_stcmp(ptr -> next_sibling -> txt, "<") == 1) || (ptr -> next_sibling  && (ft_stcmp(ptr -> next_sibling -> txt, ">") == 1 )))
	{
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			*redir = create_redir_node(*redir, ptr);
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			ptr = ptr -> next_sibling;
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			ptr = ptr -> next_sibling;
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			*redir = create_redir_node(*redir, ptr);
	}
	else if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
	{
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			*redir = create_redir_node(*redir, ptr);
		if (ptr)
			ptr = ptr -> next_sibling;
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1) 
			*redir = create_redir_node(*redir, ptr);
	}
	if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
		ptr = ptr -> next_sibling;
	return (ptr);
}