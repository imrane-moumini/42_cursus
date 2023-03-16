/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node_commannd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:18:31 by imrane            #+#    #+#             */
/*   Updated: 2023/03/16 21:42:09 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com *create_com_node(t_com *com, t_node *node)
{
	t_com *ptr;
	t_com *follow;
	ptr = malloc(sizeof(t_com));
	if (!node)
		return (NULL);
	// si existe pas t la tete sinon t kle suivant
	// ok c ici je renvois le mauvais truc
	// je veux renvoyer la limked list en me souvenant tjr de la tete 
	if (!com)
	{
		printf("im the head, my value is =>%s\n", node -> txt);
		
		ptr -> txt = malloc(sizeof(char)* ((ft_strlen(node -> txt) + 1)));
		ft_strlcpy(ptr -> txt, node -> txt, ft_strlen(node -> txt) + 1);
		ptr -> next_sibling = NULL;
		com = ptr;
	}
	else
	{
		printf("im the next, my value is =>%s\n", node -> txt);
		// ok g caot2  en gros je vais pas plus loin dans l'ajout aue un element 
		// il faut aue je me permette dajouter plus
		// je creer une boucle
		follow = com;
		while (follow -> next_sibling != NULL)
			follow = follow -> next_sibling;
		follow -> next_sibling = ptr;
		ptr -> txt = malloc(sizeof(char)* ((ft_strlen(node -> txt) + 1)));
		ft_strlcpy(ptr -> txt, node -> txt, ft_strlen(node -> txt) + 1);
		ptr -> next_sibling = NULL;
	}
	return (com);
}