/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:06:18 by imrane            #+#    #+#             */
/*   Updated: 2023/02/24 22:13:28 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_free(t_env *mini_env, t_node *root, t_source *src, t_info_tok *tok) 
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
		// ajouter les sécuritées et mettre NULL
		free(ptr_env -> txt);
		free(ptr_env -> var_name);
		free(ptr_env -> var_value);
		free(ptr_env);
		ptr_env = NULL;
	}
	// free source_s;
	
	// free (token);
		// faut hje fasse le leien entre tok et node pour savoir quand free
		// voir init node et add node
	// free info_tok
	if ()
}
void free_src(t_source *src)
{
	if (src)
	{
		if(src -> buffer)
			free (src -> buffer);
		free(src);
		src = NULL;
	}
}
void free_tok(t_token *tok)
{
	if (tok)
	{
		free(tok -> text);
		free(tok);
		tok = NULL;
	}
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