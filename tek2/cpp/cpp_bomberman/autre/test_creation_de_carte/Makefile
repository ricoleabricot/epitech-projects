
CC		=	clang++

NAME		=	Bomberman

SRC		=	main.cpp \
			Engine.cpp \
			Cube.cpp

LIB_GDL		=	-L../LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lrt 

INCS           	=	-I../LibBomberman_linux_x64/includes/

OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	g++ -c $(SRC) -I../LibBomberman_linux_x64/includes  -L../LibBomberman_linux_x64/libs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lrt
	g++ -o $(NAME) $(OBJ) $(INCS) $(LIB_GDL) -I../LibBomberman_linux_x64/includes  -L../LibBomberman_linux_x64/libs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lrt

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
