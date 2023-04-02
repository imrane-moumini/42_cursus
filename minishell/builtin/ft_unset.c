/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:06:55 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/02 17:17:51 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


/*int     is_unset(t_env **mini_env, t_node *root)
{
	t_node *ptr;
	int nbr;
	if (!root)
		return (1);
	nbr =  how_much_pipe(root);
	ptr = root -> first_child;
	if (ptr)
	{
		printf("c0.3\n");
		if (ft_stcmp(ptr -> txt, "unset") && (ptr -> next_sibling != NULL))
		{
			printf("c0.4\n");
			if (insert_input_env(&mini_env, ptr, nbr) == 0)
			{
				printf("c0.5\n");
				return (0);
			}
		}
		ptr = ptr -> next_sibling;
		printf("c0.6\n");
	}
	// faut que le retour de ske g pas le droit je le recois la comme ca je vais pas dans
	// la suite
	return (1);
}*/

int check_if_exist(t_env *head, char *str)
{
	t_env *ptr;
	
	if (!head)
		return (2);
	ptr = head;

	while (ptr != NULL)
	{
		if (ft_stcmp(str, ptr -> var_name) == 1)
			return (1);
		ptr = ptr -> next;
	}
	return (0);
	
}

void supp_env(t_env **head, char *str)
{
	t_env *ptr;
	t_env *before;
	
	if (!head)
		return ;
		
	ptr = *head;
	if (!ptr)
		return ;
	// si premier
	if (ft_stcmp(str, ptr -> var_name) == 1)
	{
		free(ptr -> var_name);
		free(ptr -> var_value);
		free(ptr -> txt);
		*head = ptr -> next;
		free(ptr);
		return ;
	}
	// si au milieu
	before = ptr;
	while (ptr -> next != NULL)
	{
		if (ft_stcmp(str, ptr -> var_name) == 1)
		{
			
			free(ptr -> var_name);
			free(ptr -> var_value);
			free(ptr -> txt);
			before -> next =  ptr -> next;
			free (ptr);
			return ;
		}
		before = ptr;
		ptr = ptr -> next;
	}
	// si dernier

	if (ft_stcmp(str, ptr -> var_name) == 1)
	{
		free(ptr -> var_name);
		free(ptr -> var_value);
		free(ptr -> txt);
		before -> next = NULL;
		free(ptr);
		return ;
	}
}