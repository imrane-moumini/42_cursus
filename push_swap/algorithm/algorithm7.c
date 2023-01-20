/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:48 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 21:50:39 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mark_min_and_max_index(t_node **head_stack_a, int max)
{
	t_node	*ptr;

	if (head_stack_a == NULL)
		return ;
	if (*head_stack_a == NULL)
		return ;
	ptr = *head_stack_a;
	while (ptr != NULL)
	{
		if (ptr -> index == 0)
			ptr -> min_index = 1;
		if (ptr -> index == max)
			ptr -> max_index = 1;
		ptr = ptr -> next;
	}
}

int	is_index_zero_on_top(t_node **head_stack_a)
{
	t_node	*ptr;

	if (head_stack_a == NULL)
		return (0);
	if (*head_stack_a == NULL)
		return (0);
	ptr = *head_stack_a;
	if (ptr -> index == 0)
		return (1);
	else
		return (0);
}

void	ft_calculate_coup_to_min(t_node **head_stack_a, t_node *ptr)
{
	int	nbr;
	int	lenght;

	nbr = nbr_element_in_stack(*head_stack_a) / 2;
	lenght = nbr_element_in_stack(*head_stack_a);
	if (nbr % 2 == 1)
		nbr = nbr + 1;
	if (ptr -> pos == 1)
	{
		ptr -> cost_a = 0;
		return ;
	}
	if (ptr -> pos <= nbr)
		ptr -> cost_a = ptr -> pos - 1;
	if (ptr -> pos > nbr)
		ptr -> cost_a = ((lenght - ptr -> pos) + 1) * -1;
}

void	ft_execute_instruction_min(t_node **head_a, t_node **head_b, t_node *p)
{
	int	i;

	i = 0;
	if (p -> cost_a > 0)
	{
		while (i < p -> cost_a && p -> cost_a != 0)
		{
			ra(head_a, head_b);
			i++;
		}
	}
	else
	{
		p -> cost_a = p -> cost_a * -1;
		while (i < p -> cost_a && p -> cost_a != 0)
		{
			rra(head_a, head_b);
			i++;
		}
	}
}

void	put_min_index_top(t_node **head_stack_a)
{
	int		max;
	t_node	*ptr;

	if (head_stack_a == NULL)
		return ;
	if (*head_stack_a == NULL)
		return ;
	ptr = *head_stack_a;
	max = find_index_max(head_stack_a);
	mark_min_and_max_index(head_stack_a, max);
	ft_calculate_pos(head_stack_a, NULL);
	if (is_index_zero_on_top(head_stack_a) == 0)
	{
		while (ptr != NULL)
		{
			if (ptr -> index == 0)
			{
				ft_calculate_coup_to_min(head_stack_a, ptr);
				ft_execute_instruction_min(head_stack_a, NULL, ptr);
			}
			ptr = ptr -> next;
		}
	}
}