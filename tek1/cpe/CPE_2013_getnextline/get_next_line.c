/*
** get_next_line.c for get_next_line.c in /home/remy_o/rendu/GetNextLine
** 
** Made by Olivier Remy
** Login   <remy_o@epitech.net>
** 
** Started on  Mon Nov 18 17:05:38 2013 Olivier Remy
** Last update Mon Nov 25 14:53:42 2013 Olivier Remy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFF_SIZE (1)
# define PUT_LINE (0)

int		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		n;

  n = -1;
  while (str[++n])
    my_putchar(str[n]);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_realloc(char *str, int n)
{
  char		*ptr;
  int		i;

  i = 0;
  ptr = malloc(sizeof(char) * (n + 1));
  ptr[n + 1] = '\0';
  while (str[i] != '\0')
    {
      ptr[i] = str[i];
      i++;
    }
  free(str);
  return (ptr);
}

int		my_put_line(const int fd, char *buff, int red)
{
  int		l;

  l = 1;
  while (l != PUT_LINE)
    {
      while (buff[0] != '\n')
	red = read(fd, buff, BUFF_SIZE);
      l++;
      if (l != PUT_LINE)
	red = read(fd, buff, BUFF_SIZE);
    }
  return (red);
}

char		*get_next_line(const int fd)
{
  int		i;
  int		n;
  int		red;
  static char	buff[BUFF_SIZE + 1];
  char		*ptr;

  if (PUT_LINE > 0)
    red = my_put_line(fd, buff, red);
  ptr = malloc(sizeof(char));
  n = 1;
  i = 0;
  while ((red = read(fd, buff, BUFF_SIZE)) > 0)
    {
      ptr = my_realloc(ptr, n);
      ptr[i] = buff[0];
      i++;
      n++;
      printf("%d\n", red);
    }
  close(fd);
  return (ptr);
}

int		main(int argc, char **argv)
{
  char		*s;
  int		fd;

  if (argc == 2)
    {
      fd = open(argv[1], O_RDONLY);
      s = get_next_line(fd);
      my_putstr(s);
      my_putchar('\n');
    }
  else
    my_putstr("Nombre d'arguments incorrect\n");
}
