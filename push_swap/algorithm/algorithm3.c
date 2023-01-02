/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:05 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/02 21:12:57 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_printf_stack(t_node **head_stack_a, t_node **head_stack_b)
{
	t_node	*ptr;

	if (head_stack_a == NULL)
		ptr = NULL;
	else
		ptr = *head_stack_a;
	ft_printf("stack a :\n");
	while (ptr != NULL)
	{
		ft_printf(" data : %i\n", ptr -> data);
		ptr = ptr -> next;
	}
	if (head_stack_b == NULL)
		ptr = NULL;
	else
		ptr = *head_stack_b;
	ft_printf("stack b :\n");
	while (ptr != NULL)
	{
		ft_printf(" data : %i\n", ptr -> data);
		ptr = ptr -> next;
	}
}

void	ft_tri_more_than_three(t_node **head_a, t_node **head_b, int nbr)
{
	send_element_to_b(head_a, head_b, nbr / 2);
	ft_tri_three(head_a);
	while (is_stack_empty(head_b) == 0)
	{
		ft_calculate_positions(head_a, head_b);
		ft_calculate_cost(head_a, head_b);
		ft_execute(head_a, head_b, ft_min_cost(head_b));
	}
	put_min_index_top(head_a);
}

int	nbr_element_in_stack(t_node *head)
{
	t_node	*ptr;
	int		counter;

	counter = 0;
	ptr = head;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr -> next;
	}
	return (counter);
}

int	is_index_smaller_than_mediane(t_node **head_stack_a, int mediane)
{
	t_node	*ptr;

	ptr = *head_stack_a;
	while (ptr != NULL)
	{
		if (ptr -> index < mediane)
			return (1);
		ptr = ptr -> next;
	}
	return (0);
}

void	send_element_to_b(t_node **head_a, t_node **head_b, int mediane)
{
	while (is_index_smaller_than_mediane(head_a, mediane) == 1 \
		&& nbr_element_in_stack(*head_a) > 3)
	{
		if ((*head_a)-> index < mediane)
		{
			pb(head_a, head_b);
		}
		else
		{
			ra(head_a, head_b);
		}
	}
	while (nbr_element_in_stack(*head_a) > 3)
	{
		pb(head_a, head_b);
	}
}
