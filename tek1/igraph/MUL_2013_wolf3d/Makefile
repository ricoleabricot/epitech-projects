##
## Makefile for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Tue Dec 10 09:04:36 2013 Pierrick Gicquelais
## Last update Tue Feb  4 15:32:35 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -Wextra -g

LFLAGS	= -L/usr/X11/lib -L/usr/lib64 -L/usr/lib64/X11 -lmlx -I/sur/X11/include -lXext -lX11 -lm

NAME	= wolf3d

SRC=	main.c \
	screen/display.c \
	screen/color.c \
	screen/minimap.c \
	event/hook.c \
	event/move.c \
	event/algo.c \
	event/deplacement.c \
	event/teleportation.c \
	initialization/init.c \
	initialization/init_struct.c \
	parsing/parsing.c \
	parsing/get_next_line.c \
	parsing/str.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
