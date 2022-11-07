NAME = so_long
CC = gcc -Wall -Werror -Wextra
SRC = main.c

OBJ_SO_LONG = *.o

libx = -L minilibx -lmlx_Linux
libxflags = -lmlx -lXext -lX11 -lmlx_Linux

all: $(NAME)

$(NAME) : $(OBJ_SO_LONG)
		$(MAKE) --no-print-directory -C libft
		$(MAKE) --no-print-directory -C minilibx
		$(CC) $(SRC) libft/libft.a $(libx) $(libxflags) -o $(NAME) -g

$(OBJ_SO_LONG) : $(SRC)
			$(CC) -c $(SRC)

clean :
	rm -f $(OBJ_SO_LONG)

fclean : clean
	rm -f $(NAME)

re : fclean all
