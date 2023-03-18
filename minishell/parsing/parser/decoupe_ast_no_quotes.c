/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:31:15 by imrane            #+#    #+#             */
/*   Updated: 2023/03/18 21:41:05 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com **create_ast_command_redir(t_node *root)
{
	t_com **ast;
	t_ast  *save_ast;
	t_node *ptr;
	int	nbr_pipe;
	int i;
	
	save_ast = NULL;
	if (!root)
		return (NULL);
	ptr = root -> first_child;
	i = 0;
	nbr_pipe = how_much_pipe(root);
	if (nbr_pipe > 0)
	{
		ast = malloc(sizeof(t_com *) * ((nbr_pipe + 1) + 1));
		ast[(nbr_pipe + 1)] = NULL;
	}
	else
	{
		ast = malloc(sizeof(t_com *) + 1);
		ast[1] = NULL;
		nbr_pipe = 1;
	}

	while (nbr_pipe >= 0)
	{
		if (save_ast)
			save_ast = isolate_command_redir(save_ast -> save_ptr);
		else
			save_ast = isolate_command_redir(ptr);
		
		if (save_ast)
		{
			ast[i] = save_ast -> command;
			if (ast[i])
				ast[i] -> redir = save_ast -> redir;
		}
		nbr_pipe--;
		i++;
	}
	return (ast);
}


t_ast *isolate_command_redir(t_node *ptr)
{
	
	t_ast  *save_ast;
	t_redir *redir;
	t_com	*com;

	com = NULL;
	redir = NULL;
	save_ast = NULL;
	save_ast = malloc(sizeof(save_ast));
	save_ast -> command = NULL;
	save_ast -> redir = NULL;
	save_ast -> save_ptr = ptr;
	if (ptr)
	{
		// decoupe la command et arguments
		while (ptr && ft_stcmp(ptr -> txt, "|") != 1 && ft_stcmp(ptr -> txt, "<") != 1 && ft_stcmp(ptr -> txt, ">") != 1)
		{
			com = create_com_node(com, ptr);
			ptr = ptr -> next_sibling;
		}
		if (ptr)
		{
			if (ft_stcmp(ptr -> txt, "<") == 1 || ft_stcmp(ptr -> txt, ">") == 1 )
			{
				while (ptr && ft_stcmp(ptr -> txt, "|") != 1)
				{
					if ((ptr -> next_sibling  && ft_stcmp(ptr -> next_sibling -> txt, "<") == 1) || (ptr -> next_sibling  && (ft_stcmp(ptr -> next_sibling -> txt, ">") == 1 )))
					{
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
							redir = create_redir_node(redir, ptr);
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
							ptr = ptr -> next_sibling;
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
							ptr = ptr -> next_sibling;
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
							redir = create_redir_node(redir, ptr);
					}
					else if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
					{
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
							redir = create_redir_node(redir, ptr);
						if (ptr)
							ptr = ptr -> next_sibling;
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
							redir = create_redir_node(redir, ptr);
					}
					if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
						ptr = ptr -> next_sibling;
				}
			}
		}
	// avance prochaine command
		if (ptr)
			ptr = ptr -> next_sibling;
		// sauvegarde debut prochainne command + redir + command
		if (save_ast)
		{
			save_ast -> command = com;
			save_ast -> redir = redir;
			save_ast -> save_ptr = ptr;
		}
	}
	return (save_ast);
}

void print_final_ast(t_com **ast)
{
	int i;
	i = 0;
	printf("c4.1\n");
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
