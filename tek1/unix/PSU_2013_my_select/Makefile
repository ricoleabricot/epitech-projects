##
## Makefile for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Jan 13 14:22:17 2014 Pierrick Gicquelais
## Last update Sun Jan 19 22:09:34 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra -g

LDFLAGS	= -l ncurses

SRC=	main.c \
	list/put.c \
	list/aff.c \
	termcap/init.c \
	termcap/cap.c \
	termcap/term.c \
	termcap/choice.c \
	termcap/key.c \
	string/aff.c \
	string/str.c \
	string/error.c \
	string/put.c

OBJ	= $(SRC:.c=.o)

NAME	= my_select

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
