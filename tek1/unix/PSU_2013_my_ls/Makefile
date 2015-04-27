##
## Makefile for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Nov 25 14:30:01 2013 Pierrick Gicquelais
## Last update Thu Nov 28 17:46:08 2013 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall

NAME	= my_ls

SRC=	main.c \
	my_ls.c \
	rights.c \
	string.c \
	options.c \
	print/myprintf.c \
	print/nbr.c \
	print/option.c \
	print/str.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
