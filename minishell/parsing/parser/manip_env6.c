/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:38:49 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/07 18:37:41 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    create_var_value(t_env *node)
{
	int i;
	int equal;

	if (!node)
		return ;
	if (node -> txt == NULL)
		return ;
	equal = 0;
	while(node -> txt[equal] != '=')
		equal++;
	i = equal;
	while (node -> txt[i] != '\0')
		i++;
	node -> var_value = malloc((sizeof(char) *(i - equal)) + 1);
	if (node -> var_value == NULL)
		return ;
	i = 0;
	equal++;
	while(node -> txt[equal] != '\0')
	{
		node -> var_value[i] = node -> txt[equal];
		i++;
		equal++;
	}
	node ->var_value[i] = '\0';
}

int nbr_of_dollar_suite(t_node *ptr)
{
	int i;
	int count;
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


void    expand_env(t_env *head, t_node *root)

{
	t_node *ptr;
	t_node *expand;
	printf("c0.1\n");
	if (!head || !root)
		return ;
	ptr = root -> first_child;
	printf("c0.2\n");
	//if (is_here_doc(root) == 1)
	//	return ;
	while (ptr)
	{
		printf("c0.3\n");
		expand = do_i_have_to_expand(ptr);
		printf("c0.4\n");
		//if (/*txt is juste un dollar sans rien apres on expand pas*/)
		while (more_than_one_dollars_suite(ptr) == 1)
		{
			printf("c0.5\n");
			expand_job_multiple_dollar(ptr, nbr_of_dollar_suite(ptr));
			printf("c0.6\n");
		}
		printf("c0.7\n");
		expand = do_i_have_to_expand(ptr);
		printf("c0.8\n");
		if (expand)
		{
			printf("%s\n",ptr -> txt);
			printf("c0.9\n");
			expand_job(head, ptr);
			printf("c0.10\n");
			printf("%s\n",ptr -> txt);
		}
		ptr = ptr -> next_sibling;
		printf("c0.11\n");
	}
}