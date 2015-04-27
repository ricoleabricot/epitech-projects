##
## Makefile for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Sun Nov 24 17:33:54 2013 Pierrick Gicquelais
## Last update Sat Nov 30 11:12:03 2013 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -g -W -Wall -lm

NAME	= 102chiffrement

SRC=	main.c \
	error.c \
	code.c \
	matrice.c \
	str.c \
	base.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
