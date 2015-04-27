# 
## @Author: gicque_p
## @Date:   2015-02-02 09:25:07
## @Last Modified by:   gicque_p
## @Last Modified time: 2015-02-02 09:25:07
#

CXX		=	g++
RM		=	rm -f
CXXFLAGS=	-W -Wall -Wextra -I./header/
NAME	=	201yams

include		source.mk
OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
