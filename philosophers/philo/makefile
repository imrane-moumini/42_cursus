NAME = philo
CC = gcc -Wall -Werror -Wextra -pthread -g3 #-fsanitize=thread
SRC = main.c \
	utile_fonction.c \
	dinner.c \
	fill_philo.c \
	mutex.c \
	stop_dinner.c \
	threads.c \
	error.c \
	error2.c \
	dinner2.c
	
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