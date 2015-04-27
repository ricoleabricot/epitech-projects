##
## Makefile for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
##
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
##
## Started on  Mon Feb  3 21:17:42 2014 Pierrick Gicquelais
## Last update Fri Feb 14 10:49:44 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

NAME	= allum1

SRC=	main.c \
	screen/display.c \
	screen/display_allum.c \
	screen/display_nim.c \
	choosing/choice.c \
	choosing/key.c \
	choosing/first_check.c \
	choosing/check.c \
	choosing/advanced_check.c \
	choosing/launch.c \
	calc/allum.c \
	calc/algo_nim.c \
	calc/pvp_nim.c \
	calc/intell_allum.c \
	calc/intell_nim.c \
	termcap/cap.c \
	termcap/term.c \
	string/get_next_line.c \
	string/get.c \
	string/str.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra

LDFLAGS	= -lncurses

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
