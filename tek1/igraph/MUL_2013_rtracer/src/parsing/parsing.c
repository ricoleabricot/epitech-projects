/*
** parsing.c for rt in /home/gicque_p/rendu/MUL_2013_rtracer/src/new_parsing
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 16:35:25 2014 Pierrick Gicquelais
** Last update Wed May 14 18:37:48 2014 Pierrick Gicquelais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"parsing.h"

t_tmp		*parse_str(t_tmp *tmp, char *s, int *cmp)
{
  char		*epur_s;
  char		*att;
  char		*val;
  int		i;

  epur_s = epur_str(s);
  att = my_strndup(epur_s, " \t", 0);
  i = get_val(epur_s);
  val = my_strndup(epur_s, " \t", i);
  check_val(val, *cmp);
  tmp = stock_val(tmp, att, val, *cmp);
  free_str(epur_s, att, val);
  return (tmp);
}

t_obj		*my_parsing(t_obj *obj, char *file)
{
  char		*s;
  char		*epur_s;
  int		fd;
  int		cmp;

  cmp = 1;
  if ((fd = open(file, O_RDONLY)) == -1)
    my_error("Can't open file");
  while ((s = get_next_line(fd)) != NULL)
    {
      epur_s = epur_str(s);
      if (s[0] && s[0] != COMMENT_CHAR)
	obj = stock_choice(obj, epur_s, fd, &cmp);
      free(epur_s);
      free(s);
      cmp++;
    }
  check_eye(obj);
  return (obj);
}
