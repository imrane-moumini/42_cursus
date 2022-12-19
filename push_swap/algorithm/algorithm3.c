/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:05 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/19 12:29:18 by imoumini         ###   ########.fr       */
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
	// Etape 1
	send_element_to_b_unless_three(head_stack_a, head_stack_b, nbr/2);
	// Etape 2
	ft_tri_three(head_stack_a);
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

// Etape 1 :

int is_index_smaller_than_mediane(t_node **head_stack_a, int mediane)
{
	t_node *ptr;

	ptr = *head_stack_a;
	
	while (ptr != NULL)
	{
		if (ptr -> index < mediane)
			return (1);
		ptr = ptr -> next;
	}
	return (0);
}
void	send_element_to_b_unless_three(t_node **head_stack_a, t_node **head_stack_b, int mediane)
{
	// tri 1 de b (savoir quoi envoyer de a vers b):
		// si un element a un index plus petit que la médiane de tous les éléments, on l’envoie à la pile B, sinon, on rotate A
	while (is_index_smaller_than_mediane(head_stack_a, mediane) == 1) // jusqua ce qu'il y ait plus delement en dessous de la mediane
	{
		if ((*head_stack_a) -> index < mediane)
		{
			ft_printf("pb\n");
			pb(head_stack_a, head_stack_b);
		}
		else
		{
			ft_printf("ra\n");
			ra(head_stack_a);
		}
	}
	// tri 2 de b : pb tout le reste des éléments sauf les trois derniers qui restent dans la pile A.
	while (nbr_element_in_stack(*head_stack_a) > 3)
		pb(head_stack_a, head_stack_b);
}
