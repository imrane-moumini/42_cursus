/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:16:29 by imrane            #+#    #+#             */
/*   Updated: 2023/03/09 21:29:53 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


int ft_pipe_first_check(t_node *ptr)
{
	if (!ptr)
		return (1);
	if (ptr -> prev_sibling == NULL)
	{	
		return (0);
	}
	if (ptr -> next_sibling == NULL)
	{
		return (0);
	}
	if (ptr -> next_sibling)
	{
	
		if (ft_stcmp(ptr -> next_sibling -> txt, "|") == 1)
		{
			return (0);
		}
	}
	return (1);
}
int ft_pipe_check(t_node *head)
{
    t_node *ptr;
    
	ptr = head;
    if (!ptr)
		return(2);
	if (ptr -> first_child)
		ptr = ptr -> first_child;
	while (ptr != NULL)
	{
		if (ft_stcmp(ptr -> txt, "|") == 1)
		{
			if (ft_in_file_first_check(ptr) == 0)
				return (0);
			// avancer juste qua être un truc différent de  |
			while (ptr && (ft_stcmp(ptr -> txt, "|") == 1))
				ptr = ptr -> next_sibling;
		}
		if (ptr && ft_stcmp(ptr -> txt, "|") != 1)
			ptr = ptr -> next_sibling;	
	}
	return (1);
}