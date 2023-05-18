NAME = cub3d
CC = gcc -Wall -Werror -Wextra
SRC = main.c \
	game_gestion/handle_game.c
	

OBJ_CUB3D = $(SRC:%.c=%.o) 

libx = -L minilibx/ 
libxflags = -lmlx -lXext -lX11 -lz -lm

all: $(NAME)

$(NAME) : $(OBJ_CUB3D)
		$(MAKE) --no-print-directory -C libft
		$(MAKE) --no-print-directory all -C minilibx
		$(CC) $(OBJ_CUB3D) minilibx/libmlx_Linux.a libft/libft.a $(libx) $(libxflags) -o $(NAME) -g

%.o : %.c
			$(CC) $(libx) $(libxflags) -c $< -o $@

clean :
	rm -f $(OBJ_CUB3D)
	make fclean -C libft
	make clean -C minilibx

fclean : clean
	rm -f $(NAME)

re : fclean all