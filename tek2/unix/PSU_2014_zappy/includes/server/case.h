/*
** case.h for zappy in /home/boisso_c/rendu/PSU_2014_zappy
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 22 17:11:35 2015 Christian Boisson
** Last update Tue Jun 30 17:00:19 2015 Pierrick Gicquelais
*/

#ifndef			CASE_H_
# define		CASE_H_

# include		"resources.h"

typedef			struct s_case		t_case;

struct			s_case
{
  int			resources[7];
  t_list		*player;
};

void			clear_case(t_case *);
void			level_up(t_case *);

#endif			/* !CASE_H_ */
