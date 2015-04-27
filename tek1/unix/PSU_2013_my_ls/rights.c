/*
** rights.c for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Nov 27 14:18:10 2013 Pierrick Gicquelais
** Last update Fri Nov 29 14:05:28 2013 Pierrick Gicquelais
*/

#include "my_ls.h"

void	rights_file(struct dirent *path)
{
      if ((path->d_type) == 4)
	  my_putchar('d');
      else if (path->d_type == 0)
	my_putchar('s');
      else if (path->d_type == 10)
	  my_putchar('l');
      else
	my_putchar('-');
}

void	rights_usr(struct stat *buf)
{
      if ((buf->st_mode & S_IRUSR) != 0)
	my_putchar('r');
      else
	my_putchar('-');
      if ((buf->st_mode & S_IWUSR) != 0)
	my_putchar('w');
      else
	my_putchar('-');
      if ((buf->st_mode & S_IXUSR) != 0)
	my_putchar('x');
      else
	my_putchar('-');
}

void	rights_grp(struct stat *buf)
{
      if ((buf->st_mode & S_IRGRP) != 0)
	my_putchar('r');
      else
	my_putchar('-');
      if ((buf->st_mode & S_IWGRP) != 0)
	my_putchar('w');
      else
	my_putchar('-');
      if ((buf->st_mode & S_IXGRP) != 0)
	my_putchar('x');
      else
	my_putchar('-');
}

void	rights_oth(struct stat *buf)
{
      if ((buf->st_mode & S_IROTH) != 0)
	my_putchar('r');
      else
	my_putchar('-');
      if ((buf->st_mode & S_IWOTH) != 0)
	my_putchar('w');
      else
	my_putchar('-');
      if ((buf->st_mode & S_IXOTH) != 0)
	my_putchar('x');
      else
	my_putchar('-');
}

void	rights(struct stat *buf, struct dirent *path)
{
  rights_file(path);
  rights_usr(buf);
  rights_grp(buf);
  rights_oth(buf);
}
