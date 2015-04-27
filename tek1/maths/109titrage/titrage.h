/*
** titrage.h for 109titrage in /home/gicque_p/local/maths/109titrage
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Mar 24 09:22:32 2014 Pierrick Gicquelais
** Last update Wed Apr  2 16:18:33 2014 Pierrick Gicquelais
*/

#ifndef		TITRAGE_H_
# define	TITRAGE_H_

# define	BUF_SIZE (1)

char		**filling_tab(char **, int);
char		*get_next_line(int);
char		*my_strcpy(char *);
int		my_strlen(char *);
void		free_tab(char **);
void		my_error(char *, int);

#endif		/* !TITRAGE_H_ */
