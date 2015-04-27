/*
** my_ls.c for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Nov 26 11:34:57 2013 Pierrick Gicquelais
** Last update Fri Nov 29 14:27:46 2013 Pierrick Gicquelais
*/

#include <string.h>
#include "my_ls.h"

void	my_ls(DIR *dirp, char **argv, int i, char option)
{
  struct dirent	*path;
  struct stat	buf;
  char		*str;

  my_printf("%s :\n", argv[i]);
  while ((path = readdir(dirp)) != NULL)
    {
      if (option != 'a')
	{
	  if (path->d_name[0] != '.')
	    {
	      str = my_strcat(argv[i], path->d_name);
	      lstat(str, &buf);
	      free(str);
	      maff_detailed(path, &buf, 0);
	    }
	}
      else
	{
	  str = my_strcat(argv[i], path->d_name);
	  lstat(str, &buf);
	  free(str);
	  maff_detailed(path, &buf, 0);
	}
    }
}

void	my_ls_el(DIR *dirp, char **argv, int i)
{
  struct dirent	*path;
  struct stat	buf;
  unsigned int	byte;
  char		*str;

  my_printf("%s :\n", argv[i]);
  while ((path = readdir(dirp)) != NULL)
    {
      if (path->d_name[0] != '.')
	{
	  str = my_strcat(argv[i], path->d_name);
	  lstat(str, &buf);
	  free(str);
	  rights(&buf, path);
	  my_putchar(' ');
	  maff_detailed(path, &buf, 1);
	  byte = byte + (buf.st_size);
	}
    }
  closedir(dirp);
  printf("total : %d \n\n", byte / 2000);
}

void	my_ls_standard(DIR *dirp, char option)
{
  struct dirent	*path;
  struct stat	buf;

  while ((path = readdir(dirp)) != NULL)
    {
      if (option != 'a')
	{
	  if (path->d_name[0] != '.')
	    {
	      lstat(path->d_name, &buf);
	      maff_detailed(path, &buf, 0);
	    }
	}
      else
	{
	  lstat(path->d_name, &buf);
	  maff_detailed(path, &buf, 0);
	}
    }
  closedir(dirp);
}

void	my_ls_el_standard(DIR *dirp)
{
  struct dirent	*path;
  struct stat	buf;
  int		byte;

  while ((path = readdir(dirp)) != NULL)
    {
      if (path->d_name[0] != '.')
	{
	  lstat(path->d_name, &buf);
	  rights(&buf, path);
	  my_putchar(' ');
	  maff_detailed(path, &buf, 1);
	  byte = byte + (buf.st_blocks);
	}
    }
  closedir(dirp);
  printf("total : %d \n", byte / 512);
}

void	my_lsd(char **argv, int i)
{
  struct stat	buf;

  if (argv[i])
    {
      lstat(argv[i], &buf);
      if ((buf.st_mode & S_IFREG) == 0)
        my_my_putstr("\033[0;37m");
      if ((buf.st_mode & S_IFDIR && S_IXUSR) == 0)
	my_my_putstr("\033[0;32m");
      if ((buf.st_mode & S_IFLNK) == 0)
	my_my_putstr("\033[01;34m");
      if ((buf.st_mode & S_IXUSR) == 0)
	my_my_putstr("\033[0;37m");
      my_my_putstr(argv[i]);
      my_my_putstr("\033[0;37m");
      my_putchar(' ');
    }
}
