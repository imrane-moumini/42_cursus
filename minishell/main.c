/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/04/24 20:32:31 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_exe.h"

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
	t_env *last_node;
	char *exit_status;
	char	*prompt_name;
	(void)argc;
    (void)argv;
	
	ft_signal(1);
	mini_env = copy_env(env);
	final = NULL;
    src = NULL;
	info = NULL;
	root = NULL;
	ast = NULL;
	final_env = NULL;
	while (1)
	{
		prompt_name = get_prompt_name(mini_env);
		input = readline(prompt_name);
		free(prompt_name);
		if (!input)
			ft_exit_d(&mini_env);
		add_history(input);
		if (single_enter(input) == 0 && does_quotes_closed(input) == 1 && check_space_append_heredoc(input) == 1)
		{
			root = parse_simple_command(input, &src, &info);
			if (check_if_exist(mini_env, "?") == 1)
				supp_env(&mini_env, "?");
			add_node_env(mini_env);
			last_node = last_env_node(mini_env);
			exit_status = ft_itoa(g_exit_status);
			fill_last_node(last_node, ft_strcpy("?"), exit_status, ft_strjoin(ft_strcpy("?="), exit_status));
			expand_env(mini_env,root);
			is_unset(&mini_env, root);
			if(error_pars(root) == 1 && is_env_var(mini_env, root) == 1)
			{
				supp_quotes(root);
				ast = create_ast_command_redir(root);
				final = create_final_ast(ast);
				ft_free_before_final_ast(&ast);
				final_expand(final);
				final_env = transform_env_in_double_tab(mini_env);
				free_env(&mini_env);
				ft_free(NULL, &root, &src, &info);
				executor(final, final_env);
				printf("g_exit_status = %d\n", g_exit_status);
				mini_env = copy_env(final_env);
				free_final_env(&final_env);
				ft_free_final_ast(&final);
			}
			else
				ft_free(NULL, &root, &src,&info);
		}
			else (free(input));
	}
}


// faire ctrl c fait rien
// faire ctr D -> quitte le shell
// faire ctrl \ -> ne fait rien
// regler les invalid write, conditionnal jump
//faire norminette

//signaux 
	// qund jsuis dans la boucle while
	// qund jsuis dans un fork (genre dans mon cat)
	// qund jsuis dans le heredoc
// etre a laffut de tous les exit status

/*




LEAKS : echo mathieu 



BASH (qd on fait control D)
imoumini@e2r9p11:~/minishell_imrane$ ^C
imoumini@e2r9p11:~/minishell_imrane$ 
exit
imoumini@e2r9p11:~/minishell_imrane$ echo $?
130
MINISHELL
minishell>^C
minishell>
exit
➜  minishell_imrane git:(master) ✗ echo $?
0




COMMAND :
gdb
file ./minishell
run
=> tape les commandes que tu veux, si ca segfault voir commande si dessous 
bt



*/
/*

imoumini@e2r10p12:/mnt/nfs/homes/imoumini/42_cursus/minishell$ export a="s -a"
==599236== Invalid read of size 1
==599236==    at 0x10F6BD: str_without_quotes (supp_quotes.c:39)
==599236==    by 0x10F5A3: supp_quotes (supp_quotes.c:25)
==599236==    by 0x109684: main (main.c:63)
==599236==  Address 0x4b6ba29 is 0 bytes after a block of size 9 alloc'd
==599236==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==599236==    by 0x10B496: ft_strcpy (manip_env.c:25)
==599236==    by 0x10A6FA: new_node (parser.c:21)
==599236==    by 0x10A976: if_tok_exist (parser.c:99)
==599236==    by 0x10A878: parse_simple_command (parser.c:70)
==599236==    by 0x109582: main (main.c:52)

*/
