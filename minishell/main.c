/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/04/10 22:19:56 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

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
	/*
	// signal exit
	struct sigaction action_exit;
	sigset_t	sigmask;

	sigemptyset(&sigmask);
	action_exit.sa_flags = SA_SIGINFO;
	action_exit.sa_mask = sigmask;
	action_exit.sa_sigaction = ft_sigint;
	sigaction(SIGINT, &action_exit, NULL);
	*/
	// programme hors signaux
	mini_env = copy_env(env);
    src = NULL;
	info = NULL;
	root = NULL;
	ast = NULL;
		
	while (1)
    {
        input = readline("minishell> ");
		if (!input)
			return (printf("exit\n"), 0); // free (c ici que je gere control D )
		// fonction ici qui tema si espace entre les >
		if (does_quotes_closed(input) == 1 && single_enter(input) == 0 && check_space_append_heredoc(input) == 1)
		{
			//exit(1);
			root = parse_simple_command(input, &src, &info);
			print_ast(root);
			ft_exit(&mini_env, &root, &src, &info);
			printf("c0\n");
			expand_env(mini_env,root);
			is_unset(&mini_env, root);
			printf("c0 bis\n");
			if(error_pars(root) == 1 && is_env_var(mini_env, root) == 1)
			{
				printf("c1\n");
				//afficher env apres que j'ai ajouté var env
        		printf("----------------------\n");
				print_env(mini_env);
				printf("----------------------\n");
				// afficher ast avant expand
				print_ast(root);
				printf("----------------------\n");
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
				//executor(final, env);
				
			}
			ft_free(NULL, &root, &src,&info);
			printf("c9\n");
			ft_free_final_ast(&final);
			printf("c10\n");
		}
			else (free(input));
    }
}

// regler les invalid write, conditionnal jump et invalid free

   // faire ctrl c fait rien
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien

// guillemet
// heredoc pas expand
// faire historique

// quand ya des simple guillemets a linterieur de gdouble uillemet je les laisses
// les double guillemet je les enleve tout le temps sauf qund c entourer de simple guillemets
// les premiere guillemets qu'on voit prime sur ce que quon doit faire
// je peut pas anlyser mot par mot vu que je deco


// une fois que jqurqis expand
// va falloir que jenleve les double guillemets ou simple en focntion
// je vais devoir recouper pasque ptete yqurq des pipes et redir
// checker differemment si les quotes sont closes, chequer direct au niveau de linput




// supp les double guillemets
// verfier que le doubles sont pas entourer de simple
//

//$?
//env