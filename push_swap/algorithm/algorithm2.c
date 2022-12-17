/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:27:32 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/17 14:51:21 by imoumini         ###   ########.fr       */
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

int which_three_index_is_max(t_node **head_stack_a)
{
    t_node *first;
    t_node *second;
    t_node *third;
    t_node *ptr;
    
    ptr = *head_stack_a;
    first = ptr;
    second = ptr -> next;
    third = ptr -> next -> next;
    if (first -> index > second -> index && first -> index > third -> index)
        return (1);
    if (second -> index > first -> index && second -> index > third -> index)
        return (2);
    return (0);
}


// je regrad qui a le plus grand index puis je fais la commande
// puis je regarde a nouveau si je dois trier puis je fais index + commande
void ft_tri_three(t_node **head_stack_a)
{

    while (has_to_tri(head_stack_a) == 1)
    {
        t_node *first;
        t_node *second;
        t_node *ptr;
        
        ptr = *head_stack_a;
        first = ptr;
        second = ptr -> next;
        if (has_to_tri(head_stack_a) == 1 && which_three_index_is_max(head_stack_a) == 1)
        {
            ft_printf("ra\n");
            ra(head_stack_a);
            ptr = *head_stack_a;
            first = ptr;
            second = ptr -> next;
            if (has_to_tri(head_stack_a) == 1 && first -> index > second -> index)
            {
                ft_printf("sa\n");
                sa(head_stack_a);
            }
        }
        if (has_to_tri(head_stack_a) == 1 && which_three_index_is_max(head_stack_a) == 2)
        {
            ft_printf("rra\n");
            rra(head_stack_a);
            ptr = *head_stack_a;
            first = ptr;
            second = ptr -> next;
            if (has_to_tri(head_stack_a) == 1 && first -> index > second -> index)
            {
                ft_printf("sa\n");
                sa(head_stack_a);
            }
        }
        if (has_to_tri(head_stack_a) == 1 && which_three_index_is_max(head_stack_a) == 0)
        {
            ft_printf("sa\n");
            sa(head_stack_a);
        }
    }
}

void ft_tri(t_node **head_stack_a, t_node **head_stack_b, int nbr)
{
    (void)head_stack_b;
    if (nbr <= 2)
    {
        ft_printf("sa\n");
        sa(head_stack_a);
    }
    if (nbr == 3)
        ft_tri_three(head_stack_a);
    // else
    //     ft_tri_more_than_three(head);
}
