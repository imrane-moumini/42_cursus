/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:31 by imrane            #+#    #+#             */
/*   Updated: 2023/03/01 17:16:08 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void ft_exit(t_env **mini_env,t_node **root, t_source **src, t_info_tok **info)
{
    t_node *ptr;

    if (!root)
        return ;
    ptr = *root;
    if (ptr -> first_child == NULL)
        return ;
    ptr = ptr -> first_child;
    if ((ft_stcmp(ptr -> txt, "exit") == 1) && (ptr -> next_sibling == NULL))
	{
		ft_free(mini_env, root, src, info);
		exit (1);
	}
}

// meme si je mets null dans ft_free pour root g quand même 40 bloc
    // ou g ooublié de free ?
    // pk g pas plus de leaks alors que g pas free ast