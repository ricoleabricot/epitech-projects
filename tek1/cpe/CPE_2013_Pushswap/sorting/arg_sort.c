/*
** sort.c for pushswap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 17 17:08:11 2013 Pierrick Gicquelais
** Last update Mon Jan  6 23:10:31 2014 Pierrick Gicquelais
*/

#include	"../push.h"

void		third_sort(int argc, char **argv, int i)
{
  int		j;

  j = 1;
  while (i < argc - 1)
    {
      if (my_getnbr(argv[i]) < my_getnbr(argv[i + 1]))
	j++;
      i++;
    }
  if (my_strcmp(argv[1], "-a") == 0 || my_strcmp(argv[2], "-a") == 0)
    {
      if (j == i - 1)
	my_error("Any sorting list. All elements are already sorted");
    }
  else
    if (j == i)
      my_error("Any sorting list. All elements are already sorted");
}

void		second_sort(int argc, char **argv, int i)
{
  int		j;

  j = 1;
  while (i < argc - 1)
    {
      if (my_getnbr(argv[i]) > my_getnbr(argv[i + 1]))
	j++;
      i++;
    }
  if (my_strcmp(argv[1], "-a") == 0 || my_strcmp(argv[2], "-a") == 0)
    {
      if (j == i - 2)
	my_error("Any sorting list. All elements are already sorted");
    }
  else
    if (j == i - 1)
      my_error("Any sorting list. All elements are already sorted");
}

int		first_sort(int argc, char **argv)
{
  int		k;

  k = 1;
  if (argv[1] && argv[2])
    {
      if (my_strcmp(argv[1], "-a") == 0 || my_strcmp(argv[2], "-a") == 0)
	k++;
      if (my_strcmp(argv[1], "-d") == 0 || my_strcmp(argv[2], "-d") == 0)
	k++;
      if (my_strcmp(argv[1], "-v") == 0 || my_strcmp(argv[2], "-v") == 0)
	k++;
    }
  if (argc <= 1 + k)
    my_error                                                            \
      ("Any sorting of chained list. You must enter two numbers minimum");
  if (my_strcmp(argv[1], "-d") == 0 || my_strcmp(argv[2], "-d") == 0)
    second_sort(argc, argv, k);
  else
    third_sort(argc, argv, k);
  return (k);
}
