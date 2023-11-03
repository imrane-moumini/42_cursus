NAME		= RPN
CC			= c++
FLAGS		= -Wall -Werror -Wextra -std=c++98 -g -MMD
SRC			= main.cpp \
				RPN.cpp
OBJ			= $(SRC:.cpp=.o)
DEP			= $(SRC:.cpp=.d)

RM			= rm -f

all		: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

.cpp.o	:
	$(CC) $(FLAGS) -o $@ -c $<

.PHONY	: all clean fclean re

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean
	make all

-include $(DEP)
