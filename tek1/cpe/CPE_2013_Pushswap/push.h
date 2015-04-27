/*
** push.h for pushswap in /home/gicque_p/local/cpe/CPE_2013_Pushswap
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Dec 16 13:11:01 2013 Pierrick Gicquelais
** Last update Mon Jan  6 22:32:18 2014 Pierrick Gicquelais
*/

#ifndef		PUSH_H_
# define	PUSH_H_

# include	<unistd.h>
# include	<stdlib.h>

typedef struct	s_node
{
  int		nb;
  struct s_node	*next;
}		t_node;

typedef struct	s_list
{
  struct s_node	*head;
  struct s_node	*tail;
}		t_list;

t_list		*init_list();
t_node		*init_node();
void		append_list(t_list *, int);
void		push_list(t_list *, int);
void		swap_list(t_list *);
void		rotate_list(t_list *);
void		pop_list(t_list *);
void		sort_a(t_list *, t_list *, int);
void		sort_a_inverse(t_list *, t_list *, int);
void		sort_b(t_list *, t_list *, int);
void		sort_b_inverse(t_list *, t_list *, int);
void		aff_list(t_list *);
void		my_putchar(char);
void		my_putstr(char *);
void		my_putnbr(int);
void		my_error(char *);
void		aff_option(t_list *, t_list *);
int		sort_list(t_list *, t_list *, char **);
int		sort_list_inverse(t_list *, t_list *, char **);
int		list_count(t_list *);
int		first_sort(int, char **);
int		my_strcmp(char *, char *);
int		my_getnbr(char *);

#endif		/* !PUSH_H_ */
