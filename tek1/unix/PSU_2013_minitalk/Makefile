##
## Makefile for minitalk in /home/gicque_p/PSU_2013_minitalk
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Tue Feb 25 10:21:57 2014 Pierrick Gicquelais
## Last update Thu Mar 20 09:02:24 2014 Pierrick Gicquelais
##

CC		= gcc -g

RM		= rm -f

CLIENT		= bin/client

SERVER		= bin/server

CFLAGS		+= -I. -W -Wall -Wextra

SRC_CLIENT=	src_client/main.c	\
		src_client/send.c	\
		parsing/string.c	\
		parsing/str.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

SRC_SERVER=	src_server/main.c	\
		src_server/receive.c	\
		parsing/string.c	\
		parsing/str.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

$(SERVER):	$(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:	clean
	$(RM) $(CLIENT) $(SERVER)

re:	fclean all
