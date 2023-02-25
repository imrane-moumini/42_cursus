/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:31 by imrane            #+#    #+#             */
/*   Updated: 2023/02/25 15:24:15 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void ft_exit(t_env **mini_env,t_node **root, t_source **src, t_info_tok **info)
{
    t_node *ptr;

    if (!root)
        return ;
    if(root -> first_child = NULL)
        return ;
    ptr = root -> first_child;
    if ((ft_stcmp(ptr -> text, "exit") == 1) && (ptr -> next_sibling == NULL))
	{
		ft_free(mini_env, root, src, info);
		exit (1);
	}
}