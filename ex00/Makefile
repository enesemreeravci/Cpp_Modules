NAME = megaphone
CC = c++ 
CLAGS = -Wall -Wextra -Werror

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=-o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f *.o

fclean:
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re