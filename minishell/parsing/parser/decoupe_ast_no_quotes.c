/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:31:15 by imrane            #+#    #+#             */
/*   Updated: 2023/03/17 17:38:33 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// free nouveaux ast
	// free ast command et argument
	// free ast pipe, redirection et nom de fichier à créer

// si ast oipe et redirection = NULL c que ya pas de redirection ou pipe

// ast redirection et nom de fichier à créer
// en fait je met juste redirection et fichier
// pipe pas besoin car je lke saurais au nbr de command
// pour cahque commanbd je mets la redirection et le fichier
// je vaius lire en premier ce fichier pour savoir si ya infile
	// en fait je compte ke nombre de pipe 
		// j'aurais le, nbr de command 
			// si ya plus d'une command c que l'input de la prochaine est la sortie de la précedente
			
	// seukl le pipe separe les command
	// la redirection est a linterieur d'unne command
	// un tableau par commande
	// si ya quotes je regroupe pour avoir double quote et pas 2 simple quotes
	// je les mets à la suite
	// si ya quote ou double quotes ce qui se trouve à la droite imédiat c le nom du fichier
	// tu sais que si ya pipe le nombre de command = nombre de pipe *2
	
// ast command et arguments
	// je créer un tableau qui contient des list chainé
		// chaque index représnete une command , la liste se terlmine  par NULL
	// tout ce qui est avant les redirection et les pipes
	// je doit retirer les guillemest quand j'envoie à excecv
	
// une fois les 2 data structure créé je free la première


t_com **create_ast_command_redir(t_node *root)
{
	t_com **ast;
	t_ast  *save_ast;
	t_node *ptr;
	int	nbr_pipe;
	int i;
	
	save_ast = NULL;
	printf("c2.1\n");
	if (!root)
		return (NULL);
	ptr = root -> first_child;
	i = 0;
	printf("c2.2\n");
	nbr_pipe = how_much_pipe(root);
	printf("c2.3\n");
	if (nbr_pipe > 0)
	{
		printf("c2.4\n");
		ast = malloc(sizeof(t_com *) * ((nbr_pipe *2) + 1));
		printf("c2.5\n");
		ast[(nbr_pipe *2)] = NULL;
	}
	else
	{
		printf("c2.6\n");
		ast = malloc(sizeof(t_com *) + 1);
		printf("c2.7\n");
		ast[1] = NULL;
		printf("c2.8\n");
	}

	printf("c2.9\n");
	
	while (ast[i] != NULL)
	{
		printf("c2.10\n");
		// le pb c ici dans save-ast command et redir existe pas, voir pk
		if (save_ast)
		{
			printf("i exist\n");
			save_ast = isolate_command_redir(save_ast -> save_ptr);
		}
		else
		{
			printf("im not exist\n");
			save_ast = isolate_command_redir(ptr);
		}
		printf("c2.11\n");
		
		if (save_ast)
		{
			if (save_ast -> command)
				printf("command exist\n");
			if (save_ast -> redir)
				printf("redir exist\n");
			ast[i] = save_ast -> command;
			printf("c2.12\n");
			if (ast[i])
				ast[i] -> redir = save_ast -> redir;
			printf("c2.13\n");
		}
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
		printf("c2.10.1\n");
		while (ptr && ft_stcmp(ptr -> txt, "|") != 1)
		{
			printf("c2.10.2\n");
			if (ft_stcmp(ptr -> txt, "<") == 1 || ft_stcmp(ptr -> txt, ">") == 1 )
			{
				printf("c2.10.3\n");
				redir = create_redir_node(redir, ptr);
				printf("c2.10.4\n");
				if (ft_stcmp(ptr -> next_sibling -> txt, "<") == 1 || ft_stcmp(ptr -> next_sibling -> txt, ">") == 1 )
				{
					printf("c2.10.5\n");
					redir = create_redir_node(redir, ptr);
					//print_redir(redir);
					printf("c2.10.6\n");
					ptr = ptr -> next_sibling;
					printf("c2.10.7\n");
					ptr = ptr -> next_sibling;
					printf("c2.10.8\n");
				}
				else
				{
					printf("c2.10.9\n");
					ptr = ptr -> next_sibling;
					printf("c2.10.10\n");
					redir = create_redir_node(redir, ptr);
					printf("c2.10.11\n");
				}
			}
			// ok le pb se trouve vers la, genre je creer rien au final, a guetter
			if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			{
				printf("c2.10.12\n");
				com = create_com_node(com, ptr);
				// ok com existe jamais
				// ok regler le pb , maintenant le pb c que ca saute un mot
				if (com)
					printf("com exist\n");
				printf("c2.10.13\n");
				printf("c2.10.14\n");
				if (ptr)
					ptr = ptr -> next_sibling;
				printf("c2.10.15\n");
			}
		}
		if (ptr)
			ptr = ptr -> next_sibling;
		printf("c2.10.16\n");
		if (save_ast)
		{
			save_ast -> command = com;
			printf("c2.10.17\n");
			save_ast -> redir = redir;
			printf("c2.10.18\n");
			save_ast -> save_ptr = ptr;
			printf("c2.10.19\n");
		}
	}
	// la struct qui se souvient e la command + des redir
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
		printf("c4.2\n");
		print_command(ast[i]);
		printf("c4.3\n");
		print_redir(ast[i] -> redir);
		printf("c4.4\n");
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
	printf("c4.2.1\n");
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
		ft_printf("redir is =>%s\n");
		ft_printf("%s\n",ptr -> txt);
		ptr = ptr -> next_sibling;
	}
}

// mes fnctions return NULL savoir pk
// mme ptr -> txt n'exsite pas
	// carrement je crois que ca vaut meme pas nul genre jlai meem pas alouer ou jsai pas
	// du coup ca segfault
// vasy je vais voir la valeur de mes struct au fil des tours pour trouver le pb
// g trouve, le pb c aue ast -> command et redir existe pas
// c bon command regler , la faut je fix pk redir existe pas quand jen creer