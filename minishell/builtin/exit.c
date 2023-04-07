/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:31 by imrane            #+#    #+#             */
/*   Updated: 2023/04/07 19:17:20 by imoumini         ###   ########.fr       */
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
    if ((ft_stcmp_exit(ptr -> txt, "exit") == 1) && (ptr -> next_sibling == NULL))
	{
		ft_free(mini_env, root, src, info);
		exit (1);
	}
}
int		ft_stcmp_exit(char *str1, char *str2)
{
	int i;
	i = 0;
	if (!str1)
		return (0);
	if (!str2)
		return (0);
	if (str1[0] == '\0')
		return (0);
	if (ft_strlen(str1) != ft_strlen(str2))
        return (0);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}