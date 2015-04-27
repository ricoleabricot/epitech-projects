/*
** xmalloc.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Mar 16 17:16:28 2015 Pierrick Gicquelais
** Last update Mon Mar 16 17:21:52 2015 Pierrick Gicquelais
*/

#include	"xmalloc.h"
#include	"merror.h"

void		*xmalloc(size_t size)
{
  void		*ret;

  if ((ret = malloc(size)) == NULL)
    merror("Malloc Error");
  return (ret);
}
