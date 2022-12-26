/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:05 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/26 19:15:50 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_tri_more_than_three(t_node **head_stack_a, t_node **head_stack_b, int nbr)
{
	// Etape 1
	send_element_to_b_unless_three(head_stack_a, head_stack_b, nbr/2);
	// Etape 2
	ft_tri_three(head_stack_a);
	// Etape 3
	ft_calculate_positions(head_stack_a, head_stack_b);
	// Etape 4 et 5
	// tant que b n'est pas vide
	// je calcule les couts
	ft_calculate_cost(head_stack_a, head_stack_b);
		// je recupere lelement avec le cost le plus bas
		// je fais les instructions de la pile A et B
		// jenvoi lelement de B a A
	ft_execute_instructions(head_stack_a, head_stack_b,ft_min_cost(head_stack_b));
		
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
	while (is_index_smaller_than_mediane(head_stack_a, mediane) == 1)
	{
		if ((*head_stack_a) -> index < mediane)
		{
			ft_printf("pb\n");
			pb(head_stack_a, head_stack_b);
		}
		else
		{
			ft_printf("ra\n");
			ra(head_stack_a, head_stack_b);
		}
	}
	while (nbr_element_in_stack(*head_stack_a) > 3)
		pb(head_stack_a, head_stack_b);
}
