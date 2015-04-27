/*
** main.h for 101pong in /home/gicque_p/local/maths/101pong
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sat Nov  9 14:11:30 2013 Pierrick Gicquelais
** Last update Thu Nov 14 14:54:24 2013 Pierrick Gicquelais
*/

#ifndef MAIN_H_
#define MAIN_H_

void		my_putchar(char);
void		my_putstr(char *);
int		*speed_vector(int *, int, char **);
int		*pos_coord(int *, int *, int);
int		my_put_nbr(int);
int		my_getnbr(char *);
int		check_char(char *);
void		check_option(char, void *);
void		my_printf(const char *, ...);
unsigned int	my_put_nbr_octal(unsigned int);
unsigned int	my_put_nbr_hexa(unsigned int);
float		scalaire_prod(int *);
int		my_square_root(int);
int		my_str_isnum(char *);

#endif
