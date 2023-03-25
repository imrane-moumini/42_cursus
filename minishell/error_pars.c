/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:50:27 by imrane            #+#    #+#             */
/*   Updated: 2023/03/25 18:14:48 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int nbr_in_export(t_node *head)
{
	t_node *ptr;
	if (!head)
		return (2);
	ptr = head -> first_child;
	if (ptr)
	{
		if (ft_stcmp(ptr -> txt, "export") && (ptr -> next_sibling != NULL))
		{
			if (is_nbr(ptr -> next_sibling -> txt[0]) == 1)
			{
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
	if (quote_closed(head) == 0)
	{
		return (0);
	}
    return (1);
}

int check_space_append_heredoc(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' || str[i] == '>')
		{
			if (str[i +1])
			{
				if (str[i + 1] == ' ' || str[i+1] == '\t')
				{
					i++;
					while (str[i] == ' ' || str[i] == '\t')
						i++;
					if (str[i] == '>' || str[i] == '<')
					{
						ft_printf("parse error near '%c'\n", str[i]);
						return (0);
					}
				}
			}
		}
		i++;
	}
	return (1);
}