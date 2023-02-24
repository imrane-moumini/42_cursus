/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:06:18 by imrane            #+#    #+#             */
/*   Updated: 2023/02/24 23:39:48 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
void free_ast(t_node **root);
{
	t_node *ptr_root;
	t_node *ptr_node;
	t_node *save;
	if (!root)
		return ;
	ptr_root = *root;
	if (ptr_root)
	{
		ptr_node = ptr_root -> first_child;
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
		root = NULL;
		
	}
	free(root);
	root = NULL;
}
void free_env(t_env **mini_env)
{
	t_env *ptr_env;
	t_env *save_env;

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
}
void ft_free(t_env *mini_env, t_node *root, t_source *src, t_info_tok *tok) 
{
	free_ast(root)
	free_env(mini_env);
	free_src(src);
	free_tok(tok);
	free_info(info);
}
void free_info(t_info_tok **info)
{
	t_info_tok *ptr;
	if (info)
	{
		ptr = *info;
		if (ptr)
		{
			if (ptr -> tok_buf)
				free(ptr -> tok_buf);
			free(ptr)
		}
		info = NULL;
	}
}
void free_src(t_source **src)
{
	t_source *ptr;
	if (src)
	{
		ptr = *src;
		if (ptr)
		{
			if(ptr -> buffer)
				free (ptr -> buffer);
			free(ptr);
		}
		src = NULL;
	}
}
void free_tok(t_token **tok)
{
	t_token *ptr;
	
	if (tok)
	{
		ptr = *tok;
		if (ptr)
		{
			free(ptr-> text);
			free(ptr);
		}
		tok = NULL;
	}
}
void free_info_buf(t_info_tok **info)
{
	t_info_tok *ptr;
	
	if (info)
	{
		ptr = *info
		if (ptr)
		{
			if (ptr -> tok_buf)
			{
				free(ptr -> tok_buf);
				ptr -> tok_buf = NULL;
			}
		}
		info = NULL
	}
}