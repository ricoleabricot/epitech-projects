/*
** algorithm.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Mar  8 16:46:11 2015 Pierrick Gicquelais
** Last update Sun Mar  8 18:06:30 2015 Pierrick Gicquelais
*/

#include	"algorithm.h"

int		find_nearest_center(int position)
{
  if (position <= (SHM_SIZE / 2) - (SHM_SIZE / 100))
    return (position + 100);
  else if (position >= (SHM_SIZE / 2) + (SHM_SIZE / 100))
    return (position - 100);
  else if (position <= (SHM_SIZE / 2))
    return (position + 1);
  return (position - 1);
}

int		find_nearest_ennemy(unsigned char *map, int id, int position)
{
  int		i;
  int		j;

  i = position;
  j = position;
  while (i > 0 && map[i] != id)
    i++;
  while (j < SHM_SIZE && map[i] != id)
    j++;

  if (i < j)
    return (i);
  return (j);
}

int		find_new_position(unsigned char *map, int id, int position)
{
  int	        ennemy;

  if (position <= ((SHM_SIZE / 2) - (SHM_SIZE / 10)) || \
      position >= ((SHM_SIZE / 2) + (SHM_SIZE / 10)))
    return (find_nearest_center(position));
  else
    {
      ennemy = find_nearest_ennemy(map, id, position);
      if (ennemy >= (position + (SHM_SIZE / 100)))
	return ((position + (SHM_SIZE / 100)) % SHM_SIZE);
      else if (ennemy <= (position - (SHM_SIZE / 100)))
	return ((position - (SHM_SIZE / 100)) % SHM_SIZE);
      else if (ennemy >= (position - (SHM_SIZE / 100)) && ennemy < position)
	return ((position - 1) % SHM_SIZE);
      else
	return ((position + 1) % SHM_SIZE);
    }
}
