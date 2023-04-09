/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:50:27 by imrane            #+#    #+#             */
/*   Updated: 2023/04/09 19:41:41 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



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

int does_quotes_closed(char *str)
{
	int i;
	int single;
	int double_q;
	printf("closed 1\n");
	single = 0;
	double_q = 0;
	i = 0;
	
	while (str[i])
	{
		printf("closed 2\n");
		if (str[i] == '"')
		{
			printf("close double\n");
			double_q++;
		}
		if (str[i] == '\'')
		{
			printf("close single\n");
			single++;
		}
		if (str[i] == '|')
		{
			printf("closed 3\n");
			if (single % 2 != 0 || double_q % 2 != 0)
			{
				printf("closed 4\n");
				ft_printf("error : quotes are not closed\n");
				return (0);
			}
		}
		i++;
	}
	printf("closed 5\n");
	if (single % 2 != 0 || double_q % 2 != 0)
	{
		printf("closed 6\n");
		ft_printf("error : quotes are not closed\n");
		return (0);
	}
	else
	{
		printf("closed 7\n");
		return (1);
	}		
}