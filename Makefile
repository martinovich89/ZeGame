NAME			=	zeGame

HEADERS			=	Galaxy.hpp System.hpp Planet.hpp Comet.hpp Utils.hpp Realm.hpp Player.hpp Menu.hpp

INC				=	-I./

SRC_PATH		=	./

SRCS			=	main.cpp Galaxy.cpp System.cpp Planet.cpp Comet.cpp Utils.cpp Player.cpp Menu.cpp

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	g++

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++11 -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS) $(INC) -o $(NAME) -lncurses

%.o : %.cpp $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $< -lncurses

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re