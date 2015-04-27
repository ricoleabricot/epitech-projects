/*
** champ.h for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Mar 20 13:32:25 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:18:44 2014 Pierrick Gicquelais
*/

#ifndef				__STRUCT_H_
# define			__STRUCT_H_

# include	"maccro.h"

typedef struct	s_header	t_header;
typedef struct	s_ptr		t_ptr;
typedef struct	s_champ		t_champ;
typedef struct	s_info		t_info;
typedef struct	s_vm		t_vm;
typedef struct	s_instru	t_instru;
typedef	struct	op_s		op_t;
typedef	struct	s_arena		t_arena;
typedef	char			args_type_t;

struct				op_s
{
   char				*mnemonique;
   char				nbr_args;
   args_type_t			type[MAX_ARGS_NUMBER];
   char				code;
   int				nbr_cycles;
   char				*comment;
};

struct				s_header
{
  int				magic;
  char				prog_name[PROG_NAME_LENGHT + 1];
  int				prog_size;
  char				comment[COMMENT_LENGHT + 1];
};

struct				s_instru
{
  int				opcode;
  int				coding;
  char				param[4][5];
  int				exec_cycle;
  int				size;
};

struct				s_info
{
  int				prog_nbr;
  int				load_adress;
  int				pos;
  int				prog_size;
  char				name[PROG_NAME_LENGHT + 1];
  char				comment[COMMENT_LENGHT + 1];
};

struct				s_champ
{
  int				pc;
  int				reg[REG_NUMBER];
  char				live;
  char				carry;
  t_instru			*instru;
  t_champ			*next;
};

struct				s_ptr
{
  void				*mlx_ptr;
  void				*win_ptr;
  void				*img_ptr;
  char				*data;
  int				bpp;
  int				sizeline;
  int				endian;
};

struct				s_arena
{
  unsigned char			arena[MEM_SIZE];
  int				block;
  int				player;
};

struct				s_vm
{
  t_ptr				*ptr;
  t_champ			**ch;
  t_info			info[4];
  t_arena			*arena;
  int				champ_nbr;
  int				cycle;
  int				cycle_to_die;
  int				nbr_live;
  int				dump_nbr;
};

#endif				/* !__STRUCT_H_ */
