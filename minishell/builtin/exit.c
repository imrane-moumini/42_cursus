/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:31 by imrane            #+#    #+#             */
/*   Updated: 2023/02/24 21:10:05 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_free(t_env *mini_env, t_node *root, char *input)
{
	t_env *ptr_env;
	t_node *ptr_node;
	t_node *save;
	t_env *save_env;
	free(input);
	// free node
	if (root)
	{
		ptr_node = root -> first_child;
		if (ptr_node)
		{
			if (ptr_node -> next_sibling != NULL)
			{
				while (ptr_node -> next_sibling != NULL)
				{
					save = ptr_node -> next_sibling;
					free(ptr_node -> txt);
					free(ptr_node);
					ptr_node = save;
				}
				free(ptr_node -> txt);
				free(ptr_node);
			}
			else
			{
				free(ptr_node -> txt);
				free(ptr_node);
			}
		}
		ptr_node = NULL;
		
	}
	free(root);
	root = NULL;
	//free env
	ptr_env = mini_env;
	if (ptr_env)
	{
		while (ptr_env -> next != NULL)
		{
			save = ptr_env -> next;
			free(ptr_env -> txt);
			free(ptr_env -> var_name);
			free(ptr_env -> var_value);
			free(ptr_env);
			ptr_env = save;
		}
		free(ptr_env -> txt);
		free(ptr_env -> var_name);
		free(ptr_env -> var_value);
		free(ptr_env);
		ptr_env = NULL;
	}
	// free source_s;
	if (src)
	{
		free (src -> buffer);
		free(src);
		src = NULL;
	}
	// free (token);
	// free info_tok
	
}

void free_info_buf(t_info_tok *info)
{
	if (info)
	{
		if (info -> tok_buf)
		{
			free(info -> tok_buf);
			info -> tok_buf = NULL;
		}
	}
}
void ft_exit(t_env *mini_env,t_node *root, char *input)
{
    t_node *ptr;

    if (!root)
        return ;
    if(root -> first_child = NULL)
        return ;
    ptr = root -> first_child;
    if ((ft_stcmp(ptr -> text, exit) == 1) && (ptr -> next_sibling == NULL))
	{
		ft_free(mini_env, root, input);
		exit (1);
	}
}