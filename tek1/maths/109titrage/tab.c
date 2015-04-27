/*
** tab.c for 109titrage in /home/gicque_p/local/maths/109titrage
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 31 13:55:36 2014 Pierrick Gicquelais
** Last update Wed Apr  2 16:21:42 2014 Pierrick Gicquelais
*/

#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <stdio.h>
#include        <string.h>
#include        "titrage.h"

char		**filling_tab(char **argv, int option)
{
  char		**tab;
  char		*s;
  int		i;

  i = 1;
  tab = malloc(2048 * sizeof(char *));
  tab[0] = my_strcpy("Kafei's the best");
  if (option == 1)
    {
      if (atof(argv[1]) >= 10 && atof(argv[1]) <= 80)
	tab[1] = my_strcpy(argv[1]);
      else
	my_error("The angle (arg 1) must be contained between 10 and 80", 42);
      i++;
    }
  while (((s = get_next_line(0)) != NULL) && (strcmp(s, "FIN") != 0))
    {
      tab[i] = my_strcpy(s);
      free(s);
      i++;
    }
  free(s);
  return (tab);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
