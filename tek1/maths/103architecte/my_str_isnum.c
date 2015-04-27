/*
** my_str_isnum.c for my_str_isnum in /home/gicque_p/piscine/piscine6
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Oct  8 17:44:06 2013 Pierrick Gicquelais
** Last update Thu Dec 12 00:58:12 2013 Pierrick Gicquelais
*/

int	my_str_isnum(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str == 0)
    return (1);
  if (str[i] == '-')
    i++;
  while (str[i] != '\0')
    {
      if (j > 1)
	return (0);
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
	  if (str[i] == '.')
	    j++;
	  i++;
	}
      else
	return (0);
    }
  return (1);
}
