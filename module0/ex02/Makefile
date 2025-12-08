NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp tests.cpp

RM = rm -rf

OBJS = $(SRCS:.cpp=.o)
RED    := \033[1;31m
YELLOW := \033[1;33m
RESET  := \033[0m

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo -e "$(YELLOW)Compiled$(RESET)"

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(RED)Ready for usage $(RESET)"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "$(RED)Object files cleaned$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)Everything removed$(RESET)"

re : fclean all

.PHONY : all clean fclean re