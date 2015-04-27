/*
** my_strlcmp.c for corewar in /home/boisso_c/Documents/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Mar 31 13:31:33 2014 Christian Boisson
** Last update Fri Apr 11 00:36:23 2014 Christian Boisson
*/

int		my_strlcmp(char *s1, char *s2, int j)
{
  int		i;
  int		dif;

  i = 0;
  dif = 0;
  while (dif == 0 && (s1[j] != '\0' || s2[i] != '\0'))
    {
      dif = s1[j] - s2[i];
      i++;
      j++;
    }
  return (dif);
}
