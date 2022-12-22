/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:34:11 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/22 17:37:16 by imoumini         ###   ########.fr       */
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


// void find_target_pos(t_node *ptr_a, t_node *ptr_b)
// {
    
//    // ne conserver que les index les plus grands
//     // se souvenir de tous ces elements
//    // comparer ses index et voir le plus proche
//     // soustrire lindex de lelement de la pile A et celui de la pile B c comme ca que je vais savoir
//     // celui qui a lecat le plus petit gagne et si c egal je choisi au hasard
// // je peux pas le sauvgarder dans la struct parce que je dois assisgner la vaeur a a stuct
// // je dois en fait vraimemebt me souvenir de toutes le infos de la stack a et comarer

// // si c le plus grand, prendre comme target pos, la pos de lindex le plus petit

    
//     while (ptr_a != NULL)
//     {
//         if (ptr_a -> index > ptr_b -> index)
//         {
            
//         }
//     }
    
// }
// // faire position cible
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
//     while (ptr_b != NULL)
//     {
//         find_target_pos(ptr_a, ptr_b);
//         ptr_b = ptr_b -> next;
//     }
// }