/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/20 22:40:14 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
	//t_info_tok info;
    t_env	*mini_env;
	
    (void)argc;
    (void)argv;
	mini_env = copy_env(env);
	//print_env(mini_env);
    
	/*
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
                printf("%s\n", ptr -> txt);
                ptr = ptr -> next_sibling;
            }
        }
        free(input);
        //free_node_tree(root);
    }*/

    // afficher env apres que j'ai ajouté var env
    // afficher input avant expand
    // afficher inout apres expand
    // make
    // regler pb
    // faire test du dessus
}