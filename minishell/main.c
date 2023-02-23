/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/23 15:23:13 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
    t_env	*mini_env;
	char *input;
    t_source src;
    t_info_tok info;
    t_node *root;
    (void)argc;
    (void)argv;
	mini_env = copy_env(env);
	//print_env(mini_env);
    
	
	init_global_info_token(&info);
	while (1)
    {
        // ajout export aui lieu dejouter bob=ranger
		// n'a pas expand
		// quand je lance une deuxième commande ya un segfault
        input = readline("minishell> ");
		root = parse_simple_command(input, &src, &info);
		if (is_env_var(root))
			insert_input_env(mini_env, root);
		 // afficher env apres que j'ai ajouté var env
        printf("----------------------\n");
		print_env(mini_env);
		printf("----------------------\n");
		// afficher ast avant expand
		print_ast(root);
		printf("----------------------\n");
		// afficher ast apres expand
		expand_env(mini_env,root);
		print_ast(root);
        //free_node_tree(root);
    }

   
    // make
    // regler pb
    // faire test du dessus
}