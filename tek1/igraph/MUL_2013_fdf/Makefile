##
## Makefile for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Thu Nov 28 13:49:37 2013 Pierrick Gicquelais
## Last update Sun Dec  8 13:51:03 2013 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -g -W -Wall -Wextra

LFLAGS	= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

NAME	= fdf

SRC=	main.c \
	display/draw.c \
	display/hook.c \
	display/display.c \
	parsing/parsing.c \
	parsing/get_next_line.c \
	parsing/my_str_to_wordtab.c \
	parsing/my_getnbr.c \
	parsing/str.c \
	parsing/error.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
