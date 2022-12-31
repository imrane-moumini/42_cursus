NAME = push_swap
CC = gcc -Wall -Werror -Wextra
SRC = main.c \
	stack/handle_stack.c \
	stack/handle_stack2.c \
	stack/handle_stack3.c \
	stack/handle_stack4.c \
	stack/handle_stack5.c \
	stack/check_error.c \
	stack/check_error2.c \
	stack/handle_main.c \
	algorithm/algorithm.c \
	algorithm/algorithm2.c \
	algorithm/algorithm3.c \
	algorithm/algorithm4.c \
	algorithm/algorithm5.c \
	algorithm/algorithm6.c \
	algorithm/algorithm7.c \
	algorithm/algorithm8.c 
	
OBJ_PUSH_SWAP = $(SRC:%.c=%.o) 


all: $(NAME)

$(NAME) : $(OBJ_PUSH_SWAP)
		$(MAKE) --no-print-directory -C libft
		$(CC) $(OBJ_PUSH_SWAP) libft/libft.a -o $(NAME) -g

%.o : %.c
		$(CC) -c $< -o $@

clean :
	rm -f $(OBJ_PUSH_SWAP)
	make fclean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean all