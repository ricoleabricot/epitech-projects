/*
** main.c for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Nov 28 15:52:55 2013 Pierrick Gicquelais
** Last update Fri Nov 29 12:51:51 2013 Pierrick Gicquelais
*/

#include "my_ls.h"

int	main(int argc, char **argv)
{
  DIR	*dirp;
  char	option;
  int	i;

  i = 1;
  if ((dirp = opendir(".")) == NULL)
    return (0);
  option = check_options(argv);
  tmp_error(argv);
  if (option == 'd')
    {
      while (++i < argc)
	my_lsd(argv, i);
      my_putchar('\n');
      exit (0);
    }
  if (argc == 1 || (argc == 2 && option != 0))
    standard_input(dirp, option);
  else
    other_input(dirp, argc, option, argv);
  closedir(dirp);
  return (0);
}
