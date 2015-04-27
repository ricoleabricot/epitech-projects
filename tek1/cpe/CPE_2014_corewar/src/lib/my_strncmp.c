/*
** my_strncmp.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Mon Mar 24 14:41:10 2014 Nicolas Ribeiro Teixeira
** Last update Mon Mar 24 14:41:11 2014 Nicolas Ribeiro Teixeira
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	a;

  a = 0;
  while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0' && a < (n - 1))
    a++;
  return (s1[a] - s2[a]);
}
