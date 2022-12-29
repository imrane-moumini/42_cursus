/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:53 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/29 16:43:09 by imoumini         ###   ########.fr       */
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
	ptr -> index_sup = 0;
	ptr -> pos_diff = 0;
	ptr -> min_index = 0;
	ptr -> max_index = 0;
	ptr -> next = NULL;
	// printf("FEFEFE\n");
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
		// ft_printf("ft_swap 1\n");
	    // ft_printf_stack(head, NULL);
		tmp = ptr->next; // 2
		ptr->next = tmp->next; //
		tmp->next = ptr; // adresse du premier
		*head = tmp;
		// tmp -> next = ptr;
		ptr = NULL;
		// ft_printf("ft_swap 2\n");
	    // ft_printf_stack(head, NULL); 
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
