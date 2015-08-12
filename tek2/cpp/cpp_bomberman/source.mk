##
## source.mk for  in /home/zwertv_e/rendu/cpp_bomberman
## 
## Made by zwertv_e
## Login   <zwertv_e@epitech.net>
## 
## Started on  Wed May 20 02:53:31 2015 zwertv_e
## Last update Sun Jun 14 16:59:59 2015 zwertv_e
##

PATH_SRC	=	src/
PATH_TEST   =   test/
PATH_ITEMS  =   $(PATH_SRC)item/

SRC		+=	$(PATH_SRC)main.cpp
SRC		+=	$(PATH_SRC)GameEngine.cpp
SRC		+=	$(PATH_SRC)Map.cpp
SRC		+=	$(PATH_SRC)Display.cpp
SRC		+=	$(PATH_SRC)Exception.cpp
SRC		+=	$(PATH_SRC)Menu.cpp
SRC		+=	$(PATH_SRC)GameInput.cpp
SRC		+=	$(PATH_SRC)ADrawableObject.cpp
SRC		+=	$(PATH_SRC)APlayer.cpp
SRC		+=	$(PATH_SRC)Player.cpp
SRC		+=	$(PATH_SRC)TextureLoader.cpp
SRC		+=	$(PATH_SRC)Param.cpp

SRC		+=	$(PATH_ITEMS)AItem.cpp
SRC		+=	$(PATH_ITEMS)Bomb.cpp
SRC		+=	$(PATH_ITEMS)Floor.cpp
SRC		+=	$(PATH_ITEMS)Explosion.cpp
SRC		+=	$(PATH_ITEMS)Box.cpp
SRC		+=	$(PATH_ITEMS)Wall.cpp

SRC		+=	$(PATH_ITEMS)MenuItem.cpp
SRC		+=	$(PATH_ITEMS)Cursor.cpp

SRCTEST	+=	$(PATH_TEST)unit.cpp

SRCTEST	+=	$(PATH_SRC)Map.cpp
SRCTEST	+=	$(PATH_SRC)Exception.cpp

SRCTEST	+=	$(PATH_ITEMS)AItem.cpp
SRCTEST	+=	$(PATH_ITEMS)Bomb.cpp
SRCTEST	+=	$(PATH_ITEMS)Mine.cpp
SRCTEST	+=	$(PATH_ITEMS)Floor.cpp
SRCTEST	+=	$(PATH_ITEMS)Wall.cpp

SRCTEST	+=	$(PATH_TEST)Map.test.cpp
