##
## source.mk for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Wed Feb 25 13:59:13 2015 Pierrick Gicquelais
## Last update Sun Mar  8 19:29:16 2015 Pierrick Gicquelais
##

SRC	+=	src/main.c
SRC	+=	src/lemipc.c
SRC	+=	src/map.c
SRC	+=	src/player.c
SRC	+=	src/game.c
SRC	+=	src/algorithm.c
SRC	+=	src/usage.c
SRC	+=	src/move.c
SRC	+=	src/ia.c
SRC	+=	$(X_SRC)

D_SRC	+=	src/display.c
D_SRC	+=	src/lemipc.c
D_SRC	+=	$(X_SRC)

X_SRC	+=	src/xmalloc.c
X_SRC	+=	src/xftok.c
X_SRC	+=	src/xshm.c
X_SRC	+=	src/xsem.c
X_SRC	+=	src/xmsg.c
X_SRC	+=	src/error.c
