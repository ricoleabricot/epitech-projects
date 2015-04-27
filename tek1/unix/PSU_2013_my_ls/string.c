/*
** string.c for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Nov 28 17:40:48 2013 Pierrick Gicquelais
** Last update Fri Nov 29 12:09:38 2013 Pierrick Gicquelais
*/

#include "my_ls.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  int	k;
  char	*str;

  i = 0;
  j = 0;
  k = 0;
  if ((str = malloc((my_strlen(src) + my_strlen(dest) + 2)	\
		    * sizeof(char))) == NULL)
    exit (0);
  while (dest[i])
    str[k++] = dest[i++];
  if (dest[i - 1] != '/')
    str[k++] = '/';
  while (src[j])
    str[k++] = src[j++];
  str[k] = '\0';
  return (str);
}

char    *my_time(char *str)
{
  int   i;
  int   cmp;

  i = 0;
  cmp = 0;
  while (str[i])
    {
      if (cmp == 2)
	str[i] = '\0';
      if (str[i + 1] == ':')
	cmp++;
      i++;
    }
  return (str);
}

void	maff_color(struct dirent *path, struct stat *buf)
{
  if (path->d_type == 4)
    my_my_putstr("\033[01;34m");
  else if (path->d_type == 10)
    my_my_putstr("\033[0;36m");
  else
    {
      if ((buf->st_mode & S_IXUSR) != 0)
	my_my_putstr("\033[0;32m");
      else
	my_my_putstr("\033[0;37m");
    }
}

void    maff_detailed(struct dirent *path, struct stat *buf, int i)
{
  struct passwd	*name;
  struct group	*group;
  char		*linkname;

  name = getpwuid(buf->st_uid);
  group = getgrgid(buf->st_gid);
  if (i == 1)
    {
      my_printf("%d %s\t%s\t%d  \t%s ", buf->st_nlink, name->pw_name,	\
		group->gr_name, buf->st_size, my_time(ctime(&buf->st_ctime)));
    }
  maff_color(path, buf);
  my_my_putstr(path->d_name);
  if (path->d_type == 10 && i == 1)
    {
      my_my_putstr("\033[0;37m -> ");
      linkname = malloc(buf->st_size + 1);
      readlink(path->d_name, linkname, buf->st_size);
      linkname[buf->st_size] = '\0';
      my_my_putstr(linkname);
      free(linkname);
    }
  else
    my_my_putstr("\033[0;37m");
  my_putchar('\n');
}
