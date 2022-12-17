/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:05 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/17 22:35:30 by imoumini         ###   ########.fr       */
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
void	ft_tri_more_than_three(t_node **head_stack_a, t_node **head_stack_b, int nbr)
{
	send_element_to_b_unless_three(head_stack_a, head_stack_b, nbr/2);
}
int	nbr_element_in_stack(t_node *head)
{
	t_node	*ptr;
	int		counter;

	counter = 0;
	ptr = head;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr -> next;
	}
	return (counter);
}

void	send_element_to_b_unless_three(t_node **head_stack_a, t_node **head_stack_b, int mediane)
{
	// tri 1 de b (savoir quoi envoyer de a vers b):
		// si un element a un index plus petit que la médiane de tous les éléments, on l’envoie à la pile B, sinon, on rotate A
	t_node	*ptr_a;

	ptr_a = *head_stack_a;
	while (ptr_a != NULL)
	{
		if (ptr_a -> index < mediane)
			pb(head_stack_a, head_stack_b);
		else
		{
			ra(head_stack_a);
			ptr_a = *head_stack_a;
		}
	}
	// tri 2 de b : pb tout le reste des éléments sauf les trois derniers qui restent dans la pile A.
	while (nbr_element_in_stack(ptr_a) != 3)
		pb(head_stack_a, head_stack_b);
}