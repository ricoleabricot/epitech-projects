/*
** error.c for 102chiffrement in /home/gicque_p/local/maths/102chiffrement
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Nov 24 17:37:05 2013 Pierrick Gicquelais
** Last update Sat Nov 30 14:47:58 2013 Pierrick Gicquelais
*/

#include "main.h"

void	my_list_error(int argc, char **argv)
{
  int	i;

  i = 2;
  if (argc != 8)
    {
      printf("\033[01;31m");
      printf("Wrong number of arguments. Must be 7.\nMan 102Chiffrement : Argument 1 must be a string with only minus letters and spaces.\n");
      printf("Arguments 2 to 5 must be numbers.\nArgument 6 must be a string with only different characters.\nArgument 7 must be '0' to code or '1' to decode\n");
      exit (0);
    }
  if (atoi(argv[7]) != 0 && atoi(argv[7]) != 1)
    {
      printf("\033[01;31m");
      printf("Argument 7 must be '0' to code or '1' to decode.\n");
      exit (0);
    }
  while (i <= 5)
    {
      if (my_str_isnum(argv[i]) == 0)
  	{
  	  printf("\033[01;31m");
  	  printf("Argument %d must be a number.\n", i);
  	  exit (0);
  	}
      i++;
    }
}

void	my_list_error_next(char **argv)
{
  int	i;

  i = 0;
  while (argv[1][i])
    {
      if ((argv[1][i] < 'a' || argv[1][i] > 'z') && argv[1][i] != ' ' && atoi(argv[7]) == 0)
	{
	  printf("\033[01;31m");
	  printf("Message (argument 1) must only contained minus letters or spaces.\nCharacter %c is not a typo you can use.\n", argv[1][i]);
	  exit (0);
	}
      i++;
    }
  i = 0;
  while (argv[6][i])
    {
      if (argv[6][i] == argv[6][i + 1])
	{
	  printf("\033[01;31m");
	  printf("Base must contained only different characters.\nCharacter %d and %d are the same !\n", i + 1, i + 2);
	  exit (0);
	}
      i++;
    }
  i = 0;
  if (atoi(argv[7]) == 1)
    while (argv[1][i])
      {
	if (argv[1][i] != ' ')
	  {
	    if (pos_base(argv[1][i], argv[6]) == -1)
	      {
		printf("\033[01;31m");
		printf("Character: %c in the strings are not present in base\n", argv[1][i]);
		exit (0);
	      }
	  }
	i++;
      }
}
