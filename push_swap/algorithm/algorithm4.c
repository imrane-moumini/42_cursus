/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:34:11 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 21:12:15 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_calculate_pos(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*ptr_a;
	t_node	*ptr_b;
	int		counter;

	if (head_stack_a != NULL)
		ptr_a = *head_stack_a;
	else
		ptr_a = NULL;
	if (head_stack_b != NULL)
		ptr_b = *head_stack_b;
	else
		ptr_b = NULL;
	counter = 0;
	while (ptr_a != NULL)
	{
		ptr_a -> pos = ++counter;
		ptr_a = ptr_a -> next;
	}
	counter = 0;
	while (ptr_b != NULL)
	{
		ptr_b -> pos = ++counter;
		ptr_b = ptr_b -> next;
	}
}

void	first_passage(t_node *ptr_a, t_node *ptr_b, t_calculate *cal)
{
	while (ptr_a != NULL)
	{
		if (ptr_a -> index > ptr_b -> index)
		{
			cal -> index_greater = 0;
			ptr_a -> index_sup = 1;
			ptr_a -> pos_diff = ptr_a -> index - ptr_b -> index;
			cal -> node_pos = ptr_a -> pos;
			cal -> node_index_diff = ptr_a -> pos_diff;
		}
		else
		{
			cal -> mini_index = ptr_a -> index;
			cal -> node_pos = ptr_a -> pos;
		}
		ptr_a = ptr_a -> next;
	}
}

void	b_index_not_greater(t_node *ptr_a, t_node *ptr_b, t_calculate *cal)
{
	while (ptr_a != NULL)
	{
		if (ptr_a -> index_sup == 1)
		{
			if (ptr_a -> pos_diff <= cal -> node_index_diff \
				&& ptr_a->index > ptr_b->index)
			{
				cal -> node_pos = ptr_a -> pos;
				cal -> node_index_diff = ptr_a -> pos_diff;
			}
		}
		ptr_a = ptr_a -> next;
	}
	ptr_b -> target_pos = cal -> node_pos;
}

void	find_target_pos(t_node *ptr_a, t_node *ptr_b)
{
	int			cmp;
	int			position;
	t_node		*save;
	t_calculate	cal;

	cmp = INT_MAX;
	cal.index_greater = 1;
	save = ptr_a;
	first_passage(ptr_a, ptr_b, &cal);
	ptr_a = save;
	if (cal.index_greater == 1)
	{
		while (ptr_a != NULL)
		{
			if (ptr_a->index < cmp)
			{
				cmp = ptr_a->index;
				position = ptr_a->pos;
			}
			ptr_a = ptr_a->next;
		}
		ptr_b -> target_pos = position;
		return ;
	}
	b_index_not_greater(ptr_a, ptr_b, &cal);
}

void	ft_calculate_target_pos(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*ptr_a;
	t_node	*ptr_b;

	if (head_stack_a == NULL)
		ptr_a = NULL;
	else
		ptr_a = *head_stack_a;
	if (head_stack_b == NULL)
		ptr_b = NULL;
	else
		ptr_b = *head_stack_b;
	while (ptr_b != NULL)
	{
		find_target_pos(ptr_a, ptr_b);
		ptr_b = ptr_b -> next;
	}
}
