NAME = minishell
CC = gcc -Wall -Werror -Wextra 
SRC = main.c \
	parsing/lexer.c \
	parsing/parser.c
	
OBJ = $(SRC:%.c=%.o) 


all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lreadline -g3

%.o : %.c
		$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re