NAME = Array

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled $(NAME) successfully"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all