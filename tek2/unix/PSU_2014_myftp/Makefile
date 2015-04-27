##
## Makefile for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Wed Feb 25 13:57:24 2015 Pierrick Gicquelais
## Last update Sun Mar 22 12:49:24 2015 Pierrick Gicquelais
##

CC	=	gcc
RM	=	rm -f
SERVER	=	serveur
CLIENT	=	client

CFLAGS	+=	-W -Wall -Wextra -Wno-unused-result -O2 -I./inc/misc/ -I./inc/server/ -I./inc/client/

S_DIR	=	src/server
C_DIR	=	src/client

S_INC	=	-I./inc/server/

include		source.mk
S_OBJ	=	$(S_SRC:.c=.o)
C_OBJ	=	$(C_SRC:.c=.o)

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(S_OBJ)
	$(CC) $(S_OBJ) -o $(SERVER) $(LDFLAGS)

$(CLIENT):	$(C_OBJ)
	$(CC)  $(C_OBJ) -o $(CLIENT)

clean:
	$(RM) $(S_OBJ) $(C_OBJ)

fclean:		clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re:		fclean all

.PHONY:		all clean fclean re
