/*
** asm.h for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Mon Mar 24 14:04:37 2014 Nicolas Ribeiro Teixeira
** Last update Sat Apr 12 12:05:02 2014 Nicolas Ribeiro Teixeira
*/

#ifndef		ASM_H_
# define	ASM_H_

typedef		struct s_list	t_list;

struct		s_list
{
  int		argnbr;
  int		line;
  char		**args;
  int		octet;
  t_list	*next;
};

int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_strlcmp(char *, char *, int);
char		*my_get_name(int, int *, int, int);
char		*my_get_comment(int, int *, int, int);
void		my_check_name(char *, int);
int		my_get_champ_fd(char *);
int		my_get_doublepoint_pos(char *);
int		my_special_doublepoint_pos(char *);
t_list		*my_append_instruction(t_list *, char *, int *, int);
t_list		*parse_chained_list(t_list *);
void		my_error(int, char *, int , char *);
void		check_indirect(t_list *, int);
char		**my_label_found(char **, int *, char *);
void		write_cor(t_list *, char **, int);
void		label_undefined(int, char *);
void		check_errnbr(char *, char, int);
void		my_errnbr(char *, int);
char		**my_opcode_found(char **, char *, int, int);
int		spec_case(char *, t_list **, int, int *);
int		my_get_line_nbr(t_list *, char *);
char		**special_instruction(char *, int);
char		*my_cut_str(int, char *);
void		my_warnings(int, int);
void		no_such_register(int);
void		check_direct(t_list *, int);

#endif		/* !ASM_H_ */
