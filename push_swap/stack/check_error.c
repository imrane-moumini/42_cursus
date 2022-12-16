/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:01:34 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/16 16:53:19 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_ony_number(char *str)
{
	// regarder ttes les erreurs possible
	// faire norminette
	// faire algo de trie
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}
int check_empty_stack(char *str)
{
	// vide = nul car
	// vide = aucun chiffre
	int i;
	int counter;

	i = 0;
	counter = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			counter++;
		i++;
	}
	if (counter == 0)
		return (1);
	return (0);
}
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