##
## Makefile for 101pong in /home/gicque_p/local/maths
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Sat Nov  9 13:22:13 2013 Pierrick Gicquelais
## Last update Thu Nov 14 14:47:06 2013 Pierrick Gicquelais
##

CC	= gcc -Wall -ansi -lm

RM	= rm -f

NAME	= 101pong

SRC=	main.c \
	str.c \
	my_getnbr.c \
	nbr.c \
	my_str_isnum.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
