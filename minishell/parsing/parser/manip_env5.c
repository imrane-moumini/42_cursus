/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:38:31 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/07 19:15:53 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void expand_job_multiple_dollar(t_node *ptr, int nbr)
{
	int i;
	char *str_nbr;
	char *save_before_dollar;
	char *save_after_dollar;
	char *new_str;
	
	i = 0;
	while (ptr -> txt[i] != '\0')
	{
		if (ptr ->txt[i] == '$')
		{
			save_before_dollar = before_dollar(ptr -> txt);
			str_nbr = add_nbr(nbr);
			save_after_dollar = after_multiple_dollar(ptr -> txt, nbr);
			new_str = ft_strjoin(save_before_dollar, str_nbr);
			free (str_nbr);
			new_str = ft_strjoin(new_str, save_after_dollar);
			free(save_after_dollar);
			free(ptr -> txt);
			ptr -> txt = new_str;
			return ;
		}
		i++;
	}
}

void expand_job(t_env *head, t_node *ptr)
{
	int i;
	char *save_var;
	char *save_before_dollar;
	char *save_after_dollar;
	char *new_str;

	i = 0;
	save_after_dollar = malloc(sizeof(char) * 2);
	save_after_dollar[0] = 'a';
	save_after_dollar[1] = '\0';
	while (ptr -> txt[i] != '\0')
	{
		if (ptr ->txt[i] == '$')
		{
			i++;
			free(save_after_dollar);
			save_before_dollar = before_dollar(ptr -> txt);
			save_var = catch_var(ptr->txt + i);
			save_after_dollar = after_dollar(ptr -> txt);
			new_str = ft_strjoin(save_before_dollar, return_matching_value(head, save_var));
			if (save_after_dollar)
				new_str = ft_strjoin(new_str, save_after_dollar);
			free(ptr -> txt);
			free(save_var);
			ptr -> txt = new_str;
			i--;
		}
		i++;
	}
}
int more_than_one_dollars_suite(t_node *ptr)
{
	int i;
	i = 0;

	while(ptr -> txt[i])
	{
		if(ptr->txt[i] == '$')
		{
			if (ptr->txt[i + 1])
			{
				if (ptr->txt[i+1] == '$')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

char *after_multiple_dollar(char *str, int nbr)
{
	int i;
	int save;
	int count;
	char *after;

	count = 0;
	i =0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '$')
		{
			if (nbr % 2 == 0)
			{
				while (nbr)
				{
					i++;
					nbr--;
				}
				save = i;
			}
			else
			{
				while (nbr > 1)
				{
					i++;
					nbr--;
				}
				save = i;
			}
			break;
		}
		i++;
	}

	while (str[i] != '\0')
		i++;
	count = i -save;
	after = malloc(sizeof(char) * (count + 1));
	i =0;
	while (str[save] != '\0')
	{
		after[i] = str[save]; 
		i++;
		save++;
	}
	after[i] = '\0';
	return (after);
}

char *add_nbr(int nbr)
{
	char *str_nbr;
	int count;

	count = 2;
	while (nbr > 1)
	{
		if (count == 2)
		{
			str_nbr = malloc(sizeof(char) * 8);
			str_nbr[0] = '3';
			str_nbr[1] = '1';
			str_nbr[2] = '0';
			str_nbr[3] = '5';
			str_nbr[4] = '1';
			str_nbr[5] = '6';
			str_nbr[6] = '0';
			str_nbr[7] = '\0';
			count--;
			if (nbr == 2)
				return (str_nbr);
		}
		if (count == 0)
			str_nbr = ft_strjoin(str_nbr, str_nbr);
		if (count >= 0)
			count--;
		if (nbr > 0)
			nbr = nbr/2;
	}
	return (str_nbr);
}