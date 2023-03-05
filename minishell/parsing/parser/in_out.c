/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:17:23 by imrane            #+#    #+#             */
/*   Updated: 2023/03/05 17:39:51 by imrane           ###   ########.fr       */
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
	printf("c1\n");
    if (!ptr)
		return(2);
	printf("c2\n");
	if (ptr -> first_child)
		ptr = ptr -> first_child;
	while (ptr != NULL)
	{
		printf("c3\n");
		if (ft_stcmp(ptr -> txt, "<") == 1)
		{
			printf("c4\n");
			break;
		}
		ptr = ptr -> next_sibling;
		printf("c5\n");
	}
	// non concerné
	if (ptr == NULL)
		return (2);
	printf("c6\n");
	// ce que j'ai pas le droit de faire
	if (ptr -> next_sibling)
	{
		printf("c7\n");
		// si ya  <<
		if (ft_stcmp(ptr -> next_sibling -> txt, "<") == 1)
		{
			printf("c8\n");
			if ((ptr -> next_sibling -> next_sibling -> txt))
			{
				printf("c9\n");
				ft_printf("syntax error near unexpected token `newline'\n");
				return (0);
			}
			if (ptr -> next_sibling -> next_sibling)
			{
				printf("c10\n");
				if (ft_stcmp(ptr -> next_sibling -> next_sibling -> txt, "<") == 1 || ft_stcmp(ptr -> next_sibling -> next_sibling -> txt, ">") == 1)
				{
					printf("ptr -> txt : %s\n", ptr -> txt);
					printf("ptr -> txt next : %s\n", ptr -> next_sibling -> txt);
					printf("ptr -> txt next next: %s\n", ptr -> next_sibling -> next_sibling -> txt);
					printf("c11\n");
					ft_printf("syntax error near unexpected token '%s'\n", ptr -> next_sibling -> next_sibling -> txt);
					return (0);
				}
			}
			// ne pas expand
		}
	}
	else // si ya rien après le <
	{
		printf("c12\n");
		ft_printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
	
	// pas de pb
	return (1);
    
}