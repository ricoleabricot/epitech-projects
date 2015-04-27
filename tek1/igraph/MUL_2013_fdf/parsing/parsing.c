/*
** parsing.c for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec  2 13:35:50 2013 Pierrick Gicquelais
** Last update Thu Jan  9 22:59:03 2014 Pierrick Gicquelais
*/

#include "../include/fdf.h"

t_list	*rev_list(t_list **list)
{
  t_list	*cur_elem;
  t_list	*prev_elem;
  t_list	*next_elem;

  cur_elem = *list;
  prev_elem = NULL;
  next_elem = NULL;
  while (cur_elem !=  NULL)
    {
      *list = cur_elem;
      prev_elem = cur_elem->next;
      cur_elem->next = next_elem;
      next_elem = cur_elem;
      cur_elem = prev_elem;
    }
  return (prev_elem);
}

void	proj_iso_list(t_list **list, t_dat *dat)
{
  t_list	*elem;
  static int	i = 0;

  if (i == 0)
    {
      dat->cte1 = 0.7;
      dat->cte2 = 0.7;
      dat->proj_x = 50;
      dat->proj_y = 50;
      dat->mid_x = 1680 / 2 - dat->save_line;
      dat->mid_y = 1000 / 2 - dat->j;
    }
  elem = *list;
  while (elem != NULL)
    {
      elem->X = ((dat->cte1 * (elem->x * dat->proj_x)) -		\
		 (dat->cte2 * (elem->y * dat->proj_y)) + dat->mid_x);
      elem->Y = ((elem->z * (-5)) + (dat->cte1 / 2) * (elem->x * (35)) + \
		 (dat->cte2 / 2) * (elem->y * dat->proj_y) + dat->mid_y);
      elem = elem->next;
    }
  i++;
}

void	fill_list(t_list **list, char **tab, int i, int j)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    exit (0);
  elem->x = i;
  elem->y = j;
  elem->z = my_getnbr(tab[i]);
  elem->next = *list;
  *list = elem;
}

t_list	*my_parsing(t_list **list, char **argv, t_dat *dat)
{
  char		**tab;
  char		*s;
  int		fd;

  dat->j = 0;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    exit(0);
  while ((s = get_next_line(fd)) != NULL)
    {
      dat->i = -1;
      tab = my_str_to_wordtab(s);
      if (dat->j == 0)
	dat->save_line = word_count(s) + 1;
      while (tab[++dat->i])
	  fill_list(list, tab, dat->i, dat->j);
      if (dat->i != dat->save_line)
	{
	  my_putstr("Wrong format of map. Must be a rectangle or square\n");
	  exit (0);
	}
      free(s);
      dat->j++;
    }
  close(fd);
  return (rev_list(list));
}
