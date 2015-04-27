/*
** lib.h for rt in /home/gicque_p/rendu/MUL_2013_rtracer/include
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:04:59 2014 Pierrick Gicquelais
** Last update Wed May 14 08:15:54 2014 Pierrick Gicquelais
*/

#ifndef		LIB_H_
# define	LIB_H_

# include	<stdarg.h>
# define	BUF_SIZE	(1)

char		*get_next_line(int);
char		*epur_str(char *);
char		*my_strndup(char *, char *, int);
char		*my_strcat(char *, char *);
int		my_fputchar(int, char);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
int		my_strncpy(char *, char *, char *, int);
int		my_getnbr(char *);
int		my_isnum(char *);
void		my_fputstr(int, char *);
void		my_fputnbr(int, int);
void		my_fprintf(int, const char *, ...);
void		my_error(char *);

#endif		/* !LIB_H_ */
