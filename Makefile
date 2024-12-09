NAME = Game
CXX = c++  # Use at least C++11 for modern OpenGL support
CPPFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lGL -lglfw -ldl  # Link OpenGL and GLFW libraries

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
