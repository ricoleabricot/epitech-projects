/*
** op.h for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Tue Apr  8 15:59:56 2014 Nicolas Ribeiro Teixeira
** Last update Tue Apr  8 16:00:11 2014 Nicolas Ribeiro Teixeira
*/

#ifndef			_OP_H_
# define		_OP_H_

# define		IDX_MOD			512
# define		MAX_ARGS_NUMBER		4

# define		COMMENT_CHAR		'#'
# define		LABEL_CHAR		':'
# define		DIRECT_CHAR		'%'
# define		SEPARATOR_CHAR		','

# define		LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define		NAME_CMD_STRING		".name"
# define		COMMENT_CMD_STRING	".comment"

# define		REG_NUMBER		16

typedef			char			args_type_t;

# define		T_REG			1
# define		T_DIR			2
# define		T_IND			4

struct						op_s
{
   char						*mnemonique;
   char						nbr_args;
   args_type_t					type[MAX_ARGS_NUMBER];
   char						code;
   int						nbr_cycles;
   char						*comment;
};

typedef			struct op_s		op_t;

# define		IND_SIZE		2
# define		REG_SIZE		4
# define		DIR_SIZE		REG_SIZE

extern			op_t			op_tab[];

# define		COREWAR_EXEC_MAGIC	0xea83f3
# define		PROG_NAME_LENGTH	128
# define		COMMENT_LENGTH		2048

struct header_s
{
   int						magic;
   char						prog_name[PROG_NAME_LENGTH + 1];
   int						prog_size;
   char						comment[COMMENT_LENGTH + 1];
};

typedef			struct header_s		header_t;

#endif			/* !OP_H_ */
