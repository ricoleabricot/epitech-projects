##
## Makefile for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Sat Apr  4 12:51:17 2015 Pierrick Gicquelais
## Last update Tue Apr 21 17:59:17 2015 Pierrick Gicquelais
##

CC	=	gcc
RM	=	rm -f
SERVER	=	server
CLIENT	=	client

CFLAGS	+=	-W -Wall -Wextra -Wno-unused-result -O2 -I./inc/misc/ -I./inc/server/ -I./inc/client/ -g

include		source.mk
S_OBJ	=	$(S_SRC:.c=.o)
C_OBJ	=	$(C_SRC:.c=.o)

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(S_OBJ)
	$(CC) $(S_OBJ) -o $(SERVER)
	mkdir -p .downloads

$(CLIENT):	$(C_OBJ)
	$(CC)  $(C_OBJ) -o $(CLIENT)

clean:
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)

fclean:		clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re:		fclean all

.PHONY:		all clean fclean re
