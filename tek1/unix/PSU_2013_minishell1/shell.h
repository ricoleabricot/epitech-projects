/*
** shell.h for mysh in /home/gicque_p/local/unix/PSU_2013_minishell1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed Dec 11 14:42:22 2013 Pierrick Gicquelais
** Last update Sat Dec 21 16:48:20 2013 Pierrick Gicquelais
*/

#ifndef		SHELL_H_
# define	SHELL_H_

# include	<sys/wait.h>
# include	<sys/time.h>
# include	<signal.h>
# include	<stdlib.h>
# include	<unistd.h>

# define	BUF_SIZE (1)

char		**my_str_to_wordtab(char *);
char		**my_env_to_wordtab(char *);
char		**my_env(char **);
char		*get_next_line(int);
char		*my_strcat(char *, char *);
int		word_count(char *);
int		env_count(char *);
int		word_len(char *);
int		env_len(char *);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
void		parent_process(char **);
void		child_process(char *, char **, char **);
void		my_execution(char **, char **);
void		my_builtin(char *, char **);
void		my_alias(char *, char **, char **);
void		my_cd(char *, char **, char **);
void		my_opt_cd(char **, char **, int, int);
void		my_putchar(char);
void		my_putstr(char *);
void		my_error(char *);
void		my_spec_error(char *);

#endif /*!SHELL_H_ */
