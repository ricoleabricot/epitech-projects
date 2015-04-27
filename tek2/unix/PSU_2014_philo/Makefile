##
## Makefile for malloc in /home/plasko_a/programation/c/malloc
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Wed Feb 25 08:53:51 2014 Antoine Plaskowski
## Last update Wed Feb 25 16:33:58 2015 Antoine Plaskowski
##

NAME			=	philo

CC			?=	gcc

RM			=	rm -f

MKDIR			=	mkdir -p

RMDIR			=	rmdir --ignore-fail-on-non-empty

ECHO			=	/bin/echo

DEBUG			?=	no

LEVEL			?=	3

COLOR			?=	no

LIB			=	-l pthread

INCLUDE			=	-I inc/

CFLAGS			=	-Wall -Wextra -O$(LEVEL)
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	$(INCLUDE)

ifeq ($(CC), clang)
CFLAGS			+=	-Weverything -Wno-padded
endif

ifneq ($(DEBUG), no)
CFLAGS			+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS			+=	-fdiagnostics-color
endif

LDFLAGS			+=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS			+=	-s
endif

DFLAGS			=	-Y -w80 $(INCLUDE)

SRC			=

include				source.mk

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			:
				$(RM) $(OBJ)
				$(RM) $(NAME)

re			:	fclean all

depend			:
				makedepend $(SRC) $(DFLAGS)

%.o			:	%.c
				$(CC) -c $< -o $@ $(CFLAGS)

%.s			:	%.c
				$(CC) -S $< -o $@ $(CFLAGS)

.PHONY			:	all clean fclean re %.o %.s

.SUFFIXES		:	.o.c .s.c

# DO NOT DELETE
