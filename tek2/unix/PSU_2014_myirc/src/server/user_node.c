/*
** user_node.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc/src/server
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Apr  6 13:27:30 2015 Pierrick Gicquelais
** Last update Fri Apr 10 18:02:14 2015 Pierrick Gicquelais
*/

#include	"user.h"

t_user		*first_user(t_user *user)
{
  if (user != NULL)
    while (user->prev != NULL)
      user = user->prev;
  return (user);
}

t_user		*last_user(t_user *user)
{
  if (user != NULL)
    while (user->next != NULL)
      user = user->next;
  return (user);
}

static t_user	*pop_element(t_user *users, t_user *tmp)
{
  if (users->prev == NULL && users->next != NULL)
    {
      users->next->prev = NULL;
      users = users->next;
    }
  else if (users->prev != NULL && users->next == NULL)
    {
      users->prev->next = NULL;
      users = users->prev;
    }
  else if (users->prev != NULL && users->next != NULL)
    {
      users->prev->next = tmp->next;
      users->next->prev = tmp->prev;
      users = users->prev;
    }
  else
    users = NULL;

  return (users);
}

t_user		*pop_user(t_user *users, int fd)
{
  t_user	*tmp;

  users = get_user_by_fd(users, fd);

  if (users != NULL)
    {
      tmp = users;
      users = pop_element(users, tmp);
      free_user(tmp);
    }

  return (first_user(users));
}
