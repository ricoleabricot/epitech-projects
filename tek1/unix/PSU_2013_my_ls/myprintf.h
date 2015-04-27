/*
** main.h for my_printf in /home/gicque_p/local/unix/PSU_2018_my_printf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov  4 15:50:21 2013 Pierrick Gicquelais
** Last update Thu Nov 14 20:10:38 2013 Pierrick Gicquelais
*/

#ifndef MYPRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

void		my_putchar(char);
void		my_my_putchar(char, int);
int		my_int_putchar(int);
void		my_my_putstr(char *);
int		my_printf(const char *, ...);
int		check_char(const char *);
void		check_option(char, va_list);
int		my_put_nbr(int);
int		my_my_put_nbr(int);
void		option_nbr(char, va_list);
void		option_string(char, va_list);
void		option_char(char, va_list);
unsigned int	my_put_nbr_unsign(unsigned int);
unsigned int	my_put_nbr_octal(unsigned int);
unsigned int	my_put_nbr_hexa(unsigned int, char);
unsigned int	my_put_nbr_bin(unsigned int);
void		my_putstr_octal(char *);
int		my_is_prime(int);

#endif
