/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:45:39 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/07 19:45:09 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void fill_last_node(t_env *last_node, char *var_env_name, char *var_env_value, char *env_input)
{
    last_node -> var_name = var_env_name;
	last_node -> var_value = var_env_value;
	last_node -> txt = env_input;
}

char *return_after(char *str, int j, int save)
{
    int i;
    int length;
    char *after;

    length = 0;
    i = 0;
    while (str[j])
	{
		j++;
		length++;
	}
	after = malloc(sizeof(char) * (length + 1));
	while(str[save] != '\0')
	{
		after[i] = str[save];
		i++;
		save++;
	}
	after[i] = '\0';
    return (after);
}

void final_txt(char *save_after_dollar, char *new_str, t_node *ptr, char *save_var)
{
	if (save_after_dollar)
		new_str = ft_strjoin(new_str, save_after_dollar);
	free(ptr -> txt);
	free(save_var);
	ptr -> txt = new_str;
}

void init_save_after_dollar(char *save_after_dollar)
{
	save_after_dollar = malloc(sizeof(char) * 2);
	save_after_dollar[0] = 'a';
	save_after_dollar[1] = '\0';
}

char *return_after_multiple_dollar(char *str, int i, int save)
{
	int count;
	char *after;
	
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