/*
** allum.h for allum in /home/gicque_p/local/cpe/CPE_2014_Allum1
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb  3 21:14:33 2014 Pierrick Gicquelais
** Last update Fri Feb 14 12:06:59 2014 Pierrick Gicquelais
*/

#ifndef		ALLUM_H_
# define	ALLUM_H_

# include	<term.h>
# include	<termios.h>

# define	BUF_SIZE (1)

typedef struct	s_var
{
  int		choice[4];
  int		line[4];
  char		*s1;
  char		*s2;
  char		*j1;
  char		*j2;
}		t_var;

char		*find_term(char **);
char		*get_next_line(int);
int		choose_all(t_var *, int, int, int);
int		up_key(char *, char *, int);
int		down_key(char *, char *, int);
int		intell_allum(t_var *, int);
int		marienbad(t_var *, int);
int		easy_marienbad(t_var *, int);
int		check_nb(t_var *, int *, int, int *);
int		check_nbr(int, int, int *);
int		my_getnbr(char *);
int		get_info(t_var *, char *, int);
int		my_putchar(int);
int		my_strlen(char *);
void		raw_attr(struct termios *);
void		canon_attr(struct termios *);
void		display_menu();
void		display_mod(t_var *);
void		display_pvp(t_var *);
void		display_difficulty(t_var *);
void		display_allum(int);
void		display_nim(int, int, int, int);
void		display_number(int);
void		display_nb(int, int, char *, char *);
void		display_success();
void		display_error();
void		my_choice();
void		launch_game(t_var *);
void		init_nim(t_var *);
void		algo_allum(t_var *);
void		algo_nim(t_var *);
void		pvp_allum(t_var *);
void		pvp_nim(t_var *);
void		ending_intell(t_var *, int);
void		end_game();
void		my_getnick(t_var *);
void		check_option(t_var *, int);
void		check_success(t_var *);
void		check_end(t_var *, int, char *);
void		useless_check(int, char **);
void		check_name(char *, char *);
void		my_putstr(char *);
void		my_putnbr(int);
void		my_error(char *);

#endif	/* !ALLUM_H_ */
