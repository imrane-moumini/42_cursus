/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:31:15 by imrane            #+#    #+#             */
/*   Updated: 2023/04/06 17:27:22 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com **create_ast_command_redir(t_node *root)
{
	t_com **ast;
	t_ast  *save_ast;
	t_node *ptr;
	int	nbr_pipe;
	
	save_ast = NULL;
	ast = NULL;
	if (!root)
		return (NULL);
	ptr = root -> first_child;
	nbr_pipe = how_much_pipe(root);
	ast = malloc_ast(ast, nbr_pipe);
	ast = create_ast_command_redir_while(ast, save_ast, ptr, nbr_pipe);
	return (ast);
}


t_ast *isolate_command_redir(t_node *ptr)
{
	
	t_ast  *save_ast;
	t_redir *redir;
	t_com	*com;

	if (!ptr)
		return (NULL);
	com = NULL;
	redir = NULL;
	if (ptr)
	{
		while (ptr && ft_stcmp(ptr -> txt, "|") != 1)
		{
			while (ptr && ft_stcmp(ptr -> txt, "|") != 1 && ft_stcmp(ptr -> txt, "<") != 1 && ft_stcmp(ptr -> txt, ">") != 1)
			{
				com = create_com_node(com, ptr);
				ptr = ptr -> next_sibling;
			}
			if (ptr)
			{
				if (ft_stcmp(ptr -> txt, "<") == 1 || ft_stcmp(ptr -> txt, ">") == 1 )
					ptr = return_ptr(&redir, ptr);
			}
		}
		if (ptr)
			ptr = ptr -> next_sibling;
		save_ast = malloc(sizeof(save_ast));
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
	}
	return (save_ast);
}

void print_final_ast(t_com **ast)
{
	int i;
	i = 0;
	while(ast[i])
	{
		
		ft_printf("------------------------\n");
		printf("command %i is :\n", i);
		print_command(ast[i]);
		print_redir(ast[i] -> redir);
		ft_printf("------------------------\n");
		i++;
	}
}

void print_command(t_com *com)
{
	t_com *ptr;
	if (!com)
	{
		printf("there is nos command\n");
		return ;
	}
	ptr = com;
	while (ptr)
	{
		ft_printf("command is \n");
		ft_printf("%s\n",ptr -> txt);
		ptr = ptr -> next_sibling;
	}
}
void print_redir(t_redir *redir)
{
	t_redir *ptr;
	if (!redir)
	{
		ft_printf("there is no redir for this command\n");
		return ;
	}
	ptr = redir;
	while (ptr)
	{
		ft_printf("redir is \n");
		ft_printf("%s\n",ptr -> txt);
		ptr = ptr -> next_sibling;
	}
}

