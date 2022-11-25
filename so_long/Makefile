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

OBJ_SO_LONG = $(SRC:%.c=%.o) 

libx = -L minilibx/ 
libxflags = -lmlx -lXext -lX11 -lz -lm

all: $(NAME)

$(NAME) : $(OBJ_SO_LONG)
		$(MAKE) --no-print-directory -C libft
		$(MAKE) --no-print-directory all -C minilibx
		$(CC) $(OBJ_SO_LONG) minilibx/libmlx_Linux.a libft/libft.a $(libx) $(libxflags) -o $(NAME) -g

%.o : %.c
			$(CC) $(libx) $(libxflags) -c $< -o $@

clean :
	rm -f $(OBJ_SO_LONG)
	make fclean -C libft
	make clean -C minilibx

fclean : clean
	rm -f $(NAME)

re : fclean all
