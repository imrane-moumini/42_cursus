/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:17:23 by imrane            #+#    #+#             */
/*   Updated: 2023/03/09 18:10:07 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
// boucle qui a chaque < va a la prochaine lettre puyis rpochain <

// in file
    // regarde si ya juste ça < ou si ya <<
        // si <
        // si <<
// out file

// tout ce que je fais il faiut que je les appelle de manière continue genre
// je decoupe tout en petite fonction

// reflechir a logoque de parcourir en premier
// le truc si ya un espace après les < je le gère dans le lexer direct

int ft_in_file(t_node *head)
{
    t_node *ptr;
    
	ptr = head;
    if (!ptr)
		return(2);
	if (ptr -> first_child)
		ptr = ptr -> first_child;
	while (ptr != NULL)
	{
		if (ft_stcmp(ptr -> txt, "<") == 1)
			break;
		ptr = ptr -> next_sibling;
	}
	// non concerné
	if (ptr == NULL)
		return (2);
	// ce que j'ai pas le droit de faire
	if (ptr -> next_sibling)
	{
		// si ya  <<
		if (ft_stcmp(ptr -> next_sibling -> txt, "<") == 1)
		{
			if (ptr -> next_sibling -> next_sibling == NULL)
			{
				ft_printf("syntax error near unexpected token `newline'\n");
				return (0);
			}
			if (ptr -> next_sibling -> next_sibling)
			{
				if (ft_stcmp(ptr -> next_sibling -> next_sibling -> txt, "<") == 1 || ft_stcmp(ptr -> next_sibling -> next_sibling -> txt, ">") == 1)
				{
					ft_printf("syntax error near unexpected token '%s'\n", ptr -> next_sibling -> next_sibling -> txt);
					return (0);
				}
			}
			// ne pas expand
		}
	}
	else // si ya un seul < et ya rien après le <
	{
		ft_printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
	if (ptr) // si ya un seul <
	{
		if (ptr -> next_sibling) // si ya un truc après le <
		{
			if (ft_stcmp(ptr -> next_sibling -> txt, ">") == 1 || ft_stcmp(ptr -> next_sibling -> next_sibling -> txt, ">") == 1)
				{
					ft_printf("syntax error near unexpected token '%s'\n", ptr -> next_sibling -> txt);
					return (0);
				}
		}
	}
	
	// pas de pb
	return (1);
    
}