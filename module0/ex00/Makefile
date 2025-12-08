NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

# Colors
GREEN = \033[0;32m
RED   = \033[0;31m
BLUE  = \033[0;34m
RESET = \033[0m

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	$(CXX) -c $< -o $@
	@echo "$(BLUE)Compiled:$<$(RESET)"

$(NAME) : $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build complete -> $(NAME)$(RESET)"

all : $(NAME)

clean :
	$(RM) *.o
	@echo "$(RED)Object files removed$(RESET)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED)Binary removed$(RESET)"

re : fclean all

.PHONY : all clean fclean re
