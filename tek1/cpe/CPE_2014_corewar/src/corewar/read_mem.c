/*
** read_memori.c for corewar in /home/boisso_c/rendu/CPE_2014_corewar/src/corewar
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Sat Apr 12 11:26:41 2014 Christian Boisson
** Last update Sat Apr 12 11:38:09 2014 Christian Boisson
*/

int		getmem(char *str, int i)
{
  int		nbr;
  if (i == 1)
    nbr = str[0];
  else if (i == 2)
    nbr = str[1] + 256 * str[0];
  else if (i == 4)
    nbr = str[3] + 256 * str[2] + 65536 * str[1] + \
      16777216 * str[0];
  return (nbr);
}
