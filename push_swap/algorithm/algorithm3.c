/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:05 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/17 21:57:43 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// etape 1 : pb tout sauf 3
// etape 2 : trier la pile a
// etape 3 : boucle tant que b nest pas vide
	// trouver la position des element de a et b
	// calculer la position cible dans la pile a ou chaque element de la pile b devrait etre
	// Calculer le nombre d’actions (le coût) pour mettre chaque élément de la pile B à sa position cible dans la pile A et choisir l’élément le moins coûteux.
	// Effectuer la suite d’actions pour déplacer l’élément de la pile B vers la pile A.
//etape 4 : si la pile a nest pas trie, alterner entre ra et rra jusquq quelle soit dans lordre

int	nbr_element_in_stack(t_node *head)
{
	int counter;
	
	counter = 0;
	ptr = head;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr -> next;
	}
	return (counter);
}

void	send_element_to_b_unless_three(t_node **head_stack_a, t_node **head_stack_b)
{
	// tri 1 de b :
	
	// tri 2 de b :
}