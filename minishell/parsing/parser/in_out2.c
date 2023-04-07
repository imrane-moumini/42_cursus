/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:13:47 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/07 15:26:24 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int in_file_second_check_alone(t_node *ptr)
{
    if ((ptr -> next_sibling) == NULL) // si ya un seul < et ya rien après le <
	{
		ft_printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
    return (1);
}

int in_file_second_check_something_after(t_node *ptr)
{
    if (ft_stcmp(ptr -> txt, "<") == 1)
	{
		if (ptr -> next_sibling) // si ya un truc après le <
		{
			if (ft_stcmp(ptr -> next_sibling -> txt, ">") == 1)
				{
					ft_printf("syntax error near unexpected token '%s'\n", ptr -> next_sibling -> txt);
					return (0);
				}
		}
	}
	if (ft_stcmp(ptr -> txt, ">") == 1)
	{
		if (ptr -> next_sibling) // si ya un truc après le <
		{
			if (ft_stcmp(ptr -> next_sibling -> txt, "<") == 1)
				{
					ft_printf("syntax error near unexpected token '%s'\n", ptr -> next_sibling -> txt);
					return (0);
				}
		}
	}
    return (1);
}

int ft_in_file_first_check_wrong_arrow(t_node *ptr)
{
	if (ft_stcmp(ptr -> txt, "<") == 1 && ft_stcmp(ptr -> next_sibling -> txt, ">") == 1)
	{
		ft_printf("syntax error near unexpected token '>'\n");
		return (0);
	}
	if (ft_stcmp(ptr -> txt, ">") == 1 && ft_stcmp(ptr -> next_sibling -> txt, "<") == 1)
	{
		ft_printf("syntax error near unexpected token '<'\n");
		return (0);
	}
	return (1);
}