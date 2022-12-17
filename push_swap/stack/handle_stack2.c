/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:49 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/17 14:49:34 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_before_last_node(t_node *head)
{
	if (head == NULL)
		return (head);
	if (head -> next == NULL)
		return (NULL);
	while (head -> next -> next != NULL)
	{
		head = head -> next;
	}
	return (head);
}

void	ft_reverse_rotate(t_node **head)
{
	t_node	*ptr;
	//t_node	*tmp;
	t_node	*last_node;
	t_node	*before_last_node;

	last_node = ft_last_node(*head);
	before_last_node = ft_before_last_node(*head);
	ptr = *head;
	if (ptr == NULL)
		return ;
	if (ptr -> next == NULL)
		return ;
	if (ptr -> next -> next == NULL)
	{
		*head = last_node;
		last_node -> next = ptr;
		ptr -> next = NULL;
	}
	else
	{
		last_node -> next = *head;;
		*head = last_node;
		before_last_node -> next = NULL;
	}
}

void	sa(t_node **head_stack_a)
{
	ft_swap(head_stack_a);
}

void	sb(t_node **head_stack_b)
{
	ft_swap(head_stack_b);
}

void	ss(t_node **head_stack_a, t_node **head_stack_b)
{
	ft_swap(head_stack_a);
	ft_swap(head_stack_b);
}
