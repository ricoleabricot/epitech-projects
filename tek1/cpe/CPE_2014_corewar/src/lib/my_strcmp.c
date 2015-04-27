/*
** my_strcmp.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/src/lib
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Tue Mar 25 10:47:55 2014 Christian Boisson
** Last update Wed Mar 26 09:19:32 2014 Christian Boisson
*/

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		dif;

  i = 0;
  dif = 0;
  while (dif == 0 && (s1[i] != '\0' || s2[i] != '\0'))
    {
      dif = s1[i] - s2[i];
      i++;
    }
  return (dif);
}
