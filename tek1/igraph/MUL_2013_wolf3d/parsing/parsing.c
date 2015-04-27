/*
** parsing.c for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Jan  7 11:57:03 2014 Pierrick Gicquelais
** Last update Sun Jan 12 22:24:45 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../include/wolf.h"

void		fill_tab(t_ptr *ptr, char *s, int j)
{
  int		i;
  int		k;

  i = 0;
  k = 0;
  if ((ptr->map[j] = malloc(my_strlen(s) * sizeof(char))) == NULL)
    my_error("Error with a memory allocation");
  while (s[i])
    {
      if (s[i] != ' ')
	{
	  ptr->map[j][k] = s[i];
	  k++;
	}
      i++;
    }
}

void		error_map(int line, int column)
{
  my_putstr("Error at line: ");
  my_putnbr(line + 1);
  my_putstr(" , column: ");
  my_putnbr(column + 1);
  my_putchar('\n');
  my_error("Wrong format of map. You must have a limit of walls");
}

void		check_map(char **map)
{
  int		i;

  if (MAP_LENGHT != MAP_WIDTH)
    my_error("The map must be a square");
  i = -1;
  while (++i < MAP_LENGHT)
    if (map[0][i] != '1')
      error_map(0, i);
  i = -1;
  while (++i < MAP_LENGHT)
    if (map[MAP_WIDTH - 1][i] != '1')
      error_map(MAP_WIDTH - 1, i);
  i = -1;
  while (++i < MAP_WIDTH)
    {
      if (map[i][0] != '1')
	error_map(i, 0);
      else if (map[i][MAP_LENGHT - 1] != '1')
	error_map(i, MAP_LENGHT - 1);
    }
}

void		my_parsing(t_ptr *ptr)
{
  int		fd;
  char		*s;
  int		j;

  j = 0;
  if ((fd = open("map_hard", O_RDONLY)) == 1)
    my_error("Error to open the map");
  if ((ptr->map = malloc(MAP_WIDTH * sizeof(char *))) == NULL)
    my_error("Error with a memory allocation");
  while ((s = get_next_line(fd)) != NULL)
    {
      fill_tab(ptr, s, j);
      j++;
      free(s);
    }
  close(fd);
  check_map(ptr->map);
}
