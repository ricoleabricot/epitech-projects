##
## Makefile for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Fri Feb  7 09:08:13 2014 Pierrick Gicquelais
## Last update Fri Mar 14 15:09:50 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -I./include/ -W -Wall -Wextra -g

LDFLAGS	= -L/usr/X11/lib -L/usr/lib64 -L/usr/lib64/X11 -lmlx -lXext -lX11 -lm

NAME	= rtv1

SRC=	main.c 			\
	config/init.c 		\
	config/free.c 		\
	config/str.c		\
	calc/rotate.c		\
	calc/inter.c 		\
	calc/delta.c		\
	calc/light.c		\
	calc/shadow.c		\
	screen/img.c		\
	screen/display.c 	\
	screen/hook.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
