/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:27:32 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/16 23:21:08 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// faire fonction qui regqrde si ya besoin de trier ou pas

// 2 nb
	// sa
// 3 nb
	// 6 cas (3 actions : ra rra sa)
	// si 'l'index du premier nb est le plus grand => ra
	// si l'index du deuxieme nb est plus grand => rra
	// si l'index du premier nb > lindex du deuxieme nb => sa
// plu de 3 nb
	// calculer la liste daction la moins longue

int has_to_tri(t_node **head)
{
    t_node *ptr;
    ptr = *head;
    
    while (ptr -> next != NULL)
    {
        if (ptr -> data > ptr -> next -> data)
            return (1); 
        ptr = ptr -> next;
    }
    return (0);
}

void ft_tri(t_node **head_stack_a, t_node **head_stack_b, int nbr)
{
    (void)head_stack_b;
    if (nbr <= 2)
        sa(head_stack_a);
    // if (nbr == 3)
    //     ft_tri_three(head);
    // else
    //     ft_tri_more_than_three(head);
}
