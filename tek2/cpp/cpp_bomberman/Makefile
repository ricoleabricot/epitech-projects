##
## Makefile for  in /home/zwertv_e/rendu/cpp_bomberman
## 
## Made by zwertv_e
## Login   <zwertv_e@epitech.net>
## 
## Started on  Wed May 20 16:44:51 2015 zwertv_e
## Last update Fri May 22 15:13:19 2015 Antoine Plaskowski
##

NAME		 =	bomberman

TEST		 =	unit

CXX			?=	g++

RM			=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB			=	-L LibBomberman_linux_x64/libs/ -l gdl_gl -l GL -l GLEW -l rt -l fbxsdk -l SDL2 -l pthread -l dl

INCLUDE		=	-I include/ -I LibBomberman_linux_x64/includes/

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-Wno-padded
##CXXFLAGS	+=	-ansi -pedantic
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CXX), clang)
CXXFLAGS	+=	-Weverything -Wno-padded
endif

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include		source.mk

DPD			=	$(SRC:.cpp=.dpd)
DPD			+=	$(SRCTEST:.cpp=.dpd)

OBJ			=	$(SRC:.cpp=.o)
OBJTEST		=	$(SRCTEST:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

$(TEST)		:	$(OBJTEST)
			$(CXX) $(OBJTEST) -o $(TEST) $(LDFLAGS)

clean		:
			@$(RM) -f $(OBJ)
			@$(RM) -f $(OBJTEST)
			@$(RM) -f $(DPD)

fclean		:	clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(TEST)

re			:	fclean all

%.dpd			:	%.cpp
			@$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o			:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.cpp .dpd.cpp

-include		$(DPD)
