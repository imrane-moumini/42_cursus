/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:01:34 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/15 21:03:27 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int check_empty_stack()
// {
	
// }
int	check_doublon_list(t_node *head)
{
	t_node	*ptr;
	t_node	*save_head;
	t_node	*ptr_data;
	t_node	*save_adress_data;
	int		doublon_data;
	
	ptr = head;
	save_head = head;
	ptr_data = head;
	if (ptr == NULL)
		return (0);
	if (ptr -> next == NULL)
		return (0);
	doublon_data = ptr_data -> data;
	save_adress_data = ptr_data;
	while (ptr != NULL && ptr_data != NULL)
	{
		while (ptr != NULL)
		{
			if (doublon_data == ptr -> data && save_adress_data != ptr)
				return (1);
			ptr = ptr -> next;
		}
		ptr_data = ptr_data -> next;
		if (ptr_data != NULL)
		{
			doublon_data = ptr_data -> data;
			save_adress_data = ptr_data;
		}
		ptr = save_head;
	}
	return (0);
}