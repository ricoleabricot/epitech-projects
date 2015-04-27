## 
## @Author: gicque_p
## @Date:   2015-02-07 00:21:10
## @Last Modified by:   gicque_p
## @Last Modified time: 2015-02-07 00:43:30
##

CXX		=	g++
CXXFLAGS=	-W -Wall -Wextra -I./header/ -g
RM		=	rm -rf
NAME	=	avm
T_NAME	=	unit

include		source.mk
OBJ		=	$(SRC:.cpp=.o)
T_OBJ	=	$(T_SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(T_OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)
	$(CXX) $(T_OBJ) -o $(T_NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJ) $(T_OBJ)

fclean:		clean
	$(RM) $(NAME) $(T_NAME)

re:			fclean all

.PHONY:		all clean fclean re
