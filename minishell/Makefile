NAME = minishell
CC = gcc -Wall -Werror -Wextra 
SRC = main.c \
	parsing/lexer.c \
	parsing/parser.c \
	parsing/init_src_token.c
	
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