##
## Makefile for 107transfert in /home/gicque_p/local/maths/107transfert
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Feb 24 21:08:57 2014 Pierrick Gicquelais
## Last update Sat Mar  8 10:31:21 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

NAME	= 107transfert

CFLAGS	= -W -Wall -Wextra -g

SRC=	main.c			\
	ex1.c			\
	ex2.c			\
	check.c			\
	my_str_to_wordtab.c	\
	aff.c			\
	math.c			\
	free.c			\
	error.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
