/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:25:42 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 19:28:09 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_beg_pb(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*ptr;
	t_node	*first;
	t_node	*tmp;

	if (*head_stack_a == NULL)
		return ;
	first = *head_stack_a;
	ptr = malloc(sizeof(t_node));
	ptr -> data = first -> data;
	ptr -> index = first -> index;
	ptr -> pos = first -> pos;
	ptr -> target_pos = first -> target_pos;
	ptr -> cost_a = first -> cost_a;
	ptr -> cost_b = first -> cost_b;
	ptr -> next = NULL;
	if (*head_stack_b == NULL)
	{
		*head_stack_b = ptr;
		return ;
	}
	tmp = *head_stack_b;
	*head_stack_b = ptr;
	ptr -> next = tmp;
}
