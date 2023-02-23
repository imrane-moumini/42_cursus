/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:31 by imrane            #+#    #+#             */
/*   Updated: 2023/02/23 19:26:24 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_free(t_env *mini_env, t_node *root, char *input)
{
	t_env *ptr_env;
	t_node *ptr_node;

	
	free(input);
	// free node
	
	//free env
	free(root);
	
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