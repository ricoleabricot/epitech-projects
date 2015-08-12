/*
** list.h for zapy in /home/boisso_c/rendu/PSU_2014_zappy/includes/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 22 15:34:55 2015 Christian Boisson
** Last update Wed Jun 24 14:34:29 2015 Pierrick Gicquelais
*/

#ifndef			LIST_H_
# define		LIST_H_

typedef			struct s_list		t_list;

struct			s_list
{
  void			*data;
  struct s_list		*begin;
  struct s_list		*next;
  struct s_list		*prev;
};

t_list			*append_list(t_list *, void *);
t_list			*pop_list(t_list *, void *);
t_list			*delete_list(t_list *);
t_list			*begin_list(t_list *);
void			free_list(t_list *);
int			list_size(t_list *);

#endif			/* !LIST_H_ */
