/*
** tore.h for 105tore in /home/gicque_p/local/maths/105tore
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 08:55:48 2014 Pierrick Gicquelais
** Last update Sun Jan 19 20:05:06 2014 Pierrick Gicquelais
*/

#ifndef		TORE_H_
# define	TORE_H_

# include	<math.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

int		my_str_isnum(char *);
void		option_choice(char **);
void		aff_equation(char **);
void		aff_bissection(double, double, double, double, double, double, double, char **);
void		aff_newton(double, double, double, double, double, double, char **);
void		aff_secante(double, double, double, double, double, double, double, char **);
void		my_putchar(char);
void		my_putstr(char *);
void		my_error(char *);
void		my_few_error(int);
void		my_many_error(int);
void		my_choice_error(char **);
void		my_number_error(int, char **);

#endif /* !TORE_H_ */
