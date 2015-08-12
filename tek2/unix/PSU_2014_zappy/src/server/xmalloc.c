/*
** xmalloc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 09:47:04 2015 Pierrick Gicquelais
** Last update Thu Jun 18 09:56:10 2015 Pierrick Gicquelais
*/

#include	"server/xmalloc.h"

void		*xmalloc(size_t size)
{
  void		*ret;

  if ((ret = malloc(size)) == NULL)
    merror("Malloc Error");
  return (ret);
}
