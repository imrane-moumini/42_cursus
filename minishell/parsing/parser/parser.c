/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:23:57 by imrane            #+#    #+#             */
/*   Updated: 2023/04/23 17:05:55 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*new_node(t_token *tok)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (tok)
		node -> txt = ft_strcpy((tok -> text));
	node -> children = 0;
	node -> first_child = NULL;
	node -> next = NULL;
	node -> prev_sibling = NULL;
	return (node);
}

t_node	*add_node_to_ast(t_node *root, t_node *node)
{
	t_node	*ptr;
	t_node	*prev;

	if (root -> first_child == NULL)
		root -> first_child = node;
	else
	{
		ptr = root -> first_child;
		while (ptr != NULL)
		{
			prev = ptr;
			ptr = ptr -> next;
		}
		prev -> next = node;
		node -> prev_sibling = prev;
	}
	return (root);
}

t_node	*parse_simple_command(char *input, t_source **src, t_info_tok **info)
{
	t_node		*root;
	t_token		*tok;
	t_source	*src_ft;
	t_info_tok	*info_ft;

	if (!input)
		return (NULL);
	src = init_src(src, input);
	info = init_global_info_token(info);
	root = new_node(NULL);
	src_ft = *src;
	info_ft = *info;
	printf("info sur info_ft %s\n", info_ft->tok_buf);
	printf("suivi malloc : %p\n", info_ft);
	if (!root)
		return (NULL);
	if (src_ft -> end_input != 1)
		tok = tokenize(src_ft, info_ft);
	printf("c-1.2.0\n");
	while (src_ft -> exit != 1 || tok != NULL)
	{
		printf("c-1.2.1\n");
		if (!(if_tok_exist(tok, root, info)))
			return (NULL);
		info = init_global_info_token(info);
		info_ft = *(info);
		printf("info sur info_ft %s\n", info_ft->tok_buf);
		printf("suivi malloc bis : %p\n", info_ft);
		tok = tokenize(src_ft, info_ft);
	}
	return (free_tok(&tok), root);
}

void	print_ast(t_node *node)
{
	t_node	*ptr;

	if (!node)
		return ;
	ptr = node -> first_child;
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr -> txt);
		ptr = ptr -> next;
	}
}

t_node	*if_tok_exist(t_token *tok, t_node *root, t_info_tok **info)
{
	t_node	*node;

	printf("c-1.2.2\n");
	if (tok)
	{
		printf("c-1.2.2.0\n");
		node = new_node(tok);
		printf("c-1.2.2.1\n");
		if (!node)
		{
			printf("c-1.2.3\n");
			return (NULL);
		}
		printf("c-1.2.2.2\n");
		add_node_to_ast(root, node);
		free_tok(&tok);
	}
	printf("c-1.2\n");
	free_info(info);
	info = NULL;
	return (root);
}
