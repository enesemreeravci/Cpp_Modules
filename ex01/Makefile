NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PhoneBook.cpp Contact.cpp
RM = rm -rf

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $<"

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Build complete"

all : $(NAME)

clean :
	$(RM) $(OBJS)
	@echo "Object files removed"

fclean : clean
	$(RM) $(NAME)
	@echo "Binary removed"

re : fclean all

.PHONY : all clean fclean re
