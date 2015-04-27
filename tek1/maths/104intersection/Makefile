##
## Makefile for 104intersection in /home/gicque_p/local/maths/104intersection
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Tue Dec 17 21:29:30 2013 Pierrick Gicquelais
## Last update Sat Jan  4 20:37:09 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra -lm

NAME	=	104intersection

SRC=	main.c \
	option.c \
	aff.c \
	error.c \
	str.c \
	bonus.c \
	bonus_error.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
