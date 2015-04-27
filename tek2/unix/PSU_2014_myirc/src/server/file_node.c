/*
** file_node.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 12:23:08 2015 Pierrick Gicquelais
** Last update Sun Apr 12 21:59:19 2015 Pierrick Gicquelais
*/

#include	"file.h"

t_file		*first_file(t_file *file)
{
  if (file != NULL)
    while (file->prev != NULL)
      file = file->prev;
  return (file);
}

t_file		*last_file(t_file *file)
{
  if (file != NULL)
    while (file->next != NULL)
      file = file->next;
  return (file);
}

static t_file	*pop_element(t_file *files, t_file *tmp)
{
  if (files->prev == NULL && files->next != NULL)
    {
      files->next->prev = NULL;
      files = files->next;
    }
  else if (files->prev != NULL && files->next == NULL)
    {
      files->prev->next = NULL;
      files = files->prev;
    }
  else if (files->prev != NULL && files->next != NULL)
    {
      files->prev->next = tmp->next;
      files->next->prev = tmp->prev;
      files = files->prev;
    }
  else
    files = NULL;

  return (files);
}

t_file		*pop_file(t_file *files, char *from, char *to)
{
  t_file	*tmp;

  files = get_file_by_fromto(files, from, to);
  if (files != NULL)
    {
      tmp = files;
      files = pop_element(files, tmp);
      free_file(tmp);
    }
  return (first_file(files));
}
