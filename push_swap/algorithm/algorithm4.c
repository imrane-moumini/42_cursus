/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:34:11 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/24 16:04:16 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// etape 3
void ft_calculate_positions(t_node **head_stack_a, t_node **head_stack_b)
{
    ft_calculate_pos(head_stack_a, head_stack_b);
    ft_calculate_target_pos(head_stack_a, head_stack_b);
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


void find_target_pos(t_node *ptr_a, t_node *ptr_b)
{
    t_node *save;
	int		node_pos;
	int		node_index_diff;
	int		index_greater;
	int		mini_index;

	index_greater = 1;
	save = ptr_a;
	ft_printf("im in target pos\n");
    while (ptr_a != NULL)
    {
		ft_printf("c1\n");
        if (ptr_a -> index > ptr_b -> index)
        {
			ft_printf("c2\n");
			index_greater = 0;
			ptr_a -> index_sup = 1;
			ptr_a -> pos_diff = ptr_a -> index - ptr_b -> index;
			node_pos = ptr_a -> pos;
			node_index_diff = ptr_a -> pos_diff;
        }
		else
		{
			ft_printf("c3\n");
			mini_index = ptr_a -> index;
			node_pos = ptr_a -> pos;
		}
		ptr_a = ptr_a -> next;
    }
	ptr_a = save;
	// si lindex de b est le plus grand
	if (index_greater == 1)
	{
		ft_printf("c4\n");
		while (ptr_a != NULL)
    	{
			ft_printf("c5\n");
        	if (ptr_a -> index < mini_index)
			{
				ft_printf("c6\n");
				node_pos = ptr_a -> pos;
			}
			ptr_a = ptr_a -> next;
   		}
		ptr_b -> target_pos = node_pos;
		return ;
	}

	// si lindex de b nest pas le plus grand
	while (ptr_a != NULL)
    {
		ft_printf("c7\n");
        if (ptr_a -> index_sup == 1)
        {
			ft_printf("c8\n");
			if (ptr_a -> pos_diff < node_index_diff)
			{
				ft_printf("c9\n");
				node_pos = ptr_a -> pos;
				node_index_diff = ptr_a -> pos_diff;
			}
        }
		ptr_a = ptr_a -> next;
    }
	ptr_b -> target_pos = node_pos;
    
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
		ft_printf("im here\n");
        find_target_pos(ptr_a, ptr_b);
        ptr_b = ptr_b -> next;
    }
}