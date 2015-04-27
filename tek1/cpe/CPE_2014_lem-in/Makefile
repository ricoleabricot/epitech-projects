##
## Makefile for lemin in /home/gicque_p/local/cpe/CPE_2014_lem-in
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Thu Apr 17 10:54:58 2014 Pierrick Gicquelais
## Last update Fri Apr 18 11:37:07 2014 Pierrick Gicquelais
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-I./include/
CFLAGS	+=	-W -Wall -Wextra -g

NAME	=	lem_in

SRC	=	main.c		\
		graphe.c	\
		list.c		\
		parsing.c	\
		get_next_line.c	\
		epur.c		\
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

.PHONY:		all clean fclean re
