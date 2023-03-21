/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:31:15 by imrane            #+#    #+#             */
/*   Updated: 2023/03/21 20:53:04 by imoumini         ###   ########.fr       */
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
	
	printf("c3.1\n");
	save_ast = NULL;
	printf("c3.2\n");
	if (!root)
		return (NULL);
	printf("c3.3\n");
	ptr = root -> first_child;
	printf("c3.4\n");
	i = 0;
	nbr_pipe = how_much_pipe(root);
	printf("c3.5\n");
	if (nbr_pipe > 0)
	{
		printf("c3.6\n");
		ast = malloc(sizeof(t_com *) * ((nbr_pipe + 1) + 1));
		printf("c3.7\n");
		ast[(nbr_pipe + 1)] = NULL;
		printf("c3.8\n");
	}
	else
	{
		printf("c3.9\n");
		ast = malloc(sizeof(t_com *) + 1);
		printf("c3.10\n");
		ast[1] = NULL;
		nbr_pipe = 1;
		printf("c3.11\n");
	}

	// c vers la que je dois free save ast sans que ca nike ma logique
	// jvai creer une valeur de save 
	// jvai passer le vrai a la fonction puis free la valeur de save
	// voir le moment opportun pour free 
	while (nbr_pipe >= 0)
	{
		printf("c3.12\n");
		if (save_ast)
		{
			printf("c3.13\n");
			// je me souvien de lancienne valeur de save ast
			// isolate cree save_ast (un nouveau save ast)
			save_ast = isolate_command_redir(save_ast -> save_ptr);
			printf("c3.14\n");
		}
		else
		{
			printf("c3.15\n");
			save_ast = isolate_command_redir(ptr);
			printf("c3.16\n");
		}
		
		
		if (save_ast)
		{
			printf("c3.17\n");
			printf("i is : %i\n", i);
			// okg capter si ya pas de command ca vaut null
			// du coup ast[i] = NULL
			// du coup je ne peux pas faire ast[i] -> redir, ca va segfault
			// en gros si jamais ya pas de commad il faut qund meme que jen voi une node vide
			// comme ca je pourrais la remplir
			if (save_ast -> command)
				ast[i] = save_ast -> command;
			else
			{
				ast[i] = malloc(sizeof(t_com));
				ast[i] -> txt = NULL;
			}
			printf("c3.18\n");
			if (ast[i])
			{
				printf("c3.19\n");
				ast[i] -> redir = save_ast -> redir;
				printf("c3.20\n");
			}
			free(save_ast);
			printf("c3.21\n");
			i++;
		}
		// c ici quon free lancien save ast
		printf("c3.22\n");
		nbr_pipe--;
	}
	return (ast);
}

// qund je met juste < sans rien avant ca fonctionne pas
// il me compte ni comme une redir ni l suite
// voir pk
// et en plus ca creer des leaks
// qund ca c regler voir les read bizzare
// une fois que c bon voit tous le stests sans parenthese
// puis faire logique parenthese et voir tous les test sans parentheses
t_ast *isolate_command_redir(t_node *ptr)
{
	
	t_ast  *save_ast;
	t_redir *redir;
	t_com	*com;
	t_redir *follow;
	printf("c3.13.1\n");
	if (!ptr)
		return (NULL);
	printf("c3.13.2\n");
	com = NULL;
	redir = NULL;
	if (ptr)
	{
		printf("c3.13.3\n");
		// decoupe la command et arguments
		while (ptr && ft_stcmp(ptr -> txt, "|") != 1 && ft_stcmp(ptr -> txt, "<") != 1 && ft_stcmp(ptr -> txt, ">") != 1)
		{
			printf("c3.13.4\n");
			com = create_com_node(com, ptr);
			printf("c3.13.5\n");
			ptr = ptr -> next_sibling;
			printf("c3.13.6\n");
		}
		if (ptr)
		{
			printf("c3.13.7\n");
			if (ft_stcmp(ptr -> txt, "<") == 1 || ft_stcmp(ptr -> txt, ">") == 1 )
			{
				printf("c3.13.8\n");
				while (ptr && ft_stcmp(ptr -> txt, "|") != 1)
				{
					printf("c3.13.9\n");
					if ((ptr -> next_sibling  && ft_stcmp(ptr -> next_sibling -> txt, "<") == 1) || (ptr -> next_sibling  && (ft_stcmp(ptr -> next_sibling -> txt, ">") == 1 )))
					{
						printf("c3.13.10\n");
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
						{
							printf("c3.13.11\n");
							redir = create_redir_node(redir, ptr);
							if (redir)
							{
								follow = redir;
								while (follow)
								{
									printf("redir is %s\n", follow -> txt);
									follow = follow -> next_sibling;
								}
							}
							printf("c3.13.12\n");
						}
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
						{
							printf("c3.13.13\n");
							ptr = ptr -> next_sibling;
							printf("c3.13.14\n");
						}
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
						{
							printf("c3.13.15\n");
							ptr = ptr -> next_sibling;
							printf("c3.13.16\n");
						}
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
						{
							printf("c3.13.17\n");
							redir = create_redir_node(redir, ptr);
							printf("c3.13.18\n");
						}
					}
					else if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
					{
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
						{
							printf("c3.13.19\n");
							redir = create_redir_node(redir, ptr);
							if (redir)
							{
								follow = redir;
								while (follow)
								{
									printf("redir is %s\n", follow -> txt);
									follow = follow -> next_sibling;
								}
							}
							printf("c3.13.20\n");
						}
						if (ptr )
						{
							printf("c3.13.21\n");
							ptr = ptr -> next_sibling;
							printf("c3.13.22\n");
						}
						if (ptr && ft_stcmp(ptr -> txt, "|") != 1) 
						{
							printf("c3.13.23\n");
							redir = create_redir_node(redir, ptr);
							if (redir)
							{
								follow = redir;
								while (follow)
								{
									printf("redir is %s\n", follow -> txt);
									follow = follow -> next_sibling;
								}
							}
							printf("c3.13.24\n");
						}
					}
					if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
					{
						printf("c3.13.25\n");
						ptr = ptr -> next_sibling;
						printf("c3.13.26\n");
					}
				}
			}
		}
	// avance prochaine command
		if (ptr)
		{
			printf("c3.13.27\n");
			ptr = ptr -> next_sibling;
			printf("c3.13.28\n");
		}
		// sauvegarde debut prochainne command + redir + command
		save_ast = malloc(sizeof(save_ast));
		printf("c3.13.29\n");
		if (com)
		{
			printf("c3.13.30\n");
			save_ast -> command = com;
			printf("c3.13.31\n");
		}
		
		if (redir)
		{
			printf("c3.13.32\n");
			save_ast -> redir = redir;
			if (redir)
			{
				follow = save_ast -> redir;
				while (follow)
				{
					printf("redir is %s\n", follow -> txt);
					follow = follow -> next_sibling;
				}
			}
			printf("c3.13.33\n");
		}
		if (ptr)
		{
			printf("c3.13.34\n");
			save_ast -> save_ptr = ptr;
			printf("c3.13.35\n");
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
