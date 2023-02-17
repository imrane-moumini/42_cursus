/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/17 20:15:01 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	t_info_tok info;
	
	init_global_info_token(&info);
	while (1)
    {
        char *input;
        t_source src;
        t_info_tok info;
        t_node *root;
        t_node *ptr;
		
        input = readline("minishell> ");
		root = parse_simple_command(input, &src, &info);
        ptr = root -> first_child;
        if (ptr)
        {
            while (ptr != NULL)
            {
                printf("%s ", ptr -> txt);
                ptr = ptr -> next_sibling;
            }
        }
        free(input);
        //free_node_tree(root);
    }
}