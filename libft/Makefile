NAME = libft.a

CC = gcc -Wall -Wextra -Werror

SRC = ft_isalpha.c \
    ft_memcpy.c  \
    ft_strlcat.c \
    ft_bzero.c   \
    ft_isascii.c \
    ft_strlcpy.c \
    ft_isalnum.c \
    ft_isdigit.c \
    ft_memmove.c \
    ft_strlen.c \
    ft_isalnum.c \
    ft_isprint.c \
    ft_memset.c   \
    ft_toupper.c \
    ft_tolower.c \
		ft_strchr.c\
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c

BONUS_SRC = ft_lstnew_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstsize_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstadd_back_bonus.c\
            ft_lstdelone_bonus.c \
            ft_lstclear_bonus.c \
            ft_lstiter_bonus.c \
            ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $^

%.o : %.c
	$(CC) -c $^

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
