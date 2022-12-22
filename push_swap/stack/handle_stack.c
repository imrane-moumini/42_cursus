/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:53 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/22 17:39:28 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_beg(int stack_data, t_node **head)
{
	t_node	*ptr;
	t_node	*tmp;
	
	if (head == NULL)
		return ;
	ptr = malloc(sizeof(t_node));
	ptr -> data = stack_data;
	ptr -> index = 0;
	ptr -> pos = 0;
	ptr -> target_pos = 0;
	ptr -> cost_a = 0;
	ptr -> cost_b = 0;
	ptr -> next = NULL;
	if (*head == NULL)
	{
		*head = ptr;
		return ;
	}
	tmp = *head;
	*head = ptr;
	ptr -> next = tmp;
}

void	del_first_node(t_node **head)
{
	t_node	*ptr;
	t_node	*tmp;

	if (head == NULL)
		return ;
	ptr = *head;
	if (ptr == NULL)
		return ;
	if (ptr -> next == NULL)
	{
		free(ptr);
		*head = NULL;
		ptr = NULL;
		return ;
	}
	else
	{
		tmp = ptr -> next;
		*head = tmp;
		free(ptr);
		ptr = NULL;
		tmp = NULL;
	}
}

void	ft_swap(t_node **head)
{
	t_node	*ptr;
	int		nbr;

	if (head == NULL)
		return ;
	ptr = *head;
	if (ptr == NULL)
		return ;
	if (ptr -> next == NULL)
		return ;
	else
	{
		nbr = ptr -> next -> data;
		ptr -> next -> data = ptr -> data;
		ptr -> data = nbr;
		ptr = NULL;
	}
}

t_node	*ft_last_node(t_node *head)
{
	if (head == NULL)
		return (head);
	if (head -> next == NULL)
		return (head);
	while (head -> next != NULL)
	{
		head = head -> next;
	}
	return (head);
}

void	ft_rotate(t_node **head, t_node *last_node)
{
	t_node	*ptr;
	t_node	*tmp;

	if (head == NULL)
		return ;
	ptr = *head;
	if (ptr == NULL)
		return ;
	if (ptr -> next == NULL)
		return ;
	else
	{
		tmp = ptr -> next;
		*head = tmp;
		last_node -> next = ptr;
		ptr -> next = NULL;
		tmp = NULL;
		ptr = NULL;
	}
}
