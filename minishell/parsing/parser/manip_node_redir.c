/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:17:30 by imrane            #+#    #+#             */
/*   Updated: 2023/03/13 22:39:24 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redir *create_redir_node(t_redir redir, t_node *node)
{
	t_redir *ptr;
	ptr = malloc(sizeof(t_com));
	if (!node)
		return (NULL);
	// si existe pas t la tete sinon t kle suivant
	if (!redir)
	{
        ptr -> heredoc = 0;
        ptr -> in_file = 0;
        ptr -> out_file = 0;
        ptr -> append = 0;
        ptr -> file = 0;
		ptr -> txt = malloc(sizeof(char)* ((ft_strlen(node -> txt) + 1)));
		ft_strcpy(ptr -> txt, node -> txt, ft_strlen(node -> txt) + 1);
		ptr -> next_sibling = NULL;
        if (ft_stcmp(ptr -> txt, "<") == 1 && ft_stcmp(ptr -> next_sibling -> txt, "<") == 1)  
        {
            ptr -> heredoc = 1;
            return (redir);
        }
        if (ft_stcmp(ptr -> txt, "<") == 1 && ft_stcmp(ptr -> next_sibling -> txt, "<") != 1)  
        {
            ptr -> in_file = 1;
            return (redir);
        }
        if (ft_stcmp(ptr -> txt, ">") == 1 && ft_stcmp(ptr -> next_sibling -> txt, ">") == 1)  
        {
            ptr -> append = 1;
            return (redir);
        }
        if (ft_stcmp(ptr -> txt, ">") == 1 && ft_stcmp(ptr -> next_sibling -> txt, ">") != 1)  
        {
            ptr -> out_file= 1;
            return (redir);
        }
        ptr -> file = 1;
            
	}
	else
	{
		redir -> next_sibling = ptr;
		ptr -> txt = malloc(sizeof(char)* ((ft_strlen(node -> txt) + 1)));
		ft_strcpy(ptr -> txt, node -> txt, ft_strlen(node -> txt) + 1);
		ptr -> next_sibling = NULL;
	}
	return (redir);
}