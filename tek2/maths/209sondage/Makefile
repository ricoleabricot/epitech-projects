## 
## @Author: gicque_p
## @Date:   2015-02-07 00:21:10
## @Last Modified by:   gicque_p
## @Last Modified time: 2015-02-07 00:43:30
##

CXX		=	g++
CXXFLAGS=	-W -Wall -Wextra -I./header/ -g
LDFLAGS	=	-L./ -lgmp
RM		=	rm -rf
NAME	=	209sondage
T_NAME	=	unit

SRC		+=	main.cpp
OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
