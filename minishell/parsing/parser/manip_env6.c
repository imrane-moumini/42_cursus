/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:38:49 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/22 18:50:27 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_var_value(t_env *node)
{
	int	i;
	int	equal;

	if (!node)
		return ;
	if (node -> txt == NULL)
		return ;
	equal = 0;
	while (node -> txt[equal] != '=')
		equal++;
	i = equal;
	while (node -> txt[i] != '\0')
		i++;
	node->var_value = malloc((sizeof(char) * (i - equal)) + 1);
	if (node -> var_value == NULL)
		return ;
	i = 0;
	equal++;
	while (node -> txt[equal] != '\0')
	{
		node -> var_value[i] = node -> txt[equal];
		i++;
		equal++;
	}
	node ->var_value[i] = '\0';
}

int	nbr_of_dollar_suite(t_node *ptr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ptr->txt[i] != '\0')
	{
		while (ptr->txt[i] == '$')
		{
			count++;
			i++;
			if (ptr->txt[i] != '$')
				return (count);
		}
		i++;
	}
	return (count);
}

void	expand_env(t_env *head, t_node *root)
{
	t_node	*ptr;
	t_node	*expand;

	if (!head || !root)
		return ;
	attribute_atfer_here_doc(attribue_here_doc(root));
	ptr = root -> first_child;
	while (ptr)
	{
		printf("c1\n");
		expand = do_i_have_to_expand(ptr);
		printf("c2\n");
		while (more_than_one_dollars_suite(ptr) == 1)
		{
			printf("c3\n");
			expand_job_multiple_dollar(ptr, nbr_of_dollar_suite(ptr));
			printf("c4\n");
			if (ptr)
				printf("ptr in expand more than %s\n", ptr -> txt);
		}
		printf("c5\n");
		
		expand = do_i_have_to_expand(ptr);
		printf("c6\n");
		if (expand)
		{
			printf("c7\n");
			expand_job(head, ptr);
			if (ptr)
				printf("ptr after expand job %s\n", ptr -> txt);
			printf("c8\n");
		}
		ptr = ptr -> next;
		printf("c9\n");
	}
}

int	is_it_heredoc(t_node *node)
{
	t_node	*ptr;

	if (!node)
		return (0);
	ptr = node;
	if (ptr -> txt[0] == '<')
	{
		if (ptr -> next)
		{
			if (ptr -> next -> txt[0] == '<')
				return (1);
		}
	}
	return (0);
}
