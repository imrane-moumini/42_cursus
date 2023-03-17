/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:17:30 by imrane            #+#    #+#             */
/*   Updated: 2023/03/17 22:18:42 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redir *create_redir_node(t_redir *redir, t_node *node)
{
	t_redir *ptr;
	t_redir *follow;
	
	ptr = malloc(sizeof(t_redir));
	if (!node)
		return (NULL);
	// si existe pas t la tete sinon t kle suivant
	if (node)
		printf("node is => %s\n",node -> txt);
	if (node -> next_sibling)
		printf("node next is => %s\n",node -> next_sibling -> txt);
	if (!redir)
	{
        ptr -> heredoc = 0;
        ptr -> in_file = 0;
        ptr -> out_file = 0;
        ptr -> append = 0;
        ptr -> file = 0;
		ptr -> txt = malloc(sizeof(char)* ((ft_strlen(node -> txt) + 1)));
		ft_strlcpy(ptr -> txt, node -> txt, ft_strlen(node -> txt) + 1);
		ptr -> next_sibling = NULL;
		redir = ptr;
		printf("c2.10.5.1\n");
        if (ft_stcmp(node -> txt, "<") == 1 && node -> next_sibling && ft_stcmp(node -> next_sibling -> txt, "<") == 1)  
        {
			printf("c2.10.5.2\n");
            ptr -> heredoc = 1;
            free(ptr -> txt);
            ptr -> txt = malloc(sizeof(char) * 3);
            ft_strlcpy(ptr -> txt, "<<", 3);
            return (redir);
        }
        if (ft_stcmp(node -> txt, "<") == 1 && node -> next_sibling && ft_stcmp(node -> next_sibling -> txt, "<") != 1)  
        {
			printf("c2.10.5.3\n");
            ptr -> in_file = 1;
            return (redir);
        }
        if (ft_stcmp(node -> txt, ">") == 1 && node -> next_sibling && ft_stcmp(node -> next_sibling -> txt, ">") == 1)  
        {
			printf("c2.10.5.4\n");
            ptr -> append = 1;
            free(ptr -> txt);
            ptr -> txt = malloc(sizeof(char) * 3);
            ft_strlcpy(ptr -> txt, ">>", 3);
            return (redir);
        }
        if (ft_stcmp(node -> txt, ">") == 1 && node -> next_sibling && ft_stcmp(node -> next_sibling -> txt, ">") != 1)  
        {
			printf("c2.10.5.5\n");
            ptr -> out_file= 1;
            return (redir);
        }
        ptr -> file = 1;
	}
	else
	{
		printf("c2.10.5.6\n");
		follow = redir;
		while (follow -> next_sibling != NULL)
			follow = follow -> next_sibling;
		follow -> next_sibling = ptr;
		ptr -> txt = malloc(sizeof(char)* ((ft_strlen(node -> txt) + 1)));
        ptr -> file = 1;
		ft_strlcpy(ptr -> txt, node -> txt, ft_strlen(node -> txt) + 1);
		ptr -> next_sibling = NULL;
		printf("c2.10.5.7\n");
		//printf("after add ok, redir is :\n");
		//print_redir(redir);
	}
	printf("c2.10.5.8\n");
	return (redir);
}

// le ok ne semble pas ce rajouter ou redir affiche pas tout jusquq bout