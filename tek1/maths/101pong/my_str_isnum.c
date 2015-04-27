/*
** my_str_isnum.c for my_str_isnum in /home/gicque_p/piscine/piscine6
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Oct  8 17:44:06 2013 Pierrick Gicquelais
** Last update Thu Nov 14 14:49:06 2013 Pierrick Gicquelais
*/

int	my_str_isnum(char *str)
{
  int	i;
  
  i = 0;
  if (str[0] == '-')
    i++;
  if (str == 0)
    return (1);
  else
    {
      while (str[i] != '\0')
	{
	  if (str[i] >= '0' && str[i] <= '9')
	    i++;
	  else
	    return (0);
	}
      return (1);
    }
}
