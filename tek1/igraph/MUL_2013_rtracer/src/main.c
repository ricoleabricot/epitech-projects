/*
** main.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 16:34:15 2014 Pierrick Gicquelais
** Last update Wed May 14 08:16:49 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

int		main(int argc, char **argv)
{
  t_obj		*obj;

  obj = NULL;
  if (argc != 2)
    my_error("You must enter only a configuration file");
  obj = my_parsing(obj, argv[1]);
  aff_all_obj(obj);
  free_all_obj(obj);
  return (0);
}
