/*
** minitalk.h for minitalk in /home/gicque_p/PSU_2013_minitalk
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb 25 10:32:41 2014 Pierrick Gicquelais
** Last update Thu Mar 20 09:02:54 2014 Pierrick Gicquelais
*/

#ifndef		MINITALK_H_
# define	MINITALK_H_

char		*my_strcat(char *, char *);
char		*my_strcpy(char *, int);
int		my_getnbr(char *);
int		my_putchar(char);
int		my_strlen(char *);
void		my_time(int);
void		my_send(int, char *);
void		sig_handler(int);
void		write_bit(int);
void		my_putstr(char *);
void		my_putnbr(int);
void		my_error(char *, int);

#endif		/* !MINITALK_H_ */
