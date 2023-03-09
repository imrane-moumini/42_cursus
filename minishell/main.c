/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/03/09 20:48:33 by imrane           ###   ########.fr       */
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
		// voir pk des fois ya une new line et parfois non
        input = readline("minishell> ");
		root = parse_simple_command(input, &src, &info);
		print_ast(root);
		ft_exit(&mini_env, &root, &src, &info);
		// mettre le ft_error ici et le ft exit après
		if(error_pars(root) == 1)
		{
			is_env_var(mini_env, root);
			 // afficher env apres que j'ai ajouté var env
        	printf("----------------------\n");
			print_env(mini_env);
			printf("----------------------\n");
			// afficher ast avant expand
			print_ast(root);
			printf("----------------------\n");
			// afficher ast apres expand
			
			
			// vérifier qu'il ya pas << genre if not tu peux expand
			expand_env(mini_env,root);
			print_ast(root);
		}
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

// mettre tout ça dans des fonctions
// gerer > et >> comme delimiteur
// faire quand erreur tu remonte en haut pour mettre un nouveau prompt 
// mettre toutes les erreurs dans un ft erreur
// sans passer par le reste
// faire norminette

// juste avant de expand
	// gerer ce que g le droit de faire ou non avec les <<
	// gerer les guillemets
}