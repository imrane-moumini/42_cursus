/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:56:38 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/30 18:43:12 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// etape 5
t_instructions ft_min_cost(t_node **head_stack_b)
{
	t_node *ptr;
	t_instructions instructions;
	int min;
	
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
	while (ptr != NULL)
	{
		if (min == ptr -> total_cost)
		{
			instructions.cost_a = ptr -> cost_a;
			instructions.cost_b = ptr -> cost_b;
			//ft_printf("min in fonction : %i\n", min);
			return (instructions);
		}
		ptr = ptr -> next;
	}
	return (instructions);
}

void ft_execute_instructions(t_node **head_stack_a, t_node **head_stack_b,t_instructions instructions)
{
	int i;

	i = 0;
	//ft_printf("instructions cost a : %i, instructions cost b : %i\n", instructions.cost_a, instructions.cost_b);
	if (instructions.cost_a > 0)
	{
		while ((i < instructions.cost_a )&& instructions.cost_a != 0)
		{
			ra(head_stack_a, head_stack_b);
			i++;
		}
	}
	else
	{
		instructions.cost_a = instructions.cost_a * -1;
		while ((i < instructions.cost_a ) && instructions.cost_a != 0)
		{
			rra(head_stack_a, head_stack_b);
			i++;
		}
	}
	i = 0;
	if (instructions.cost_b > 0)
	{
		while (((i < instructions.cost_b) != 0 )&& instructions.cost_b > 0)
		{
			rb(head_stack_a, head_stack_b);
			i++;
		}
	}
	else
	{
		instructions.cost_b = instructions.cost_b * -1;
		while (((i < instructions.cost_b) != 0) && instructions.cost_b > 0)
		{
			rrb(head_stack_a, head_stack_b);
			i++;
		}
	}
	pa(head_stack_a, head_stack_b);
}

// pas derreur mais me semble pas fonctionner voir pk, c letape 5 