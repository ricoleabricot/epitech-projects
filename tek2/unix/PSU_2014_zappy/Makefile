##
## Makefile for Zappy in /home/rousse_3/rendu/Zappy
## 
## Made by rousse_3
## Login   <rousse_3@epitech.net>
## 
## Started on  Mon Jun 15 17:28:14 2015 rousse_3
## Last update Sun Jul  5 21:08:02 2015 Pierrick Gicquelais
##


CC		=	gcc

CXX		=	g++

RM		=	rm -f

CFLAGS		=	-Wall -Wextra -Wno-typedef-redefinition -lm -g
CFLAGS		+=	-I includes/

CXXFLAGS	=	-Wall -Wextra
CXXFLAGS	+=	-I includes/
LDFLAGS		+=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lX11

CLIENT		=	zappy_ai

SERVER		=	zappy_server

GRAPHIC		=	zappy_graphic

include			source.mk

OBJS_CLIENT	=	$(SRCS_CLIENT:.cpp=.o)

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

OBJS_GRAPHIC	=	$(SRCS_GRAPHIC:.cpp=.o)

DEPS_CLIENT	=	$(SRCS_CLIENT:.cpp=.dpd)

DEPS_SERVER	=	$(SRCS_SERVER:.c=.dpd)

DEPS_GRAPHIC	=	$(SRCS_GRAPHIC:.cpp=.dpd)

all		:	$(CLIENT) $(SERVER) $(GRAPHIC)

$(CLIENT)	:	$(OBJS_CLIENT)
			$(CXX) -o $(CLIENT) $(OBJS_CLIENT)

$(SERVER)	:	$(OBJS_SERVER)
			$(CC) -o $(SERVER) $(OBJS_SERVER) $(CFLAGS)

$(GRAPHIC)	:	$(OBJS_GRAPHIC)
			$(CXX) -o $(GRAPHIC) $(OBJS_GRAPHIC) $(LDFLAGS)

clean		:
			$(RM) $(OBJS_CLIENT) $(DEPS_CLIENT)
			$(RM) $(OBJS_SERVER) $(DEPS_SERVER)
			$(RM) $(OBJS_GRAPHIC) $(DEPS_GRAPHIC)

fclean		:	clean
			$(RM) $(CLIENT)
			$(RM) $(SERVER)
			$(RM) $(GRAPHIC)

re		:	fclean all

-include		$(DEPS_CLIENT)
-include		$(DEPS_SERVER)
-include		$(DEPS_GRAPHIC)

%.o		:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)
			@$(CC) -MM -o $*.dpd $< $(CFLAGS)
			@sed -i -e 's|.*:|$*.o:|' $*.dpd

%.o		:	%.cpp
			$(CXX) -c -o $@ $< $(CXXFLAGS)
			@$(CXX) -MM -o $*.dpd $< $(CXXFLAGS)
			@sed -i -e 's|.*:|$*.o:|' $*.dpd

.PHONY		:	all clean fclean re
