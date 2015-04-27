##
## Makefile for 109titrage in /home/gicque_p/local/maths/109titrage
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Mar 24 09:20:11 2014 Pierrick Gicquelais
## Last update Mon Mar 31 13:58:37 2014 Pierrick Gicquelais
##

CC	=	gcc -g

RM	=	rm -f

NAME	=	109titrage

CFLAGS	=	-I./ -W -Wall -Wextra -lm

SRC	=	main.c			\
		get_next_line.c		\
		tab.c			\
		str.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
