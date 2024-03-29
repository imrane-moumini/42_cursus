/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:20:46 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 21:52:06 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_max(t_node **head_stack_a)
{
	int		max;
	t_node	*ptr;

	max = 0;
	if (head_stack_a == NULL)
		return (0);
	if (*head_stack_a == NULL)
		return (0);
	ptr = *head_stack_a;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (max < ptr -> index)
			max = ptr -> index;
		ptr = ptr -> next;
	}
	return (max);
}
