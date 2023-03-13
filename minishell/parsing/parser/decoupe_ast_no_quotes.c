/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_ast_no_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:31:15 by imrane            #+#    #+#             */
/*   Updated: 2023/03/13 22:40:27 by imrane           ###   ########.fr       */
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


t_com **create_ast_command(t_node *root)
{
	t_com **ast;
	int	nbr_pipe;
	int i;
	
	i = 0;
	// je compte le nbr de pipe
	// je créer un tab de pointeur de node
		// si ya 0 pipe je fais juste 1 tab
		// j'alloue autant d'index qu'il y a de pipe * 2
	nbr_pipe = how_much_pipe(root);
	if (nbr_pipe > 0)
	{
		ast = malloc(sizeof(t_com *) * ((nbr_pipe *2) + 1));
		ast[(nbr_pipe *2)] = NULL;
	}
	else
	{
		ast = malloc(sizeof(t_com *) + 1);
		ast[1] = NULL;
	}
	
	// dans chaque index que je connais l'adresse de la première node
	// du coup la je copy node dans une node vierge
	// je rebranche tout
	// la premiere node je la met comme adresse de l'index
	while (ast[i] != NULL)
	{
		// fonction qui decoupe command 
			// ski est compliqué c que je dois pas prendre
			// la redirection et ski est à sa droite immédia
		ast[i] = // command + redir, premier butes c command et autre vytes c redir
		i++;
	}
}

t_ast *isolate_command_redir(t_node *root)
{
	t_node *ptr;
	t_ast  *save_ast;
	t_redir *redir;
	t_com	*com;

	com = NULL;
	redir = NULL;
	save_ast = NULL;
	if (!root)
		return (NULL);
	
	ptr = root -> first_child;
	
	if (ptr)
	{
		// si j'ai < ou > je skipp + ski est à la droite immédiat
		// du coup j'avance jusqu'a ce que j'ai | ou NULL
		// si c NULL c que g tout avancé 
		// faut que je garde le compte des avancé
		// ce que je ne prends pas je le met direct dans l'autre objet

		// on peut avoir uniquement des redirections de fichier sans commande
		// voir avec mathieu ça et rester sur cette logique pour le moment
		// tester la logique et voir si ça casse pas 
		while (ptr && ft_stcmp(ptr -> txt, "|") != 1)
		{

			if (ft_stcmp(ptr -> txt, "<") == 1 || ft_stcmp(ptr -> txt, ">") == 1 )
			{
				// attention géré si g 2 fois à la suite
				ptr = ptr -> next_sibling;
				if (ptr)
					ptr = ptr -> next_sibling;
			}
			create_com_node(com);
			com -> txt = ptr -> txt;
			
			ptr = ptr -> next_sibling;
		}
		if (ptr)
			ptr = ptr -> next_sibling
		save_ast = malloc(sizeof(save_ast));
		save_ast -> command = com;
		save_ast -> redir = ptr;
	}
	// la struct qui se souvient e la command + des redir
	return (save_ast);
}