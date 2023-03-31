/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/03/31 17:32:21 by imoumini         ###   ########.fr       */
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
	t_com **ast;
	t_final *final;
	(void)argc;
    (void)argv;
	
	// signal exit
	struct sigaction action_exit;
	sigset_t	sigmask;

	sigemptyset(&sigmask);
	action_exit.sa_flags = SA_SIGINFO;
	action_exit.sa_mask = sigmask;
	action_exit.sa_sigaction = ft_sigint;
	sigaction(SIGINT, &action_exit, NULL);
	// programme hors signaux
	mini_env = copy_env(env);
    src = NULL;
	info = NULL;
	root = NULL;
	ast = NULL;
		
	while (1)
    {
        input = readline("minishell> ");
		// fonction ici qui tema si espace entre les >
		if (single_enter(input) == 0 && check_space_append_heredoc(input) == 1)
		{
			root = parse_simple_command(input, &src, &info);
			//print_ast(root);
			ft_exit(&mini_env, &root, &src, &info);
			if(error_pars(root) == 1)
			{
				printf("c0\n");
				is_env_var(mini_env, root);
				printf("c0 bis\n");
				//afficher env apres que j'ai ajouté var env
        		printf("----------------------\n");
				print_env(mini_env);
				printf("----------------------\n");
				// afficher ast avant expand
				print_ast(root);
				printf("----------------------\n");
				
				if(is_there_quotes(root) == 0)
				{
					printf("c1\n");
					expand_env(mini_env,root);
					printf("-----------------------\n");
					printf("ast after expand is : \n");
					print_ast(root);
					printf("----------------------\n");
					printf("c2\n");
					ast = create_ast_command_redir(root);
					printf("c2 bis\n");
					printf("ast after decoupe is :\n");
					print_final_ast(ast);
					printf("c3\n");
					printf("final ast is :\n");
					printf("c4\n");
					final = create_final_ast(ast);
					// ok jai pas mis le NULL dans le double tableau ici
					printf("c4 bis\n");
					printf("final ast before final expand is :\n");
					// ok je crois que je mets jamais NULL dans le cas de USER sans env
					printf_final_ast(final);
					printf("c5\n");
					ft_free_before_final_ast(&ast);
					printf("c6\n");
					final_expand(final);
					printf("c7\n");
					printf_final_ast(final);
					printf("c8\n");
				}
				
				
			}
			ft_free(NULL, &root, &src,&info);
			ft_free_final_ast(&final);
		}
			else (free(input));
    }
}

// regler les invalid write, conditionnal jump et invalid free

   // faire ctrl c fait rien
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien
// demande à matthieu les guillemets
// faire historique
// rendre la structure avec tout bien fait pour que l'execution soit simple
// export sans option

// faire norminette

// si des guillemets
	// simple guillemets
	// double guillemets

// valgrind