##
## Makefile for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Wed Feb 25 13:57:24 2015 Pierrick Gicquelais
## Last update Wed Mar  4 12:00:19 2015 Pierrick Gicquelais
##

CC	=	gcc
RM	=	rm -f
NAME	=	lemipc
DISPLAY	=	display
CFLAGS	=	-W -Wall -Wextra -g -I./inc/
LDFLAGS	=	-lSDL

include		source.mk
OBJ	=	$(SRC:.c=.o)
D_OBJ	=	$(D_SRC:.c=.o)

all:		$(NAME) $(DISPLAY)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(DISPLAY):	$(D_OBJ)
	$(CC) $(D_OBJ) -o $(DISPLAY) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(D_OBJ)

fclean:		clean
	$(RM) $(NAME) $(DISPLAY)

re:		fclean all

.PHONY:		all clean fclean re
