##
## Makefile for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
## 
## Made by Nicolas Ribeiro Teixeira
## Login   <ribeir_b@epitech.net>
## 
## Started on Tue Mar 18 10:35:34 2014 Nicolas Ribeiro Teixeira
## Last update Mon Apr 14 13:03:51 2014 Pierrick Gicquelais
##

CC	= gcc

RM	= rm -f

CFLAGS		+= -Wextra -Wall -W
CFLAGS		+= -I./src/include -pipe
LDFLAGS		+= -L./ -lmy -L./minilibx/ -lmlx -L/usr/X11/lib -lXext -lX11

LINK_FLAGS	=

CORE_PATH	= src/corewar/
ASM_PATH	= src/asm/
LIB_PATH	= src/lib/

GREEN		= \033[01;32m
RED		= \033[01;31m
WHITE		= \033[0m
CYAN		= \033[01;34m

COREWAR_SRCS	= $(CORE_PATH)main.c			\
		  $(CORE_PATH)init.c			\
		  $(CORE_PATH)reading.c			\
		  $(CORE_PATH)check.c			\
		  $(CORE_PATH)error.c			\
		  $(CORE_PATH)printf.c			\
		  $(CORE_PATH)str.c			\
		  $(CORE_PATH)get_octet.c		\
		  $(CORE_PATH)rev_ind.c			\
		  $(CORE_PATH)dump.c			\
		  $(CORE_PATH)write_arena.c		\
		  $(CORE_PATH)core.c			\
		  $(CORE_PATH)game.c			\
		  $(CORE_PATH)exec.c			\
		  $(CORE_PATH)fill_instru.c		\
		  $(CORE_PATH)fill_no_coding.c		\
		  $(CORE_PATH)is_instruc.c		\
		  $(CORE_PATH)void.c			\
		  $(CORE_PATH)live.c			\
		  $(CORE_PATH)load.c			\
		  $(CORE_PATH)store.c			\
		  $(CORE_PATH)zjmp.c			\
		  $(CORE_PATH)fork.c			\
		  $(CORE_PATH)add.c			\
		  $(CORE_PATH)sub.c			\
		  $(CORE_PATH)and.c			\
		  $(CORE_PATH)or.c			\
		  $(CORE_PATH)xor.c			\
		  $(CORE_PATH)aff.c			\
		  $(CORE_PATH)read_mem.c		\
		  $(CORE_PATH)screen.c			\
		  $(CORE_PATH)aff_grid.c

ASM_SRCS	= $(ASM_PATH)main.c			\
		  $(ASM_PATH)chained_list_filling.c	\
		  $(ASM_PATH)check_open_getnames.c	\
		  $(ASM_PATH)parse_chained_list.c	\
		  $(ASM_PATH)my_error.c			\
		  $(ASM_PATH)my_error_2.c		\
		  $(ASM_PATH)my_label_found.c		\
		  $(ASM_PATH)my_label_found2.c		\
		  $(ASM_PATH)creat_cor.c		\
		  $(ASM_PATH)comp_octet.c		\
		  $(ASM_PATH)put_all.c			\
		  $(ASM_PATH)put_var.c			\
		  $(ASM_PATH)check_error.c		\
		  $(ASM_PATH)check_error2.c		\
		  $(ASM_PATH)my_errnbr.c		\
		  $(ASM_PATH)put_idx.c

LIB_SRCS	= src/from_subject/op.c			\
		  $(LIB_PATH)my_putchar.c		\
		  $(LIB_PATH)my_putstr.c		\
		  $(LIB_PATH)my_strcmp.c		\
		  $(LIB_PATH)my_strlen.c		\
		  $(LIB_PATH)my_put_nbr.c		\
		  $(LIB_PATH)my_getnbr.c		\
		  $(LIB_PATH)my_strncmp.c		\
		  $(LIB_PATH)my_strlncmp_nico.c		\
		  $(LIB_PATH)my_strdup.c		\
		  $(LIB_PATH)my_strcpy.c		\
		  $(LIB_PATH)my_strlcat.c		\
		  $(LIB_PATH)my_one_get_next_line.c	\
		  $(LIB_PATH)my_check_empty_str.c	\
		  $(LIB_PATH)my_strlcmp.c		\
		  $(LIB_PATH)my_isnum.c			\
		  $(LIB_PATH)my_isneg.c

COREWAR_OBJS	= $(COREWAR_SRCS:.c=.o)

ASM_OBJS	= $(ASM_SRCS:.c=.o)

LIB_OBJS	= $(LIB_SRCS:.c=.o)

COREWAR_NAME	= corewar

ASM_NAME	= asm

LIB_NAME	= libmy.a


all		: $(LIB_NAME) $(COREWAR_NAME) $(ASM_NAME)

$(LIB_NAME)	: $(LIB_OBJS)
		@echo "$(CYAN)\n > COMPILATION LIB EN COURS\n$(WHITE)"
		ar rc $(LIB_NAME) $(LIB_OBJS)
		ranlib $(LIB_NAME)
		@echo "$(GREEN)\n > COMPILATION LIB REUSSIE\n$(WHITE)"

$(COREWAR_NAME)	: $(COREWAR_OBJS) $(LIB_NAME)
		@echo "$(CYAN)\n > COMPILATION COREWAR EN COURS\n$(WHITE)"
		$(CC) $(CFLAGS) -o $(COREWAR_NAME) $(COREWAR_OBJS) $(LDFLAGS)
		@echo "$(GREEN)\n > COMPILATION COREWAR REUSSIE\n$(WHITE)"

$(ASM_NAME)	: $(ASM_OBJS) $(LIB_NAME)
		@echo "$(CYAN)\n > COMPILATION ASM EN COURS\n$(WHITE)"
		$(CC) -o $(ASM_NAME) $(ASM_OBJS) -L./ -lmy $(LINK_FLAGS)
		@echo "$(GREEN)\n > COMPILATION ASM REUSSIE\n$(WHITE)"

clean		:
		@echo "$(RED)\n\t->>> SUPPRESSION DES .o <<<-\n$(WHITE)"
		$(RM) $(COREWAR_OBJS)
		$(RM) $(ASM_OBJS)
		$(RM) $(LIB_OBJS)

fclean		: clean
		@echo "$(RED)\n\t->>> SUPPRESSION DES EXECUTABLES <<<-\n$(WHITE)"
		$(RM) $(COREWAR_NAME)
		$(RM) $(ASM_NAME)

re		: fclean all

.PHONY:		all clean fclean re
