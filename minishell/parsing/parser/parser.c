/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:57 by imrane            #+#    #+#             */
/*   Updated: 2023/02/25 15:35:48 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node *new_node(void)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	return node;
}

void	init_node(t_node *node, t_token *tok)
{
	if (tok)
		node -> txt = tok -> text;
	node -> children = 0;
	node -> first_child = NULL;
	node -> next_sibling = NULL;
	node -> prev_sibling = NULL;
}

void add_node(t_node *root, t_node *node)
{
	t_node *ptr;
	t_node *prev;
	printf("c1 node before if => %s\n", node -> txt);
	if (root -> first_child == NULL)
		root -> first_child = node;
	else
	{
		printf("c2 node in else = %s\n", node -> txt);
		ptr = root -> first_child;
		while (ptr != NULL)
		{
			prev = ptr;
			ptr = ptr -> next_sibling;
		}
		prev -> next_sibling = node;
		node -> prev_sibling = prev;
	}
}
t_node *parse_simple_command(char *input, t_source *src, t_info_tok *info)
{
	t_node *root;
	t_token *tok;
	t_node *node;
	
	if (!input)
		return (NULL);
	init_src(src, input);
	init_global_info_token(info);
	root = new_node();
	if (!root)
		return (NULL);
	init_node(root,NULL);
	if (src -> end_input != 1)
		tok = tokenize(src, info);
	free_info_buf(info);
	while (src -> exit != 1)
	{	
		node = new_node();
		if (!node)
			return (NULL);
		if (tok)
		{
			init_node(node, tok);
			add_node(root, node);
			free_tok(&tok);
		}
		free_info_buf(info);
		init_global_info_token(info);
		tok = tokenize(src, info);
		free_info_buf(info);
	}
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