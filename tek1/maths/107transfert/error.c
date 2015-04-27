/*
** error.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Mar  6 15:15:02 2014 Pierrick Gicquelais
** Last update Sat Mar  8 11:48:27 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

void		env_error()
{
  printf("\033[01;31m");
  printf("You disabled display environment. End of programm !\n");
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		char_error(int pos)
{
  printf("\033[01;31m");
  printf("Character n°%d is not correct !\n", pos);
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		argc_error()
{
  printf("\033[01;31m");
  printf("You must enter at least 1 argument !\n");
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		string_error(int pos)
{
  printf("\033[01;31m");
  printf("Format string non valid for string n°%d. You must enter numbers\n", pos);
  printf("\033[0m");
  exit(EXIT_FAILURE);
}

void		unpair_error(int argc)
{
  printf("\033[01;31m");
  printf("You must enter a pair number of arguments. '%d' is not pair\n", argc);
  printf("\033[0m");
  exit(EXIT_FAILURE);
}
