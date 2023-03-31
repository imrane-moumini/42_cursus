/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:31 by imrane            #+#    #+#             */
/*   Updated: 2023/03/31 19:21:51 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void ft_exit(t_env **mini_env,t_node **root, t_source **src, t_info_tok **info)
{
    t_node *ptr;

    if (!root)
        return ;
    ptr = *root;
    printf("ft exit 1\n");
    if (ptr -> first_child == NULL)
        return ;
    printf("ft exit 2\n");
    ptr = ptr -> first_child;
    printf("first child is =>%s\n", ptr -> txt);
    if (ptr -> next_sibling != NULL)
        printf("next sibling exist\n");
    if ((ft_stcmp(ptr -> txt, "exit") == 1) && (ptr -> next_sibling == NULL))
	{
        printf("ft exit 3\n");
		ft_free(mini_env, root, src, info);
		exit (1);
	}
}
