/*
** main.h for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Nov 24 17:41:00 2013 Pierrick Gicquelais
** Last update Sat Nov 30 12:36:50 2013 Pierrick Gicquelais
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	my_list_error(int, char **);
void	my_list_error_next(char **);
void	my_encode(char **);
void	my_decode(char **);
void	my_decode_next(char **, int *, int);
void	matrice_prod(int *, int, char **);
int	*inverse_matrice(char **);
void	convert_base(int, char *);
int	reconvert_base(char *, char *);
int	my_str_isnum(char *);
int	my_strlen(char *);
void	my_putchar(char);
void	my_putstr(char *);
double	pow(double, double);

#endif /* !MAIN_H_ */
