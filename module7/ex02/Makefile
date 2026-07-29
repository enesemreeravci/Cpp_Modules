NAME = Array
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp
OBJS = $(SRCS:.CPP=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Compiled $(NAME) successfully"

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all fclean clean re