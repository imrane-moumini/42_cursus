/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:59:30 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/29 16:44:05 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_node **head_stack_a, t_node **head_stack_b)
{
	ft_printf("rrr\n");
	rra(head_stack_a, head_stack_b);
	rrb(head_stack_a,head_stack_b);
	ft_calculate_positions(head_stack_a, head_stack_b);
}

void	pb(t_node **head_stack_a, t_node **head_stack_b)
{
	if (*head_stack_a == NULL)
		return ;
	else
	{
		ft_printf("pb\n");
		add_beg_pb(head_stack_a, head_stack_b);
		del_first_node(head_stack_a);
		ft_calculate_positions(head_stack_a, head_stack_b);
	}
}

void	pa(t_node **head_stack_a, t_node **head_stack_b)
{
	if (*head_stack_b == NULL)
		return ;
	else
	{
		ft_printf("pa\n");
		add_beg_pa(head_stack_a, head_stack_b);
		del_first_node(head_stack_b);
		ft_calculate_positions(head_stack_a, head_stack_b);
	}
}

int	is_stack_empty(t_node **head_stack_a)
{
	t_node	*ptr;

	ptr = *head_stack_a;
	if (ptr == NULL)
		return (1);
	return (0);
}


void	add_beg_pa(t_node **head_stack_a, t_node **head_stack_b)
{
	// prend le premier element de b et le met sur a
	t_node	*ptr;
	t_node	*first;
	t_node	*tmp;
	
	if (*head_stack_b == NULL)
		return ;
	first = *head_stack_b;
	ptr = malloc(sizeof(t_node));
	ptr -> data = first -> data;
	ptr -> index = first -> index;
	// printf("PA first -> data %i, first -> index %i, ptr -> index %i\n", first -> data, first -> index, ptr -> index);
	ptr -> pos = first -> pos;
	ptr -> target_pos = first -> target_pos;
	ptr -> cost_a = first -> cost_a;
	ptr -> cost_b = first -> cost_b;
	ptr -> next = NULL;
	if (*head_stack_a == NULL)
	{
		*head_stack_a = ptr;
		return ;
	}
	tmp = *head_stack_a;
	*head_stack_a = ptr;
	ptr -> next = tmp;
}

void	add_beg_pb(t_node **head_stack_a, t_node **head_stack_b)
{
	// prend le premier element de a et le met sur b
	t_node	*ptr;
	t_node	*first;
	t_node	*tmp;
	
	if (*head_stack_a == NULL)
		return ;
	first = *head_stack_a;
	ptr = malloc(sizeof(t_node));
	ptr -> data = first -> data;
	ptr -> index = first -> index;
	// printf(" PB first -> data %i, first -> index %i, ptr -> index %i\n", first -> data, first -> index, ptr -> index);
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