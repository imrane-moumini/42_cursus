/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guillemets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:17:11 by imrane            #+#    #+#             */
/*   Updated: 2023/03/10 22:04:46 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

int double_quote_closed(t_node *head)
{
	t_node *ptr;
    int count;
    
    count = 0;
    if (!head)
        return (2);
    ptr = head -> first_child;
    while (ptr)
    {
        if (ft_stcmp(ptr -> txt, "\"") == 1)
            count++;
        ptr = ptr -> next_sibling;
    }
    if (count % 2 != 0)
    {
        ft_printf("error : double quote are not closed\n");
        return (0);
    }
    return (1);
}
int quote_closed(t_node *head)
{
    if (single_quote_closed(head) == 0)
		return (0);
	if (double_quote_closed(head) == 0)
		return (0);
    return (1);
}

// je vais dans la fonction qui expand seulement si ya pas de guillemts
	// si guillemets je gère l'expand différemment
// faire fonction qui isole les parti entre guuillemets
	// comme ça je manipule que cette partie
	// une fois manipuler je réintègre dans le truc initiale
	// si g fait maudif je ne vais pas dans la fonction qui expand
	
// trouver un moeyn de gérer ça que dans ce qui est entre les guillemets
// deja j'appelle la fonction qui gère tout ça avant expand et je met genre si vrai
// tu peux aller dans expand 

// ski est chaud c que je dois isoler la partie entre parenthèse des autre partie
// single quote meta
	// $
	// pipe
// double quote meta
	// $
	// pipe

// si pipe entre guillemets il faut que je le notifie a la fonction
// qui va exécuter comme ça elle utilise pas