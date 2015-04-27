/*
** creat_cor.h for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Tue Mar 25 10:17:28 2014 Christian Boisson
** Last update Fri Apr 11 16:57:14 2014 Nicolas Ribeiro Teixeira
*/

#ifndef		CREAT_COR_H_
# define       	CREAT_COR_H_

#include	"asm.h"

typedef struct s_label
{
  int		pos;
  char		*name;
} t_label;

header_t	name_comment(char *, char *);
int		rev_int(int);
int		comp_octet(t_list *, t_label *, int);
int		instruct_size(char *, char *);
int		inst_idx_size(char *);
void		put_opcode(int, char *);
void		put_instruct(int, t_list *, t_label *);
void		put_coding(int, char *, char *);
void		put_arg(int, t_label *, char **, int);
void		put_idx_arg(int, t_label *, char **, int);
void		put_reg(int, char *);
void		put_label(int, char *, t_label *, int);
void		put_idx_label(int, char *, t_label *, int);
void		put_idx_dir(int, char *);
void		put_dir(int, char *);
void		put_ind(int, char *);
void		check_error(t_list *, t_label *);
void		label_exist(t_list *, t_label *, int);
void		check_params(t_list *);
void		check_reg(t_list *);
void		check_reg2(char **, int);
void		choice_error(t_list *, int, int);
void		check_label_are_rights(t_list *, t_label *);

#endif		/* !CREAT_COR_H_ */
