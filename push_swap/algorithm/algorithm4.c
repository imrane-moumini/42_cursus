/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:34:11 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/22 13:34:55 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// etape 3
void ft_calculate_positions(t_node **head_stack_a, t_node **head_stack_b)
{
    ft_calculate_pos(head_stack_a, head_stack_b);
    //ft_calculate_target_pos(head_stack_a, head_stack_b);
}

void ft_calculate_pos(t_node **head_stack_a, t_node **head_stack_b)
{
    t_node *ptr_a;
    t_node *ptr_b;
    int counter;

    ptr_a = *head_stack_a;
    ptr_b = *head_stack_b;
    counter = 0;
    while(ptr_a != NULL)
    {
        counter++;
        ptr_a -> pos = counter;
        ptr_a = ptr_a -> next;
    }
    counter = 0;
    while(ptr_b != NULL)
    {
        counter++;
        ptr_b -> pos = counter;
        ptr_b = ptr_b -> next;
    }
}



// faire position cible
// void ft_calculate_target_pos(t_node **head_stack_a, t_node **head_stack_b)
// {
    
// }