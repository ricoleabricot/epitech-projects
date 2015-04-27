##
## Makefile for 105tore in /home/gicque_p/local/maths/105tore
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Jan 13 08:53:37 2014 Pierrick Gicquelais
## Last update Mon Mar 31 14:47:41 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

SRC=	main.c \
	option.c \
	aff.c \
	error.c \
	str.c

OBJ	= $(SRC:.c=.o)

NAME	= 105tore

CFLAGS	= -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

