/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:53:16 by imoumini          #+#    #+#             */
/*   Updated: 2023/03/21 20:51:22 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_final *create_final_ast(t_com **ast)
{
	t_final *final;
	int i;
	printf("c4.1\n");
	final = NULL;
	i = 0;
	while (ast[i])
	{
		printf("c4.2\n");
		final = create_list_final_ast(final, ast[i]);
		printf("c4.3\n");
		i++;
	}
	printf("c4.4\n");
	return (final);
}

t_final *create_list_final_ast(t_final *final, t_com *ast)
{
	t_final *ptr;
	t_final *follow;
	
	printf("c4.2.1\n");
	ptr = malloc(sizeof(t_final));
	if (!ast)
		return (NULL);
	printf("c4.2.2\n");
	if (!final)
	{
		printf("c4.2.3\n");
		ptr -> cmds = break_linked_list_in_double_tab(ast);
		printf("c4.2.4\n");
		ptr -> redir = ast -> redir;
		printf("c4.2.5\n");
		ptr -> next_sibling = NULL;
		printf("c4.2.6\n");
		final = ptr;
		printf("c4.2.7\n");
	}
	else
	{
		printf("c4.2.8\n");
		follow = final;
		printf("c4.2.9\n");
		while (follow -> next_sibling != NULL)
			follow = follow -> next_sibling;
		printf("c4.2.10\n");
		follow -> next_sibling = ptr;
		printf("c4.2.11\n");
		ptr -> cmds = break_linked_list_in_double_tab(ast);
		printf("c4.2.12\n");
		ptr -> redir = ast -> redir;
		printf("c4.2.13\n");
		ptr -> next_sibling = NULL;
		printf("c4.2.14\n");
	}
	return (final);
}

char **break_linked_list_in_double_tab(t_com *com)
{
	char **tab;
	t_com *follow;
	int i;
	printf("c4.2.3.1\n");
	i = 0;
	printf("c4.2.3.2\n");
	if (!com)
		return (NULL);
	printf("c4.2.3.3\n");
	follow = com;
	printf("c4.2.3.4\n");
	tab = malloc(sizeof(char *) * (ft_com_len(com) + 1));
	printf("c4.2.3.5\n");
	while (follow)
	{
		printf("c4.2.3.6\n");
		if (follow -> txt)
		{
			tab[i] = malloc(sizeof(char) * (ft_strlen(follow -> txt) + 1));
			printf("c4.2.3.7\n");
			ft_strlcpy(tab[i], follow -> txt, (ft_strlen(follow -> txt) + 1));
			printf("c4.2.3.8\n");
			follow = follow -> next_sibling;
			printf("c4.2.3.9\n");
			i++;
		}
		else
		{
			tab[i] = NULL;
			follow = follow -> next_sibling;
		}
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

// creer fonction qui qffiche ma final structure pour voir si ca a fonctionner

void printf_final_ast(t_final *final)
{
	t_final *follow;
	t_redir *follow_redir;
	int i;
	int j;
	
	j = 0;
	i = 0;
	if (!final)
		return ;
	follow = final;
	while (follow)
	{
		ft_printf("---------------------------\n");
		ft_printf("for command %i :\n", j);
		ft_printf("command is : \n");
		while (follow -> cmds[i])
		{
			ft_printf("%s\n", follow -> cmds[i]);
			i++;
		}
		ft_printf("redir is : \n");
		follow_redir = follow -> redir;
		if (!follow_redir)
			ft_printf("this command as no redir\n");
		while (follow_redir)
		{
			ft_printf("%s, heredoc : %i, in_file : %i, out_file : %i, append : %i, file : %i\n", follow_redir -> txt, follow_redir -> heredoc, follow_redir -> in_file, follow_redir -> out_file, follow_redir -> append, follow_redir -> file);
			follow_redir = follow_redir -> next_sibling;
		}
		i = 0;
		j++;
		follow = follow -> next_sibling;
	}
}

// faire valgrind
// faire logique quand ya les guillemets