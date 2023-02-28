/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:57 by imrane            #+#    #+#             */
/*   Updated: 2023/02/28 21:11:40 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*new_node(t_token *tok)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (tok)
		node -> txt = ft_strcpy((tok -> text));
	node -> children = 0;
	node -> first_child = NULL;
	node -> next_sibling = NULL;
	node -> prev_sibling = NULL;
	return (node);
}

t_node *add_node_to_ast(t_node *root, t_node *node)
{
	t_node *ptr;
	t_node *prev;

	if (root -> first_child == NULL)
		root -> first_child = node;
	else
	{
		ptr = root -> first_child;
		while (ptr != NULL)
		{
			prev = ptr;
			ptr = ptr -> next_sibling;
		}
		prev -> next_sibling = node;
		node -> prev_sibling = prev;
	}
	return (root);
}
t_node *parse_simple_command(char *input, t_source *src, t_info_tok *info)
{
	t_node *root;
	t_token *tok;
	t_node *node;
	if (!input)
		return (NULL);
	src = init_src(src, input);
	info = init_global_info_token(info);
	root = new_node(NULL);
	if (!root)
		return (NULL);
	if (src -> end_input != 1)
		tok = tokenize(src, info);
	free_info_buf(info);
	while (src -> exit != 1)
	{	
		if (tok)
		{
			node = new_node(tok);
			if (!node)
				return (NULL);
			root = add_node_to_ast(root, node);
			free_tok(&tok);
		}
		free_info_buf(info);
		init_global_info_token(info);
		tok = tokenize(src, info);
		free_info_buf(info);
	}
	free_tok(&tok);
	return (root);
}

void    print_ast(t_node *node)
{
	t_node *ptr;
	if (!node)
		return ; 
	ptr = node -> first_child;
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr -> txt);
		ptr = ptr -> next_sibling;
	}
}