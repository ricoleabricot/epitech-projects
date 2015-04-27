/*
** my_check_empty_str.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Thu Mar 27 10:27:42 2014 Nicolas Ribeiro Teixeira
** Last update Wed Apr  9 14:52:57 2014 Nicolas Ribeiro Teixeira
*/

int		empty_str(char *str)
{
  int		i;

  i = 0;
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  if (str[i] == '\0')
    return (0);
  return (1);
}
