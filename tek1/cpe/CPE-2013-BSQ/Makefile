##
## Makefile for bsq in /home/gicque_p/local/cpe/CPE_2013_BSQ
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Sun Dec  8 14:11:18 2013 Pierrick Gicquelais
## Last update Sun Dec  8 18:05:21 2013 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

NAME	= bsq

SRC=	main.c \
	get_next_line.c \
	str.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
