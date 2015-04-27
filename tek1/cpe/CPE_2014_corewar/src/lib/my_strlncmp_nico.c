/*
** my_strlcmp.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Wed Mar 26 12:08:25 2014 Nicolas Ribeiro Teixeira
** Last update Tue Apr  1 12:50:50 2014 Nicolas Ribeiro Teixeira
*/

int		my_strlncmp_nico(char *s1, int i, int j, char *s2)
{
  int		k;

  k = 0;
  while (s1[i] == s2[k] && i != j && s1[i] != '\0')
    {
      i++;
      k++;
    }
  if (s2[k] == '\0' && s1[i] != '\0' && (s1[i] == ' ' || s1[i] == '\t'))
    return (0);
  return (s1[i] - s2[k]);
}
