NAME = Easy
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Compiled $(NAME) successfully"

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re