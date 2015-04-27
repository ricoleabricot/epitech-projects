##
## Makefile for 108monstre in /home/gicque_p/local/maths/108monstre
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Mar 10 08:48:14 2014 Pierrick Gicquelais
## Last update Mon Mar 17 16:53:54 2014 Pierrick Gicquelais
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra

RM	=	rm -f

NAME	=	108monstre

SRC	=	main.c	\
		str.c	\
		error.c	\

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
