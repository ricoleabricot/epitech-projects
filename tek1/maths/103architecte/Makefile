##
## Makefile for 103architecte in /home/gicque_p/local/maths/103architecte
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Dec  9 09:36:36 2013 Pierrick Gicquelais
## Last update Wed Dec 11 13:06:03 2013 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -g -lm -W -Wall -Wextra

NAME	= 103architecte

SRC=	main.c \
	calc.c \
	matrice.c \
	option.c \
	str.c \
	my_str_isnum.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
