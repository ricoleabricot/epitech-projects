/*
** architecte.h for 103architecte in /home/gicque_p/local/maths/103architecte
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 10 19:56:36 2013 Pierrick Gicquelais
** Last update Thu Dec 12 18:30:40 2013 Pierrick Gicquelais
*/

#ifndef ARCHITECTE_H_
#	define ARCHITECTE_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double	*check_option(double *, double *, char **, int);
double	*my_translation(double *, double *, char **, int);
double	*my_homothetie(double *, double *, char **, int);
double	*my_rotation(double *, double *, char **, int);
double	*my_symetrie(double *, double *, char **, int);
double	*mult_mat(double *, double *);
double	*fill_mat_rot(double *, double, double);
double	*fill_mat_sym(double *, double, double);
void	aff_mat(double *);
void	my_putchar(char);
void	my_putstr(char *);
void	my_error(char *);
void	check_error_one(char *);
void	check_error_two(char *);
int	my_str_isnum(char *);

#endif /* !ARCHITECTE_H_ */
