NAME = so_long
CC = gcc -Wall -Werror -Wextra
SRC = main.c \
	map_gestion/find_path.c \
	map_gestion/find_path2.c \
	map_gestion/create_and_fill_tab.c \
	map_gestion/checks.c \
	map_gestion/checks2.c \
	map_gestion/checks3.c \
	map_gestion/checks4.c \

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
