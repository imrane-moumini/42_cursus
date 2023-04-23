/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/04/23 15:24:18 by imoumini         ###   ########.fr       */
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
	//char	*prompt_name;
	(void)argc;
    (void)argv;
	
	// signal exit
	struct sigaction action_exit;
	sigset_t	sigmask;

	g_exit_status = 0;
	sigemptyset(&sigmask);
	action_exit.sa_flags = SA_SIGINFO;
	action_exit.sa_mask = sigmask;
	action_exit.sa_sigaction = ft_sigint;
	sigaction(SIGINT, &action_exit, NULL);
	
	// signal control slash
	signal(SIGQUIT, SIG_IGN);
	// programme hors signaux
	mini_env = copy_env(env);
	final = NULL;
    src = NULL;
	info = NULL;
	root = NULL;
	ast = NULL;
	final_env = NULL;
	while (1)
	{
		//prompt_name = get_prompt_name(mini_env);
		input = readline("minishell>");
		//free(prompt_name);
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
				//ft_free(NULL, NULL, NULL, &info);
				supp_quotes(root);
				ast = create_ast_command_redir(root);
				final = create_final_ast(ast);
				ft_free_before_final_ast(&ast);
				final_expand(final);
				final_env = transform_env_in_double_tab(mini_env);
				free_env(&mini_env);
				ft_free(NULL, &root, &src, &info);
				executor(final, final_env);
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
imoumini@e1r10p21:~/42_cursus/minishell$ echo "$USER"
imoumini
imoumini@e1r10p21:~/42_cursus/minishell$ echo '$USER'
$USER
imoumini@e1r10p21:~/42_cursus/minishell$ echo '"$USER"'
"$USER"
imoumini@e1r10p21:~/42_cursus/minishell$ echo "'"$USER"'"
'imoumini'
imoumini@e1r10p21:~/42_cursus/minishell$ echo "''$USER''"
''imoumini''
imoumini@e1r10p21:~/42_cursus/minishell$ echo "ok"$USER"dac"
okimouminidac
imoumini@e1r10p21:~/42_cursus/minishell$ echo "ok"'$USER'"dac"
ok$USERdac
imoumini@e1r10p21:~/42_cursus/minishell$ echo "ok"''$USER"''dac"
okimoumini''dac
imoumini@e1r10p21:~/42_cursus/minishell$ ""'$USER'""
$USER: command not found
imoumini@e1r10p21:~/42_cursus/minishell$ echo ""'$USER'""
$USER
imoumini@e1r10p21:~/42_cursus/minishell$ echo ""'$USER'""



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





==79096== 4,277 bytes in 69 blocks are still reachable in loss record 69 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x10B631: ft_strcpy (manip_env.c:25)
==79096==    by 0x10CAA2: copy_original_to_mini (manip_env7.c:41)
==79096==    by 0x10B9C8: copy_env (manip_env2.c:60)
==79096==    by 0x1098B9: main (main.c:85)

==79096== 3,379 bytes in 69 blocks are still reachable in loss record 57 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x10C79E: create_var_value (manip_env6.c:30)
==79096==    by 0x10CA53: create_var_name_and_value (manip_env7.c:32)
==79096==    by 0x10B9DC: copy_env (manip_env2.c:62)
==79096==    by 0x1098B9: main (main.c:85)

==79096== 2,144 bytes in 67 blocks are still reachable in loss record 55 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x10B774: new_node_env (manip_env.c:63)
==79096==    by 0x10B81F: add_node_env (manip_env.c:89)
==79096==    by 0x10B999: copy_env (manip_env2.c:55)
==79096==    by 0x1098B9: main (main.c:85)

==79096== 1,024 bytes in 1 blocks are still reachable in loss record 51 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x114B07: ft_calloc (in /mnt/nfs/homes/imoumini/minishell_imrane/minishell)
==79096==    by 0x10A301: init_buf_size (manipulate_token3.c:47)
==79096==    by 0x109D19: tokenize (manipulate_token.c:54)
==79096==    by 0x10AA55: parse_simple_command (parser.c:74)
==79096==    by 0x1096EA: main (main.c:65)

==79096== 967 bytes in 69 blocks are still reachable in loss record 42 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x10B88C: create_var_name (manip_env2.c:26)
==79096==    by 0x10CA47: create_var_name_and_value (manip_env7.c:31)
==79096==    by 0x10B9DC: copy_env (manip_env2.c:62)
==79096==    by 0x1098B9: main (main.c:85)


==79096== 96 bytes in 2 blocks are still reachable in loss record 33 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x10A882: new_node (parser.c:19)
==79096==    by 0x10AB19: if_tok_exist (parser.c:99)
==79096==    by 0x10AA1B: parse_simple_command (parser.c:70)
==79096==    by 0x1096EA: main (main.c:65)

==94331== 32 bytes in 1 blocks are still reachable in loss record 21 of 86
==94331==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==94331==    by 0x10B774: new_node_env (manip_env.c:63)
==94331==    by 0x10B81F: add_node_env (manip_env.c:89)
==94331==    by 0x109731: main (main.c:68)
==94331== 
==94331== 32 bytes in 1 blocks are still reachable in loss record 22 of 86
==94331==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==94331==    by 0x10B948: copy_env (manip_env2.c:47)
==94331==    by 0x1098B9: main (main.c:85)

==79096== 48 bytes in 1 blocks are still reachable in loss record 28 of 83
==79096==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==79096==    by 0x10A882: new_node (parser.c:19)
==79096==    by 0x10A9B4: parse_simple_command (parser.c:61)
==79096==    by 0x1096EA: main (main.c:65)

==94331== 2 bytes in 1 blocks are still reachable in loss record 1 of 86
==94331==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==94331==    by 0x114C7C: ft_itoa (in /mnt/nfs/homes/imoumini/minishell_imrane/minishell)
==94331==    by 0x109754: main (main.c:70)
==94331== 
==94331== 2 bytes in 1 blocks are still reachable in loss record 2 of 86
==94331==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==94331==    by 0x10B631: ft_strcpy (manip_env.c:25)
==94331==    by 0x10978B: main (main.c:71)

==94331== 32 bytes in 1 blocks are still reachable in loss record 20 of 86
==94331==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==94331==    by 0x109AE9: init_src (init_src_token.c:19)
==94331==    by 0x10A996: parse_simple_command (parser.c:59)
==94331==    by 0x1096EA: main (main.c:65)

*/