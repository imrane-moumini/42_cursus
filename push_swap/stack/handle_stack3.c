/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:44 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/15 17:27:47 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **head_stack_a)
{
	t_node *last_node;
	last_node = ft_last_node(*head_stack_a);
	ft_rotate(head_stack_a, last_node);
}

void	rb(t_node **head_stack_b)
{
	t_node *last_node;
	last_node = ft_last_node(*head_stack_b);
	ft_rotate(head_stack_b, last_node);
}

void	rr(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node *last_node_a;
	t_node *last_node_b;
	last_node_a = ft_last_node(*head_stack_a);
	last_node_b = ft_last_node(*head_stack_b);
	ft_rotate(head_stack_a, last_node_a);
	ft_rotate(head_stack_b, last_node_b);
}

void	rra(t_node **head_stack_a)
{
	ft_reverse_rotate(head_stack_a);
}

void	rrb(t_node **head_stack_b)
{
	ft_reverse_rotate(head_stack_b);
}



