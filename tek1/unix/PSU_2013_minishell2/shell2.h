/*
** shell2.h for mysh2 in /home/gicque_p/local/unix/PSU_2013_minishell2
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Tue Feb 25 14:58:17 2014 Pierrick Gicquelais
** Last update Thu Mar  6 14:08:31 2014 Pierrick Gicquelais
*/

#ifndef		MYSH2_H_
# define	MYSH2_H_

# include	<stdarg.h>
# define	BUF_SIZE (1)

typedef struct	s_node
{
  char		*env;
  struct s_node	*next;
  struct s_node	*prev;
}		t_node;

typedef struct	s_list
{
  int		count;
  struct s_node	*head;
  struct s_node	*tail;
}		t_list;

t_list		*init_list();
t_node		*init_node();
char		**env_cpy(t_list *);
char		**my_str_to_wordtab(char *, int *);
char		**my_env_to_wordtab(char *);
char		**my_file_malloc(char *);
char		*get_next_line(int);
char		*my_strcat(char *, char *);
char		*my_strlcpy(char *, int);
char		*my_strdup(char *, int);
char		*epur_str(char *);
int		my_execution(char *, char **, char **);
int		check_recurs(t_list *, char *, char **, int);
int		check_redir(char *, char **, char **, int);
int		check_env(char **, char **);
int		check_cd(char **);
int		my_printf(const char *, ...);
int		my_putchar(char);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_getnbr(char *);
int		my_builtin(t_list *, char *, char **, char **);
void		append_list(t_list *, char *);
void		delete_list(t_list *, char *, int);
void		parent_process(t_list *, char **);
void		child_process(char *, char **, char **);
void		my_cmd(t_list *, char *, char **, int);
void		my_fork(char *, char **, char **);
void		my_cd(char **, char **);
void		my_env(t_list *, char **);
void		my_setenv(t_list *, char **);
void		my_unsetenv(t_list *, char **);
int		redir_right(char *, char **, char **, char *);
int		redir_do_right(char *, char **, char **, char *);
int		redir_left(char *, char **, char *);
int		redir_do_left(char *, char **, char **, char *);
int		my_pipe(char *, char **, char **, char *);
void		my_free(t_list *, char *, char **, char **);
void		my_eof_free(t_list *, char *, char **);
void		my_mini_free(char *, char **);
void		my_free_env(char **);
void		my_putstr(char *);
void		enhanced_puts(char *);
void		my_error(char *, int);

#endif		/* !MYSH2_H_ */
