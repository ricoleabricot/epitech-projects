/*
** option.c for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Nov 28 14:57:46 2013 Pierrick Gicquelais
** Last update Fri Nov 29 14:28:11 2013 Pierrick Gicquelais
*/

#include "my_ls.h"

void	tmp_error(char **argv)
{
  if (argv[2])
    if (argv[2][0] == '-')
    {
      my_printf("You can for now only use one option for my_ls.\n");
      exit (0);
    }
}

char	check_options(char **argv)
{
  int	i;

  i = 1;
  if (argv[i])
    while (argv[i][0] == '-')
      {
 	if (argv[i][0] == '-')
	  {
	    if (argv[i][1] == 'l' && argv[i][2] == '\0')
	      return ('l');
	    else if (argv[i][1] == 'a' && argv[i][2] == '\0')
	      return ('a');
	    else if (argv[i][1] == 'd' && argv[i][2] == '\0')
	      return ('d');
	    else if (argv[i][1] == '-' && argv[i][2] == '\0')
	      return (1);
	    else
	      {
		my_printf("Wrong option. You can for now use only : -l, -d or -a.\n");
		exit(0);
	      }
	  }
	i++;
      }
  return (0);
}

void	standard_input(DIR *dirp, char option)
{
  if ((dirp = opendir(".")) == NULL)
    exit (0);
  if (option == 'l')
    my_ls_el_standard(dirp);
  else
    my_ls_standard(dirp, option);
}

void    other_input(DIR *dirp, int argc, char option, char **argv)
{
  int   i;

  i = 1;
  while (i < argc)
    {
      if (argv[i][0] != '-')
        {
          if ((dirp = opendir(argv[i])) != NULL)
            {
              if (option == 'l')
                my_ls_el(dirp, argv, i);
              else
		{
		  my_ls(dirp, argv, i, option);
		  my_putchar('\n');
		  closedir(dirp);
		}
            }
          else
            my_printf("ls: cannot access %s: Not a directory\n", argv[i]);
          i++;
        }
      else
        i++;
    }
}
