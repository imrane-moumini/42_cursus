/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:31:15 by imrane            #+#    #+#             */
/*   Updated: 2023/03/30 18:56:53 by imoumini         ###   ########.fr       */
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
			// decoupe la command et arguments
			while (ptr && ft_stcmp(ptr -> txt, "|") != 1 && ft_stcmp(ptr -> txt, "<") != 1 && ft_stcmp(ptr -> txt, ">") != 1)
			{
				com = create_com_node(com, ptr);
				ptr = ptr -> next_sibling;
			}
			if (ptr)
			{
				// ok ici en fait javance jusqua pipe
				// alors que jeverai avancer jusquau prochain truc et puis recommencer le processus
				
				if (ft_stcmp(ptr -> txt, "<") == 1 || ft_stcmp(ptr -> txt, ">") == 1 )
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
							if (ptr )
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


/*

imoumini@e2r7p16:~/42_cursus/minishell$ export FF="" // moi ca segfaut voir pk

*/

/*


si on ecrit un dollar seul, il ne faut pas expand
$Uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu => segfault pour un env inexistant, il faut remplacer 
par du vide. Ca revient a envoyer une string vide

minishell> "" => segfault aussi. car ca sera remplacer par du vide

env -i ./minishell =>  si je fait echo $HOME => ca segfault car avec env -i, ca enleve les variables d env,
donc il ny a plus de HOME
// apres faire en sorte de bien decoper la logique pour pouvoir la lancdr en fonction de si ya guillemet et ou heredoc
*/