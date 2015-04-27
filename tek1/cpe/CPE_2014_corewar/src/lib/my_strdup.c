/*
** my_strdup.c for asm|corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Wed Mar 26 13:26:30 2014 Nicolas Ribeiro Teixeira
** Last update Wed Mar 26 13:28:34 2014 Nicolas Ribeiro Teixeira
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strdup(char *src)
{
  int		len;
  char		*str;

  len = 0;
  while (src[len] != '\0')
    len++;
  str = malloc(sizeof(char) * (len + 1));
  str = my_strcpy(str, src);
  return (str);
}
