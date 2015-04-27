/*
** main.c for 109titrage in /home/gicque_p/local/maths/109titrage
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Mon Mar 24 09:22:00 2014 Pierrick Gicquelais
** Last update Wed Apr  2 16:18:24 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"titrage.h"

int		main(int argc, char **argv, char **envp)
{
  char		**tab;

  (void)argv;
  if (argc == 1)
    {
      tab = filling_tab(argv, 0);
      execve("./derivee", tab, envp);
    }
  else if (argc == 2)
    {
      tab = filling_tab(argv, 1);
      execve("./tangente", tab, envp);
    }
  else
    my_error("You cannot enter more than 1 arguments to launch the programm", 42);
  free_tab(tab);
  return (0);
}
