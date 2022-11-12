NAME = so_long
CC = gcc -Wall -Werror -Wextra
SRC = main.c \
	map_gestion/map_gestion_one.c \
	map_gestion/map_gestion_three.c \
	map_gestion/map_gestion_two.c

OBJ_SO_LONG = *.o

libx = -L minilibx -lmlx_Linux
libxflags = -lmlx -lXext -lX11 -lmlx_Linux

all: $(NAME)

$(NAME) : $(OBJ_SO_LONG)
		$(MAKE) --no-print-directory -C libft
		$(MAKE) --no-print-directory -C minilibx
		$(CC) $(OBJ_SO_LONG) libft/libft.a $(libx) $(libxflags) -o $(NAME) -g

$(OBJ_SO_LONG) : $(SRC)
			$(CC) -c $(SRC)

clean :
	rm -f $(OBJ_SO_LONG)
	rm -f ./libft/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all
