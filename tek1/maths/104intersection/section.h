/*
** section.h for 104intersection in /home/gicque_p/local/maths/104intersection
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 17 21:32:43 2013 Pierrick Gicquelais
** Last update Sat Jan  4 21:13:40 2014 Pierrick Gicquelais
*/

#ifndef		SECTION_H_
# define	SECTION_H_

# include	<math.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>

void		check_option(char **);
void		my_sphere(char **);
void		my_cylinder(char **);
void		my_cone(char **);
void		maff_result(double, double, double, char **);
void		my_putchar(char);
void		my_putstr(char *);
void		my_error(char *);
void		my_few_error(int);
void		my_many_error(int);
void		my_number_error(int, char **);
void		my_vector_error();
void		my_radius_error();
void		my_bonus(int, char **);
void		my_bonus_few_error(int);
void		my_bonus_many_error(int);
int		my_str_isnum(char *);

#endif /* !SECTION_H_ */
