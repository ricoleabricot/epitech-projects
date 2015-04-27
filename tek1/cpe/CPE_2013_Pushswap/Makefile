##
## Makefile for pushswap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Dec 16 12:46:18 2013 Pierrick Gicquelais
## Last update Mon Jan  6 21:02:25 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -g -W -Wall -Wextra

NAME	= push_swap

SRC=	main.c \
	list/init.c \
	list/put.c \
	list/action.c \
	list/aff.c \
	sorting/sort.c \
	sorting/arg_sort.c \
	string/my_getnbr.c \
	string/str.c \
	bonus.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
