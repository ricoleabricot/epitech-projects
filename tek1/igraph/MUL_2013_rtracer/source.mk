##
## source.mk for rt in /home/gicque_p/rendu/MUL_2013_rtracer
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon May 12 13:50:55 2014 Pierrick Gicquelais
## Last update Wed May 14 18:55:28 2014 Pierrick Gicquelais
##

SRC_PATH=	src/
LIB_PATH=	$(SRC_PATH)lib/
PARS_PATH=	$(SRC_PATH)parsing/

SRC	+=	$(SRC_PATH)main.c

SRC	+=	$(PARS_PATH)new_obj.c
SRC	+=	$(PARS_PATH)new_tmp.c
SRC	+=	$(PARS_PATH)node_obj.c
SRC	+=	$(PARS_PATH)append_obj.c
SRC	+=	$(PARS_PATH)aff_obj.c
SRC	+=	$(PARS_PATH)parsing.c
SRC	+=	$(PARS_PATH)function.c
SRC	+=	$(PARS_PATH)eye.c
SRC	+=	$(PARS_PATH)sphere.c
SRC	+=	$(PARS_PATH)cyl.c
SRC	+=	$(PARS_PATH)cone.c
SRC	+=	$(PARS_PATH)plan.c
SRC	+=	$(PARS_PATH)spot.c
SRC	+=	$(PARS_PATH)value.c
SRC	+=	$(PARS_PATH)check.c
SRC	+=	$(PARS_PATH)free.c

SRC	+=	$(LIB_PATH)my_fputchar.c
SRC	+=	$(LIB_PATH)my_fputstr.c
SRC	+=	$(LIB_PATH)my_fputnbr.c
SRC	+=	$(LIB_PATH)my_fprintf.c
SRC	+=	$(LIB_PATH)my_strlen.c
SRC	+=	$(LIB_PATH)my_strcat.c
SRC	+=	$(LIB_PATH)my_strndup.c
SRC	+=	$(LIB_PATH)my_strncpy.c
SRC	+=	$(LIB_PATH)my_strcmp.c
SRC	+=	$(LIB_PATH)my_isnum.c
SRC	+=	$(LIB_PATH)my_getnbr.c
SRC	+=	$(LIB_PATH)my_error.c
SRC	+=	$(LIB_PATH)epur_str.c
SRC	+=	$(LIB_PATH)get_next_line.c

