/*
** select.h for my_select in /home/gicque_p/local/unix/PSU_2013_my_select
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Jan 13 14:24:57 2014 Pierrick Gicquelais
** Last update Tue Feb  4 22:31:26 2014 Pierrick Gicquelais
*/

#ifndef		SELECT_H_
# define	SELECT_H_

# include	<curses.h>
# include	<term.h>
# include	<termios.h>

typedef struct	s_node
{
  int		back;
  char		*choice;
  struct s_node	*prev;
  struct s_node	*next;
}		t_node;

typedef struct	s_list
{
  struct s_node	*head;
  struct s_node	*tail;
}		t_list;

struct termios	*init_termios();
t_list		*init_list();
t_node		*init_node();
t_node		*down_key(t_node *, int *);
t_node		*up_key(t_node *, int *);
char		*find_term(char **);
int		my_putchar(int);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
void		aff_arg(t_list *, int, char **);
void		raw_attr(struct termios *);
void		canon_attr(struct termios *);
void		my_choice(struct termios *, t_list *, t_list *);
void		append_list(t_list *, char *);
void		delete_list(t_list *, char *);
void		aff_list(t_list *);
void		my_putstr(char *);
void		my_putstr_final(char *);
void		my_put_spec_str(char *, int);
void		my_error(char *);
void		space_key(t_list *, t_node *);
void		enter_key(struct termios *, t_list *);
void		echap_key(struct termios *);

#endif /* !SELECT_H_ */
