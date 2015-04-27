/*
** lib.h for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/lib
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Tue Mar 18 10:45:26 2014 Nicolas Ribeiro Teixeira
** Last update Thu Apr 10 17:23:32 2014 Pierrick Gicquelais
*/

#ifndef		LIB_H_
# define	LIB_H_

typedef		struct s_gnl	t_gnl;

struct		s_gnl
{
  char		letter;
  t_gnl		*next;
};

int		my_getnbr(char *);
int		my_strcmp(char *, char *);
int		my_strlen(char *);
int		my_strncmp(char *, char *, int);
int		my_strlcmp(char *, char *, int);
int		empty_str(char *);
int		my_isnum(char *);
int		my_isneg(char *);
int		my_strlncmp_nico(char *, int, int, char *);
int		my_putchar(char);
void		my_putstr(char *);
void		my_put_nbr(int);
char		*my_one_get_next_line(int);
char		*my_strdup(char *);
char		*my_strlcat(char *, int, int, char *);
char		*my_strcpy(char *, char *);

#endif		/* !LIB_H_ */
