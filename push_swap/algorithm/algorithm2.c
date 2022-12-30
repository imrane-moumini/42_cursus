/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:27:32 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/30 18:41:30 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void have_to_do_sa(t_node **head_stack_a)
{
    if (has_to_tri(head_stack_a) == 1 &&  (*head_stack_a) -> index > (*head_stack_a) -> next -> index)
    {
	    // ft_printf("have to do SA 1\n");
	    // ft_printf_stack(head_stack_a, NULL); 
        sa(head_stack_a, NULL);
	    // ft_printf("have to do SA 2\n");
	    // ft_printf_stack(head_stack_a, NULL); 
    }
}

void ft_tri_three(t_node **head_stack_a)
{
    while (has_to_tri(head_stack_a) == 1)
    {
        if (has_to_tri(head_stack_a) == 1 && which_three_index_is_max(head_stack_a) == 1)
        {
            ra(head_stack_a, NULL);
            have_to_do_sa(head_stack_a);
	        // ft_printf("ft_tri_three RA\n");
	        //ft_printf_stack(head_stack_a, NULL); 
        }
        else if (has_to_tri(head_stack_a) == 1 && which_three_index_is_max(head_stack_a) == 2)
        {
            rra(head_stack_a, NULL);
            have_to_do_sa(head_stack_a);
        }
        else if (has_to_tri(head_stack_a) == 1 && which_three_index_is_max(head_stack_a) == 0)
        {
            sa(head_stack_a, NULL);
            // ft_printf("ft_tri_three SA\n");
	        // ft_printf_stack(head_stack_a, NULL); 
        }
	    // ft_printf("ft_tri_three\n");
	    // ft_printf_stack(head_stack_a, NULL);        
    }
}

void ft_tri(t_node **head_stack_a, t_node **head_stack_b, int nbr)
{
    (void)head_stack_b;
    if (nbr <= 2)
    {
        sa(head_stack_a, head_stack_b);
    }
    if (nbr == 3)
        ft_tri_three(head_stack_a);
    else
        ft_tri_more_than_three(head_stack_a, head_stack_b, nbr);
}
