/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:16:29 by imrane            #+#    #+#             */
/*   Updated: 2023/03/31 19:29:57 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


int ft_pipe_first_check(t_node *ptr)
{
	if (!ptr)
		return (1);
	if (ptr -> prev_sibling == NULL)
	{
		ft_printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	if (ptr -> next_sibling == NULL)
	{
		ft_printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
	if (ptr -> next_sibling)
	{
		if (ft_stcmp(ptr -> next_sibling -> txt, "|") == 1)
		{
			ft_printf("syntax error near unexpected token `|'\n");
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
			if (ft_pipe_first_check(ptr) == 0)
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

int how_much_pipe(t_node *root)
{
	t_node *ptr;
	int count;

	printf("nbr of pipe 1\n");
	count = 0;
	printf("nbr of pipe 2\n");
	if (!root)
		return (0);
	printf("nbr of pipe 3\n");
	ptr = root -> first_child;
	printf("nbr of pipe 4\n");
	while (ptr)
	{
		printf("nbr of pipe 5\n");
		if (ft_stcmp(ptr -> txt, "|") == 1)
		{
			printf("nbr of pipe 6\n");
			count++;
		}
		ptr = ptr -> next_sibling;
		printf("nbr of pipe 7\n");
	}
	printf("nbr of pipe 8\n");
	return (count);
}