NAME	=	battle_ship
CXX		=	g++
FLAGS	=	-std=c++11 -Wall -Wextra
SRCS	=	main.cpp players.cpp game.cpp interface.cpp
OBJ		=	$(SRCS:.cpp=.o)

all: $(NAME)

%.o:	%.cpp
	$(CXX) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(FLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
