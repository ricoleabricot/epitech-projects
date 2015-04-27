/*
** choice.c for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jan 16 19:33:05 2014 Pierrick Gicquelais
** Last update Sun Jan 19 22:09:42 2014 Pierrick Gicquelais
*/

#include	<signal.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"../select.h"

void		get_winsize()
{
  int		width;
  int		height;

  width = tgetnum("co");
  height = tgetnum("li");
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  if (height < 500 || width < 500)
    my_putstr("Winsize too small !\n");
}

void		aff_screen(t_node *node, int i)
{
  tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, my_putchar);
  if (node->back == 0)
    tputs(tgetstr("us", NULL), 1, my_putchar);
  else
    tputs(tgetstr("mr", NULL), 1, my_putchar);
  my_putstr(node->choice);
  tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, my_putchar);
}

void		my_boucle(struct termios *t, t_list *list_final, t_node *node)
{
  char		buf[126];
  int		size;
  int		i;

  i = 0;
  while ((size = read(0, buf, 3)) != 0)
    {
      signal(SIGWINCH, &get_winsize);
      if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66  \
	  && node->next && size == 3)
	node = down_key(node, &i);
      else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65     \
	       && node->prev && size == 3)
	node = up_key(node, &i);
      else if (buf[0] == 32 && size == 1)
	space_key(list_final, node);
      else if (buf[0] == 10 && size == 1)
	enter_key(t, list_final);
      else if (buf[0] == 27 && size == 1)
	echap_key(t);
      aff_screen(node, i);
    }
}

void		my_choice(struct termios *t, t_list *list, t_list *list_final)
{
  t_node	*node;

  node = init_node();
  node = list->head;
  my_boucle(t, list_final, node);
}
