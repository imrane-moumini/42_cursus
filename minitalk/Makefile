NAME_SERVER	=	server
NAME_CLIENT	=	client

FLAGS		=	-Wall -Wextra -Werror


SRC_SERVER	=	server.c
SRC_CLIENT	=	client.c 

OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)
OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)

%.o:			%.c
				$(CC) $(FLAGS) -c $<
				$(MAKE) -C libft

all:			$(NAME_CLIENT) $(NAME_SERVER)


$(NAME_SERVER):	$(OBJ_SERVER)
				$(CC) $(FLAGS) $(OBJ_SERVER) libft/libft.a -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
				$(CC) $(FLAGS) $(OBJ_CLIENT) libft/libft.a -o $(NAME_CLIENT)

clean:
				rm -rf $(OBJ_SERVER) $(OBJ_CLIENT) $(NAME_SERVER) $(NAME_CLIENT)
				$(MAKE) fclean -C libft

fclean:			clean
				rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re:				fclean all

.PHONY:			all clean fclean re