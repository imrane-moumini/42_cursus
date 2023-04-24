NAME = minishell

CC = gcc -Wall -Werror -Wextra -g

SRC = main.c \
	parsing/lexer/manipulate_input.c \
	parsing/lexer/init_src_token.c \
	parsing/lexer/manipulate_token.c \
	parsing/lexer/manipulate_token2.c \
	parsing/lexer/manipulate_token3.c \
	parsing/lexer/manipulate_token4.c \
	parsing/lexer/manipulate_token5.c \
	parsing/parser/parser.c \
	parsing/parser/ft_pipe.c \
	parsing/parser/quotes.c \
	parsing/parser/quotes_2.c \
	parsing/parser/in_out.c \
	parsing/parser/in_out2.c \
	parsing/parser/in_out3.c \
	parsing/parser/manip_env.c \
	parsing/parser/manip_env2.c \
	parsing/parser/manip_env3.c \
	parsing/parser/manip_env4.c \
	parsing/parser/manip_env5.c \
	parsing/parser/manip_env6.c \
	parsing/parser/manip_env7.c \
	parsing/parser/manip_env8.c \
	parsing/parser/manip_env9.c \
	parsing/parser/manip_env10.c \
	parsing/parser/manip_env11.c \
	parsing/parser/decoupe_ast_no_quotes.c \
	parsing/parser/decoupe_ast_no_quotes2.c \
	parsing/parser/final_ast.c \
	parsing/parser/manip_node_commannd.c \
	parsing/parser/manip_node_redir.c \
	parsing/parser/manip_node_redir2.c \
	parsing/parser/manip_node_redir3.c \
	parsing/parser/exception.c \
	parsing/parser/final_check_expand.c \
	parsing/parser/final_check_expand2.c \
	parsing/parser/final_check_expand3.c \
	parsing/parser/supp_quotes.c \
	signals/signal.c \
	builtin/export_with_option.c \
	builtin/export_with_option2.c \
	builtin/ft_unset.c \
	builtin/ft_unset2.c \
	ft_free/ft_free.c \
	error_pars.c \
	error_pars2.c \
	exe/redir.c \
	exe/redir_utils.c \
	exe/heredoc.c \
	exe/heredoc_expand.c \
	exe/heredoc_utils.c \
	exe/heredoc_utils_2.c \
	exe/pipex.c \
	exe/pipex_init.c \
	exe/pipex_lonely.c \
	exe/pipex_errors.c \
	exe/exec.c \
	exe/childs.c \
	exe/cmd_access.c \
	exe/free_exe.c \
	exe/print_status.c \
	exe/builtin.c \
	exe/builtin_cd.c \
	exe/builtin_cd_utils.c \
	exe/builtin_echo.c \
	exe/builtin_env.c \
	exe/builtin_exit.c \
	exe/builtin_export.c \
	exe/builtin_pwd.c \
	exe/utils.c \
	exe/utils_2.c \
	exe/utils_3.c \
	prompt_name.c \
	print_errors.c

OBJ = $(SRC:%.c=%.o) 

all: $(NAME)

$(NAME) : $(OBJ)
		$(MAKE) --no-print-directory -C libft
		$(CC) $(OBJ) libft/libft.a -o $(NAME) -lreadline -g3

%.o : %.c
		$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)
	make fclean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re