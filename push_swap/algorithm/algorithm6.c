/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:56:38 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 22:08:02 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_inst	ft_boucle_min_cost(t_node *ptr, int min)
{
	t_inst	instructions;

	instructions.cost_a = 0;
	instructions.cost_b = 0;
	while (ptr != NULL)
	{
		if (min == ptr -> total_cost)
		{
			instructions.cost_a = ptr -> cost_a;
			instructions.cost_b = ptr -> cost_b;
			return (instructions);
		}
		ptr = ptr -> next;
	}
	return (instructions);
}

t_inst	ft_min_cost(t_node **head_stack_b)
{
	t_node			*ptr;
	t_inst			instructions;
	int				min;

	instructions.cost_a = 0;
	instructions.cost_b = 0;
	if (head_stack_b == NULL)
		return (instructions);
	if (*head_stack_b == NULL)
		return (instructions);
	ptr = *head_stack_b;
	min = ptr -> total_cost;
	while (ptr != NULL)
	{
		if (min > ptr -> total_cost)
			min = ptr -> total_cost;
		ptr = ptr -> next;
	}
	ptr = *head_stack_b;
	instructions = ft_boucle_min_cost(ptr, min);
	return (instructions);
}

void	ft_execute_cost_a(t_node **head_a, t_node **head_b, t_inst ins)
{
	int	i;

	i = 0;
	if (ins.cost_a > 0)
	{
		while ((i < ins.cost_a) && ins.cost_a != 0)
		{
			ra(head_a, head_b);
			i++;
		}
	}
	else
	{
		ins.cost_a = ins.cost_a * -1;
		while ((i < ins.cost_a) && ins.cost_a != 0)
		{
			rra(head_a, head_b);
			i++;
		}
	}
}

void	ft_execute_cost_b(t_node **head_a, t_node **head_b, t_inst ins)
{
	int	i;

	i = 0;
	if (ins.cost_b > 0)
	{
		while (((i < ins.cost_b) != 0) && ins.cost_b > 0)
		{
			rb(head_a, head_b);
			i++;
		}
	}
	else
	{
		ins.cost_b = ins.cost_b * -1;
		while (((i < ins.cost_b) != 0) && ins.cost_b > 0)
		{
			rrb(head_a, head_b);
			i++;
		}
	}
}

void	ft_execute(t_node **head_a, t_node **head_b, t_inst ins)
{
	ft_execute_cost_a(head_a, head_b, ins);
	ft_execute_cost_b(head_a, head_b, ins);
	pa(head_a, head_b);
}
