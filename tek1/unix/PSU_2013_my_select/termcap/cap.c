/*
** cap.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Jan 15 16:14:38 2014 Pierrick Gicquelais
** Last update Thu Jan 16 19:38:57 2014 Pierrick Gicquelais
*/

#include	"../select.h"

void		raw_attr(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t) == -1)
    my_error("Error with syscall tcsetattr");
}

void		canon_attr(struct termios *t)
{
  t->c_lflag |= ICANON;
  t->c_lflag |= ECHO;
  if (tcsetattr(0, TCSANOW, t) == -1)
    my_error("Error with syscall tcsetattr");
}
