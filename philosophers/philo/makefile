NAME = philo
CC = gcc -Wall -Werror -Wextra -pthread #-fsanitize=thread
SRC = main.c \
	utile_fonction.c
	
OBJ = $(SRC:%.c=%.o) 


all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) -o $(NAME) -g

%.o : %.c
		$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re