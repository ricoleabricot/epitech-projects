/*
** my_strlcat.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Thu Mar 27 09:09:54 2014 Nicolas Ribeiro Teixeira
** Last update Thu Mar 27 09:17:04 2014 Nicolas Ribeiro Teixeira
*/

char		*my_strlcat(char *s1, int begin, int end, char *s2)
{
  int		k;

  k = 0;
  while (begin != end && s2[k] != '\0')
    {
      s1[k] = s2[begin];
      k = k + 1;
      begin++;
    }
  s1[k] = '\0';
  return (s1);
}
