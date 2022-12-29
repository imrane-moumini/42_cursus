/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:34:11 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/29 19:59:38 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// etape 3

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

// first passage

void first_passage(t_node *ptr_a, t_node *ptr_b, t_calculate *cal)
{
    while (ptr_a != NULL)
    {
        if (ptr_a -> index > ptr_b -> index)
        {
			cal -> index_greater = 0;
			ptr_a -> index_sup = 1;
			ptr_a -> pos_diff = ptr_a -> index - ptr_b -> index;
			cal -> node_pos = ptr_a -> pos;
			cal -> node_index_diff = ptr_a -> pos_diff;
        }
		else
		{
			cal -> mini_index = ptr_a -> index;
			cal -> node_pos = ptr_a -> pos;
		}
		ptr_a = ptr_a -> next;
    }
}
// index b le plus grand
// index b pas le plus grand

void b_index_not_greater(t_node *ptr_a, t_node *ptr_b, t_calculate *cal)
{
    while (ptr_a != NULL)
    {
        if (ptr_a -> index_sup == 1)
        {
            // printf("DATA %i\n", ptr_b->data);
            // printf("INDEX NOT GREATER ptr_a->pos_diff %i, cal->node_index_diff %i, ptr_a->index %i, ptr_b->index %i\n", ptr_a -> pos_diff, cal -> node_index_diff, ptr_a->index, ptr_b->index);
            // printf("INDEX NOT CAL cal->node_pos %i, cal->node_index_diff %i\n", cal -> node_pos, cal -> node_index_diff);
            if (ptr_a -> pos_diff <= cal -> node_index_diff && ptr_a->index > ptr_b->index)
			{
				cal -> node_pos = ptr_a -> pos;
				cal -> node_index_diff = ptr_a -> pos_diff;
			}
        }
		ptr_a = ptr_a -> next;
    }
	ptr_b -> target_pos = cal -> node_pos;
}
void find_target_pos(t_node *ptr_a, t_node *ptr_b)
{
    t_node *save;
	t_calculate cal;

	cal.index_greater = 1;
	save = ptr_a;
    first_passage(ptr_a, ptr_b, &cal);
	ptr_a = save;
    int cmp = INT_MAX;
    int position;
	// si lindex de b est le plus grand
	if (cal.index_greater == 1)
	{
		while (ptr_a != NULL)
    	{
        	if (ptr_a->index < cmp)
            {    
                cmp = ptr_a->index;
                position = ptr_a->pos;
            }    
			ptr_a = ptr_a->next;
   		}
        ptr_b -> target_pos = position;
		return ;
	}

	// si lindex de b nest pas le plus grand
	b_index_not_greater(ptr_a, ptr_b, &cal);
    
}

// faire position cible
void ft_calculate_target_pos(t_node **head_stack_a, t_node **head_stack_b)
{
    t_node *ptr_a;
    t_node *ptr_b;
    // c la position dans la pile A ou lelement de la pile b voudrait se retrouver
    // trouver dans la pile A l'index de lelement le plus proche (strictement superieur) de lelement de la pile b
    // la position de leleent aui a cet index dans la pile a devient la target pos
    // si lindex est plus grand que tous les autre index de la pile a, prendre la osition du plus petit index de la pile a
    if (head_stack_a == NULL)
        ptr_a = NULL;
    else
        ptr_a = *head_stack_a;
    if (head_stack_b == NULL)
        ptr_b = NULL;
    else
        ptr_b = *head_stack_b;
    while (ptr_b != NULL)
    {
        find_target_pos(ptr_a, ptr_b);
        ptr_b = ptr_b -> next;
    }
}