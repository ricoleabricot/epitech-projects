##
## Makefile for rt in /home/gicque_p/local/igraph/MUL_2013_rtracer
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Wed May 14 15:36:32 2014 Pierrick Gicquelais
## Last update Wed May 14 15:36:33 2014 Pierrick Gicquelais
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	rt

RED	=	\033[01;31m
YELLOW	=	\033[01;32m
GREEN	=	\033[01;33m
WHITE	=	\033[0m

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I include

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g
endif

LDFLAGS	+=	-L./ -lmlx -L /usr/X11/lib/ -lXext -lX11 -lm

include source.mk

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	@echo "$(GREEN)\t>> COMPILATION SUCCESS\n$(WHITE)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo "$(YELLOW)\t>> LINKING SUCCESS\n$(WHITE)"

clean	:
	$(RM) $(OBJ)
	@echo "$(RED)\t>> DELETING BINAIRIES SUCCESS\n$(WHITE)"

fclean	: clean
	$(RM) $(NAME)
	@echo "$(RED)\t>> DELETING EXECUTABLE SUCCESS\n$(WHITE)"

re	: fclean all
