/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:59:30 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/17 21:44:29 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_node **head_stack_a, t_node **head_stack_b)
{
	rra(head_stack_a);
	rrb(head_stack_b);
}

void	pb(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*ptr;

	ptr = *head_stack_a;
	if (*head_stack_a == NULL)
		return ;
	else
	{
		add_beg(ptr -> data, head_stack_b);
		del_first_node(head_stack_a);
	}
}

void	pa(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*ptr;

	ptr = *head_stack_b;
	if (*head_stack_b == NULL)
		return ;
	else
	{
		add_beg(ptr -> data, head_stack_a);
		del_first_node(head_stack_b);
	}
}

int	is_empty(t_node **head_stack_a)
{
	t_node	*ptr;

	ptr = *head_stack_a;
	if (ptr == NULL)
		return (1);
	return (0);
}
