/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:50:27 by imrane            #+#    #+#             */
/*   Updated: 2023/03/10 19:46:23 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int nbr_in_export(t_node *head)
{
	t_node *ptr;
	printf ("c1\n");
	if (!head)
		return (2);
	printf ("c2\n");
	ptr = head -> first_child;
	printf ("c4\n");
	if (ptr)
	{
		printf ("c5\n");
		if (ft_stcmp(ptr -> txt, "export") && (ptr -> next_sibling != NULL))
		{
			printf ("c6\n");
			if (is_nbr(ptr -> next_sibling -> txt[0]) == 1)
			{
				printf ("c7\n");
				ft_printf("export : '%s' is not a valid identifier\n",ptr -> next_sibling -> txt);
				return (0);
			}
		}
	}
	return (1);
}
int error_pars(t_node *head)
{
    if (!head)
    {
		return(2);
	}
    if (ft_in_file(head) == 0)
    {
		return(0);
	}
	if (ft_pipe_check(head) == 0)
    {
		return(0);
	}
	if (nbr_in_export(head) == 0)
	{
		return (0);
	}
    return (1);
}