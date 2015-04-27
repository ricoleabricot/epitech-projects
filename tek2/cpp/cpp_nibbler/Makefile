## 
## @Author: gicque_p
## @Date:   2015-02-07 00:21:10
## @Last Modified by:   gicque_p
## @Last Modified time: 2015-02-07 00:43:30
##

CXX			=	clang++
CXXFLAGS	+=	-W -Wall -Wextra -I./header/ -I./lib/ -g -fPIC
LDFLAGS		+=	-ldl -L ./lib/
RM			=	rm -rf

NAME		=	nibbler
CURS_NAME	=	lib_nibbler_ncurses.so
SFML_NAME	=	lib_nibbler_sfml.so
OGL_NAME	=	lib_nibbler_opengl.so
TEST_NAME	=	unit

include			source.mk

OBJ		=		$(SRC:.cpp=.o)
CURS_OBJ=		$(CURS_SRC:.cpp=.o)
SFML_OBJ=		$(SFML_SRC:.cpp=.o)
OGL_OBJ	=		$(OGL_SRC:.cpp=.o)
TEST_OBJ=		$(TEST_SRC:.cpp=.o)

all:			$(NAME) $(CURS_NAME) $(SFML_NAME) $(OGL_NAME) $(TEST_NAME)

$(NAME):		$(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

$(CURS_NAME):	$(CURS_OBJ)
	$(CXX) -shared -o $(CURS_NAME) $(CURS_OBJ) $(LDFLAGS) -lncurses

$(SFML_NAME):	$(SFML_OBJ)
	$(CXX) -shared -o $(SFML_NAME) $(SFML_OBJ) $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(OGL_NAME):	$(OGL_OBJ)
	$(CXX) -shared -o $(OGL_NAME) $(OGL_OBJ) $(LDFLAGS) -lSDL -lGL -lGLU

$(TEST_NAME): 	$(TEST_OBJ)
	$(CXX) -o $(TEST_NAME) $(TEST_OBJ)

clean:
	$(RM) $(OBJ) $(CURS_OBJ) $(SFML_OBJ) $(OGL_OBJ) $(TEST_OBJ)

fclean:		clean
	$(RM) $(NAME) $(CURS_NAME) $(SFML_NAME) $(OGL_NAME) $(TEST_NAME)

re:			fclean all

.PHONY:		all clean fclean re
