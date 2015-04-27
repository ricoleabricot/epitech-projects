/*
** check_open_getnames.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Wed Mar 26 09:21:24 2014 Nicolas Ribeiro Teixeira
** Last update Tue Apr  8 16:03:02 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	"asm.h"
#include	"lib.h"
#include	"op.h"

void		my_check_name(char *name, int len)
{
  int		i;

  i = len - 2;
  if (name[i] != '.')
    {
      my_putstr("Invalid champion file extension\n");
      exit(1);
    }
  else if (name[i + 1] != 's')
    {
      my_putstr("Invalid champion file extension\n");
      exit(1);
    }
}

int		my_open_and_free_filename(char *filename)
{
  int		fd;

  fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
  if (fd == -1)
    {
      my_putstr("Open syscall failed !\n");
      exit(2);
    }
  free(filename);
  return (fd);
}

int		my_get_champ_fd(char *name)
{
  int		len;
  int		i;
  int		k;
  char		*filename;

  i = 0;
  k = 0;
  len = my_strlen(name);
  if ((filename = malloc(sizeof(char) * (my_strlen(name) + 3))) == NULL)
    {
      my_putstr("Malloc failed\n");
      exit(1);
    }
  while (i < (len - 1))
    {
      filename[k] = name[i++];
      k++;
    }
  filename[k++] = 'c';
  filename[k++] = 'o';
  filename[k++] = 'r';
  filename[k] = '\0';
  return (my_open_and_free_filename(filename));
}

char		*my_get_name(int dotsfd, int *line_nbr, int k, int i)
{
  char		*s;
  char		*name;

  while ((s = my_one_get_next_line(dotsfd)) != NULL)
    {
      if (my_strncmp(s, NAME_CMD_STRING, 5) == 0)
	{
	  i = 5;
	  while (s[i] != '"')
	    i++;
	  k = i + 1;
	  i++;
	  while (s[k] != '"')
	    k++;
	  if ((name = malloc(sizeof(char) * (k - i + 1))) == NULL)
	    exit(0);
	  my_strlcat(name, i, k, s);
	  free(s);
	  *line_nbr = *line_nbr + 1;
	  return (name);
	}
      free(s);
      *line_nbr = *line_nbr + 1;
    }
  return (NULL);
}

char		*my_get_comment(int dotsfd, int *line_nbr, int k, int i)
{
  char		*s;
  char		*comment;

  while ((s = my_one_get_next_line(dotsfd)) != NULL)
    {
      if (my_strncmp(s, COMMENT_CMD_STRING, 8) == 0)
	{
	  i = 8;
	  while (s[i] != '"')
	    i++;
	  k = i + 1;
	  i++;
	  while (s[k] != '"')
	    k++;
	  if ((comment = malloc(sizeof(char) * (k - i + 1))) == NULL)
	    exit(0);
	  my_strlcat(comment, i, k, s);
	  free(s);
	  *line_nbr = *line_nbr + 1;
	  return (comment);
	}
      free(s);
      *line_nbr = *line_nbr + 1;
    }
  return (NULL);
}
