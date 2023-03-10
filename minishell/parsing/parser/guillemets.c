/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guillemets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:17:11 by imrane            #+#    #+#             */
/*   Updated: 2023/03/10 21:14:05 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
// si guillemets (singlke ou double quote) pas fermé
// lacher une erreur
// le mettre dans la fonction qui gère les erreurs
// en gros faut tjr un nombre pair de guillemets
    // je compte toute les guillemets genre si ' single et si double
    // je regarde si le nbr de single ou de double et pair sinon c cuit

int single_quote_closed(t_node *head)
{
	t_node *ptr;
    int count;
    
    count = 0;
    if (!head)
        return (2);
    ptr = head -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "'") == 1)
            count++;
        ptr = ptr -> next_sibling;
    }
    if (count % 2 != 0)
    {
        ft_printf("error : single quote are not closed\n");
        return (0);
    }
    return (1);
}

int quote_closed(t_node *head)
{
    if (single_quote_closed(head) == 0)
        return (0);
    return (1);
}