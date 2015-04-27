/*
** my_one_get_next_line.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/lib
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Mon Mar 24 14:42:10 2014 Nicolas Ribeiro Teixeira
** Last update Mon Mar 24 14:45:46 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"asm.h"
#include	"lib.h"

t_gnl		*my_append_gnl(t_gnl *res, char *buffer)
{
  t_gnl		*new_element;
  t_gnl		*tmp;

  if ((new_element = malloc(sizeof(t_gnl))) == NULL)
    exit(0);
  new_element->letter = buffer[0];
  new_element->next = NULL;
  if (res == NULL)
    return (new_element);
  tmp = res;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_element;
  return (res);
}

char		*my_list_to_str(t_gnl *list)
{
  t_gnl		*tmp;
  int		i;
  char		*result;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  if ((result = malloc(sizeof(char) * i + 1)) == NULL)
    exit(0);
  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      result[i] = tmp->letter;
      i++;
      tmp = tmp->next;
    }
  result[i] = 0;
  return (result);
}

char		*my_one_get_next_line(const int fd)
{
  char		buffer[2];
  t_gnl		*res;
  int		status;

  res = NULL;
  buffer[0] = 0;
  buffer[1] = 0;
  status = 0;
  while (status != 1 && (read(fd, buffer, 1)) > 0)
    {
      if (buffer[0] == '\n')
	status = 1;
      else
	res = my_append_gnl(res, buffer);
    }
  if (res == NULL && buffer[0] != '\n')
    return (NULL);
  return (my_list_to_str(res));
}
