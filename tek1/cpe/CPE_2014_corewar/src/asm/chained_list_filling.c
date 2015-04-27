/*
** chained_list_filling.c for asm in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
**
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
**
** Started on Thu Mar 27 10:23:49 2014 Nicolas Ribeiro Teixeira
** Last update Wed Apr  9 16:18:10 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"lib.h"
#include	"op.h"

char		*my_add_arg(char *line, int i, int j)
{
  char		*param;
  int		counter;

  if ((param = malloc(sizeof(char) * ((j - i) + 1))) == NULL)
    exit(0);
  counter = 0;
  while (i != j)
    param[counter++] = line[i++];
  param[counter] = '\0';
  return (param);
}

char		**get_instruction_params(char **instruction, int i, \
					 op_t op, char *line)
{
  int		arg;
  int		j;

  arg = 0;
  while (arg != op.nbr_args)
    {
      while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
	i++;
      while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0'
	     && line[i - 1] != SEPARATOR_CHAR)
	i++;
      while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
	i++;
      j = i;
      while (line[j] != SEPARATOR_CHAR && line[j] != '\0')
	j++;
      if ((j - i) > 0)
	instruction[arg + 2] = my_add_arg(line, i, j);
      else
      	my_error(6, "Invalid argument number", 0, line);
      i = j;
      arg++;
    }
  instruction[arg + 2] = NULL;
  return (instruction);
}

char		**my_opcode_found(char **instruction, char *str,
					  int i, int j)
{
  if ((instruction = malloc(sizeof(char *) *
			    (op_tab[j].nbr_args + 3))) == NULL)
    exit(0);
  instruction[0] = my_strdup(op_tab[j].mnemonique);
  if ((instruction[1] = malloc(sizeof(char) * 2)) == NULL)
    exit(0);
  instruction[1][0] = op_tab[j].nbr_args + 48;
  instruction[1][1] = '\0';
  instruction = get_instruction_params(instruction, i, op_tab[j], str);
  return (instruction);
}

char		**create_instruction(char *str, int *label_nbr,
					     int line_nbr, int j)
{
  char		**instruction;
  int		i;
  int		dp;

  i = 0;
  instruction = NULL;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    i++;
  if (str[i] != '\0')
    {
      if ((dp = my_get_doublepoint_pos(str)) != -1)
	instruction = my_label_found(instruction, label_nbr, str);
      else
	while (op_tab[++j].mnemonique != NULL)
	  {
	    if (my_strlncmp_nico(str, i, i + my_strlen(op_tab[j].mnemonique),
				 op_tab[j].mnemonique) == 0)
	      instruction = my_opcode_found(instruction, str, i, j);
	  }
      if (instruction == NULL)
	my_error(0, NULL, line_nbr, NULL);
    }
  else
    my_error(0, NULL, line_nbr, NULL);
  return (instruction);
}

t_list		*my_append_instruction(t_list *begin, char *str,
				       int *label_nbr, int line_nbr)
{
  t_list	*new_element;
  t_list	*tmp;
  char		**args;

  if ((new_element = malloc(sizeof(t_list))) == NULL)
    exit(0);
  args = create_instruction(str, label_nbr, line_nbr, -1);
  new_element->args = args;
  new_element->argnbr = (args == NULL) ? 0 : my_getnbr(args[1]);
  new_element->line = line_nbr;
  new_element->octet = 0;
  new_element->next = NULL;
  if (begin == NULL)
    return (new_element);
  tmp = begin;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_element;
  return (begin);
}
