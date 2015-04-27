##
## Makefile for 106bombyx in /home/gicque_p/local/maths/106bombyx
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Feb 10 09:00:35 2014 Pierrick Gicquelais
## Last update Sat Feb 15 11:59:01 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra -g

LDFLAGS	= -L/usr/X11/lib -L/usr/lib64 -L/usr/lib64/X11 -lmlx -lXext -lX11 -lm
##LDFLAGS	= `sdl-config --cflags --libs`

NAME	= 106bombyx

SRC=	main.c \
	init.c \
	check.c \
	ex1.c \
	ex2.c \
	display.c \
	draw.c \
	scale.c \
	hook.c \
	free.c \
	str.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
