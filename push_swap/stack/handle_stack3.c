/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:02:44 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 19:24:21 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*last_node;

	ft_printf("ra\n");
	last_node = ft_last_node(*head_stack_a);
	ft_rotate(head_stack_a, last_node);
	ft_calculate_positions(head_stack_a, head_stack_b);
}

void	rb(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*last_node;

	ft_printf("rb\n");
	last_node = ft_last_node(*head_stack_b);
	ft_rotate(head_stack_b, last_node);
	ft_calculate_positions(head_stack_a, head_stack_b);
}

void	rr(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*last_node_a;
	t_node	*last_node_b;

	ft_printf("rr\n");
	last_node_a = ft_last_node(*head_stack_a);
	last_node_b = ft_last_node(*head_stack_b);
	ft_rotate(head_stack_a, last_node_a);
	ft_rotate(head_stack_b, last_node_b);
	ft_calculate_positions(head_stack_a, head_stack_b);
}

void	rra(t_node **head_stack_a, t_node **head_stack_b)
{
	ft_printf("rra\n");
	ft_reverse_rotate(head_stack_a);
	ft_calculate_positions(head_stack_a, head_stack_b);
}

void	rrb(t_node **head_stack_a, t_node **head_stack_b)
{
	ft_printf("rrb\n");
	ft_reverse_rotate(head_stack_b);
	ft_calculate_positions(head_stack_a, head_stack_b);
}
