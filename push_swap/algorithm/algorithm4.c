/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:34:11 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/22 16:43:09 by imoumini         ###   ########.fr       */
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
    
    if (head_stack_a != NULL)
        ptr_a = *head_stack_a;
    else
        ptr_a = NULL;
    if (head_stack_b != NULL)
        ptr_b = *head_stack_b;
    else
        ptr_b = NULL;
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
//     t_node *ptr_a;
//     t_node *ptr_b;
//     // c la position dans la pile A ou lelement de la pile b voudrait se retrouver
//     // trouver dans la pile A l'index de lelement le plus proche (strictement superieur) de lelement de la pile b
//     // la position de leleent aui a cet index dans la pile a devient la target pos
//     // si lindex est plus grand que tous les autre index de la pile a, prendre la osition du plus petit index de la pile a
//     if (head_stack_a == NULL)
//         ptr_a = NULL;
//     else
//         ptr_a = *head_stack_a;
//     if (head_stack_b == NULL)
//         ptr_b = NULL;
//     else
//         ptr_b = *head_stack_b;
    
// }