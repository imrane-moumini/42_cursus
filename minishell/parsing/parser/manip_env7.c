/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:45:12 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/07 16:25:48 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env *env_not_exist(void)
{
	t_env *mini_env;

	mini_env = malloc(sizeof(t_env));
	mini_env -> next = NULL;
	mini_env = add_node_env(mini_env);
	mini_env -> txt = ft_strcpy("nothing=nothing");
	mini_env -> var_name = ft_strcpy("nothing");
	mini_env -> var_value = ft_strcpy("nothing");
	return (mini_env);
}

void create_var_name_and_value(t_env *ptr)
{
	while(ptr != NULL)
	{
		create_var_name(ptr);
		create_var_value(ptr);
		ptr = ptr -> next;
	}
}

void copy_original_to_mini(char *original[], int i, t_env *ptr)
{
	while (original[i] && ptr != NULL)
	{
		ptr -> txt = ft_strcpy(original[i]);
		ptr = ptr -> next;
		i++;
	}
}