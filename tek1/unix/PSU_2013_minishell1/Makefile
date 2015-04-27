##
## Makefile for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Wed Dec 11 14:38:37 2013 Pierrick Gicquelais
## Last update Fri Dec 20 19:11:30 2013 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS	= -g -W -Wall -Wextra

NAME	= mysh

SRC=	main.c \
	processing/process.c \
	processing/exec.c \
	processing/env.c \
	processing/cd.c \
	parsing/get_next_line.c \
	parsing/my_str_to_wordtab.c \
	parsing/my_env_to_wordtab.c \
	parsing/string.c \
	parsing/str.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
