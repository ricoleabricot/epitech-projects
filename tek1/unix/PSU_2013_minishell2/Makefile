##
## Makefile for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
##
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
##
## Started on  Thu Feb 13 09:12:18 2014 Pierrick Gicquelais
## Last update Thu Mar  6 15:12:38 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -I./ -W -Wall -Wextra

NAME	= mysh

SRC=	main.c 				\
	builtins/env.c 			\
	builtins/my_builtin.c		\
	builtins/cd.c			\
	builtins/free.c			\
	processing/process.c 		\
	processing/exec.c 		\
	processing/redirection.c	\
	processing/pipe.c		\
	parsing/get_next_line.c 	\
	parsing/my_str_to_wordtab.c 	\
	parsing/my_env_to_wordtab.c 	\
	parsing/check.c			\
	parsing/malloc.c		\
	parsing/my_getnbr.c 		\
	parsing/string.c		\
	parsing/str.c			\
	list/init.c			\
	list/put.c			\
	list/aff.c			\
	printf/myprintf.c		\
	printf/nbr.c			\
	printf/option.c			\
	printf/str.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
