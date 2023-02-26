/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/26 18:17:43 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
    t_env	*mini_env;
	char *input;
    t_source *src;
    t_info_tok *info;
    t_node *root;
	//struct sigaction action_exit;
	//sigset_t	sigmask;
    (void)argc;
    (void)argv;

	//sigemptyset(&sigmask);
	mini_env = copy_env(env);
	//print_env(mini_env);
    src = NULL;
	info = NULL;
	root = NULL;
	
	init_global_info_token(info);
	
	while (1)
    {
		printf("c1\n");
		info = init_global_info_token(info);
		printf("c2\n");
        input = readline("minishell> ");
		printf("c3\n");
		root = parse_simple_command(input, src, info);
		print_ast(root);
		printf("c4\n");
		ft_exit(&mini_env, &root, &src, &info);
		printf("c5\n");
		if (is_env_var(root))
			insert_input_env(mini_env, root);
		printf("c6\n");
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
		ft_free(NULL, &root, &src,&info);
    }

   
   // faire ctrl c fait rien
// faire exit -> exit
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien
// dire à matthieu si c bon 
// demander comment il a géré la grammaire, genre ça c faux, ça c vrai
// demande à matthieu les guillemets
// faire historique
// rendre la structure avec tout bien fait pour que l'execution soit simple
// faire valgrind
// faire function qui free tous les alloc
// export sans option

// question mathieu
	// comment t'as fait ça on a pas le droit de faire
	// comment on fait historique
	// c'est quoi les histoires de guillemets
	// comment on reconnait leak readline comparé aux autres
}