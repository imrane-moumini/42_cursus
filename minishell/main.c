/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/04/13 20:30:03 by imoumini         ###   ########.fr       */
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
	char **final_env;
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
		add_history(input);
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
				supp_quotes(root);
				printf("ast after supp auotes is is : \n");
				print_ast(root);
				printf("----------------------\n");
				ast = create_ast_command_redir(root);
				printf("c3\n");
				printf("ast after decoupe is :\n");
				print_final_ast(ast);
				printf("c4\n");
				printf("final ast is :\n");
				printf("c5\n");
				final = create_final_ast(ast);
				printf("c6 bis\n");
				printf("final ast before final expand is :\n");
				printf_final_ast(final);
				printf("c7\n");
				ft_free_before_final_ast(&ast);
				printf("c8\n");
				final_expand(final);
				printf("c9\n");
				printf_final_ast(final);
				printf("c10\n");
				// create new env double tableau
				final_env = transform_env_in_double_tab(mini_env);
				printf("--------------------------------\n");
				printf("final env is \n");
				print_double_tab_env(final_env);
				printf("---------------------------------\n");
				printf("c11\n");
				//executor(final, env);
				
			}
			ft_free(NULL, &root, &src,&info);
			printf("c12\n");
			ft_free_final_ast(&final);
			printf("c13\n");
		}
			else (free(input));
    }
}





// merge
//$?
// gerer -a qund c entre guillemets pour bien decouper
// quqnd ya un espace dans les guillemets avec un moins ca fait une boucle infi alors que sans lespace ca decoupe bien =>ls"-z -u"$bob
// voir pk
// free final env
// regler le pb de lenv qui ecrit NULL quand ya env -i
// faire builtin
// faire ctrl c fait rien
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien
// regler les invalid write, conditionnal jump
//faire norminette