/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:20:46 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/30 15:44:31 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_max(t_node **head_stack_a)
{
	int max;
	t_node *ptr;
	
	max = 0;
	if (head_stack_a == NULL)
		return (0);
	if (*head_stack_a == NULL)
		return (0);
	ptr = *head_stack_a;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (max < ptr -> index)
			max = ptr -> index;
		ptr = ptr -> next;
	}
	return (max);
}

// int is_index_max_on_bottom(t_node **head_stack_a, int max)
// {
// 	t_node *ptr;
	
// 	if (head_stack_a == NULL)
// 		return (0);
// 	if (*head_stack_a == NULL)
// 		return (0);
// 	ptr = *head_stack_a;
// 	while (ptr -> next != NULL)
// 		ptr = ptr -> next;
// 	if (ptr -> index == max)
// 		return (1);
// 	else
// 		return (0);
// }

// void ft_calculate_coup_to_max(t_node **head_stack_a,t_node *ptr)
// {
// 	int nbr;
// 	int lenght;
	
// 	nbr = nbr_element_in_stack(*head_stack_a)/2;
// 	lenght = nbr_element_in_stack(*head_stack_a);
// 	if (nbr % 2 == 1)
// 		nbr = nbr + 1;
// 	if (ptr -> pos == 1)
// 	{
// 		ptr -> cost_a = 0;
// 		return ;
// 	}
// 	if (ptr -> pos <= nbr)
// 		ptr -> cost_a = ptr -> pos - 1;
// 	if (ptr -> pos > nbr)
// 		ptr -> cost_a = ((lenght - ptr -> pos) + 1) * -1;
// }

// void	put_max_index_down(t_node **head_stack_a)
// {
// 	int max;
// 	t_node *ptr;
	
// 	if (head_stack_a == NULL)
// 		return ;
// 	if (*head_stack_a == NULL)
// 		return ;
// 	ptr = *head_stack_a;
// 	max = find_index_max(head_stack_a);
// 	mark_min_and_max_index(head_stack_a, max);
// 	ft_calculate_pos(head_stack_a, NULL);
// 	if (is_index_max_on_bottom(head_stack_a, max) == 0)
// 	{
// 		while (ptr != NULL)
// 		{
// 			if (ptr -> index == max)
// 			{
// 				ft_calculate_coup_to_max(head_stack_a, ptr);
// 				ft_execute_instruction_max(head_stack_a,NULL,ptr);
// 			}
// 			ptr = ptr -> next;
// 		}
// 	}
	
// }