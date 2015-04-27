##
## Makefile for malloc in /home/boisso_c/rendu/PSU_2014_malloc
## 
## Made by Christian Boisson
## Login   <boisso_c@epitech.net>
## 
## Started on  Wed Feb 11 10:31:00 2015 Christian Boisson
## Last update Wed Feb 11 10:37:09 2015 Christian Boisson
##

CC		=	gcc
RM		=	rm -f
NAME		=	libmy_malloc_$(HOSTTYPE).so
LNK_NAME	=	libmy_malloc.so
CFLAGS		=	-W -Wall -Wextra -I./inc/
CFLAGS		+=	-shared -fPIC
DEBUG		=	no

ifeq ($(DEBUG), yes)
CFLAGS		+=	-g
endif

include source.mk
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	ln -sf $(NAME) $(LNK_NAME)
clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
