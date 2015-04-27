/*
** my_strlen.c for my_strlen in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Wed Mar 26 09:10:12 2014 Nicolas Ribeiro Teixeira
** Last update Wed Mar 26 09:14:10 2014 Nicolas Ribeiro Teixeira
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
