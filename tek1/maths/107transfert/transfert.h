/*
** transfert.h for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 24 21:11:35 2014 Pierrick Gicquelais
** Last update Sun Mar  9 12:25:23 2014 Pierrick Gicquelais
*/

#ifndef		TRANSFERT_H_
# define	TRANSFERT_H_

# include	<math.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>

char		**my_str_to_wordtab(char *);
int		*my_tab_to_int(char **, int);
int		*my_reverse_tab_to_int(char **, int);
int		check_env(char **);
int		check_string(char *);
int		my_pow(int, int);
void		ex1(char *);
void		ex2(int, char **);
void		aff_equation(int *, int);
void		aff_suscomp(int *, int, int, int);
void		aff_subcomp(int *, int);
void		my_free(char **);
void		argc_error();
void		env_error();
void		char_error(int);
void		string_error(int);
void		unpair_error(int);

#endif		/* !TRANSFERT_H_ */
