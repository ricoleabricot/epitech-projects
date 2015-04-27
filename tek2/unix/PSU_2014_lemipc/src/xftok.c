/*
** xftok.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 23:03:54 2015 Pierrick Gicquelais
** Last update Sat Feb 28 00:49:36 2015 Pierrick Gicquelais
*/

#include	"xftok.h"
#include	"error.h"

key_t		xftok(const char *path, int proj_id)
{
  key_t		key;

  if ((key = ftok(path, proj_id)) == -1)
    my_error("Ftok Error");
  return (key);
}

