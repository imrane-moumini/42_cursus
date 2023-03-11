/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/03/11 20:24:24 by imrane           ###   ########.fr       */
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
	
	
	while (1)
    {
        input = readline("minishell> ");
		root = parse_simple_command(input, &src, &info);
		print_ast(root);
		ft_exit(&mini_env, &root, &src, &info);
		if(error_pars(root) == 1)
		{
			
			
			is_env_var(mini_env, root);
			//afficher env apres que j'ai ajouté var env
        	printf("----------------------\n");
			print_env(mini_env);
			printf("----------------------\n");
			// afficher ast avant expand
			print_ast(root);
			printf("----------------------\n");
			if(is_there_quotes(root) == 0)
			{
				expand_env(mini_env,root);
				// decouper et retourner les data struct
			}
			/*
			if(is_there_quotes(root) == 1)
			{
				if(is_there_both(root) == 0)
				{
					if(is_there_single_quotes(root) == 1)
					{
						
					}
					if(is_there_double_quotes(root) == 1)
					{
						
					}
				}
				else
				{
					// isoler les single quote faire ski a a faire
					// isoler les double quotes faire ski ya a faire
				}
			*/
			}
			print_ast(root);
		}
		ft_free(NULL, &root, &src,&info);
    }

   
   // faire ctrl c fait rien
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien
// demande à matthieu les guillemets
// faire historique
// rendre la structure avec tout bien fait pour que l'execution soit simple
// export sans option

// faire norminette

// juste avant de expand
// gerer les meta caractères en plus de $
	// gerer les guillemets
		// gerer les meta caracterere à ne pas gerer

// demander à mathiru
	//meta caractere et guillemets
	// rl_on new line des signaux et bautre fnctions et dire moi ça a rien fait
	// ya pas a free comme c une nouvelle commande genre ça  a déjà été free ava,t

// le truc des guillemets je vais le gérer dans le decoupage final
// en fait a la fin de la boucle je rajoute la fonction decoupage ce que je renvoie
// je fais une focntion qui regarde si ya des guillemets ou pas
	// si ya je regarde si simple ou double
	// deccoupage différente en fonction si ya ou non guillemets
	// mais du coup j'expand que après avoir fait ça, je fais plus ma logique d'expand directr

// si ya pas de guillemets
// k'envoi tout si ya pas de > ou de |
	// si ya >, j'envoie ce qui est avant
		// je sauvegarde le > + ce qui se trouve imédiatement après 
		// si ya des trics après le treuc immédia bahb c'est que ya un pipe
		// je découpe ce qui ya après le pipe et je sauvegarde le pipe quelque part

// si ya des guillemets
	// simple guillemets
	// double guillemets	
}