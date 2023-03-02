/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/03/02 17:58:19 by imrane           ###   ########.fr       */
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
	
	
	while (1)
    {
        input = readline("minishell> ");
		root = parse_simple_command(input, &src, &info);
		print_ast(root);
		ft_exit(&mini_env, &root, &src, &info);
		is_env_var(mini_env, root);
		 // afficher env apres que j'ai ajouté var env
        printf("----------------------\n");
		print_env(mini_env);
		printf("----------------------\n");
		// afficher ast avant expand
		print_ast(root);
		printf("----------------------\n");
		// afficher ast apres expand
		// c dans expand que je dois mettre la boucle
		expand_env(mini_env,root);
		print_ast(root);
		ft_free(NULL, &root, &src,&info);
    }

   
   // faire ctrl c fait rien
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien
// dire à matthieu si c bon 
// demander comment il a géré la grammaire, genre ça c faux, ça c vrai
// demande à matthieu les guillemets
// faire historique
// rendre la structure avec tout bien fait pour que l'execution soit simple
// export sans option


// gérer decoupage token quadn pas espace ex $a$a ou a|a
// quand dollars et avant pas un espace tu ferme mais tu curpos pas plus pour débuter le prichain

// Mathieu
	// comment on lance un nouveau prompt ?
}