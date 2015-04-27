/*
** my_label_found.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Thu Mar 27 11:15:52 2014 Nicolas Ribeiro Teixeira
** Last update Wed Apr  9 16:29:25 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"op.h"
#include	"asm.h"

int		my_special_doublepoint_pos(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ':' && str[i] != '\0')
    i++;
  if (str[i] == ':')
    return (i);
  else
    return (-1);
}

int		my_get_doublepoint_pos(char *str)
{
  int		i;

  i = my_strlen(str) - 1;
  while ((str[i] == ' ' || str[i] == '\t') && i >= 0)
    i--;
  if (i > 0 && str[i] == LABEL_CHAR)
    return (i);
  return (-1);
}

char		**my_label_found(char **instruction,
				 int *label_nbr, char *line)
{
  (*label_nbr)++;
  if ((instruction = malloc(sizeof(char *) * 3)) == NULL)
    exit(0);
  instruction[0] = "label";
  instruction[1] = my_strdup(line);
  instruction[1][my_strlen(line) - 1] = '\0';
  instruction[2] = NULL;
  return (instruction);
}

char		**special_instruction(char *str, int line)
{
  char		**instruction;
  int		i;
  int		j;

  i = 0;
  j = -1;
  instruction = NULL;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    i++;
  if (str[i] != '\0')
    {
      while (op_tab[++j].mnemonique != NULL)
	{
	  if (my_strlncmp_nico(str, i, i + my_strlen(op_tab[j].mnemonique),
			       op_tab[j].mnemonique) == 0)
	    instruction = my_opcode_found(instruction, str, i, j);
	}
      if (instruction == NULL)
	my_error(0, NULL, line, NULL);
    }
  else
    my_error(0, NULL, line, NULL);
  return (instruction);
}

char		*my_cut_str(int dp, char *str)
{
  int		i;
  char		*new;

  if ((new = malloc(sizeof(char) * my_strlen(str) - dp)) == NULL)
    exit(0);
  i = 0;
  while (str[++dp])
    {
      new[i] = str[dp];
      i++;
    }
  new[i] = '\0';
  return (new);
}
