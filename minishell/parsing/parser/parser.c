/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:57 by imrane            #+#    #+#             */
/*   Updated: 2023/02/26 19:37:14 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*new_node(t_token *tok)
{
	t_node *node;
	node = malloc(sizeof(t_node));
	if (tok)
		node -> txt = tok -> text;
	node -> children = 0;
	node -> first_child = NULL;
	node -> next_sibling = NULL;
	node -> prev_sibling = NULL;
	return (node);
}

void add_node_to_ast(t_node *root, t_node *node)
{
	t_node *ptr;
	t_node *prev;
	//printf("c3.9.1\n");
	if (root -> first_child == NULL)
	{
		root -> first_child = node;
		//printf("c3.9.2\n");
	}
	else
	{
		//printf("c3.9.3\n");
		ptr = root -> first_child;
		//printf("c3.9.4\n");
		while (ptr != NULL)
		{
			//printf("c3.9.5\n");
			prev = ptr;
			//printf("c3.9.6\n");
			ptr = ptr -> next_sibling;
			//printf("c3.9.7\n");
		}
		prev -> next_sibling = node;
		//printf("c3.9.8\n");
		node -> prev_sibling = prev;
		//printf("c3.9.9\n");
	}
}
t_node *parse_simple_command(char *input, t_source *src, t_info_tok *info)
{
	t_node *root;
	t_token *tok;
	t_node *node;
	//printf ("c3.1\n");
	if (!input)
		return (NULL);
	src = init_src(src, input);
	//printf("buff is in parse =>%s\n", src -> buffer);
	//printf("=>curpos in parse %li\n", src -> curpos);
	//printf ("c3.2\n");
	info = init_global_info_token(info);
	//printf ("c3.3\n");
	//printf ("c3.4\n");
	root = new_node(NULL);
	if (!root)
		return (NULL);
	if (src -> end_input != 1)
	{
		//printf ("c3.5\n");
		tok = tokenize(src, info);
	}
	//printf ("c3.6\n");
	free_info_buf(info);
	//printf ("c3.7\n");
	while (src -> exit != 1)
	{	
		if (tok)
		{
			node = new_node(tok);
			if (!node)
				return (NULL);
			printf ("c3.8\n");
			//printf ("c3.9\n");
			if (root)
				printf ("c3.90\n");
			if (node)
				printf ("c3.91\n");
			add_node_to_ast(root, node);
			printf ("c3.10\n");
			free_tok(&tok);
			printf ("c3.11\n");
		}
		//printf ("c3.12\n");
		free_info_buf(info);
		//printf ("c3.13\n");
		init_global_info_token(info);
		//printf ("c3.14\n");
		tok = tokenize(src, info);
		//printf ("c3.15\n");
		free_info_buf(info);
		//printf ("c3.16\n");
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