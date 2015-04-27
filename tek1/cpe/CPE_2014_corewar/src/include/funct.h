/*
** lib.h for vm in /home/gicque_p/rendu/CPE_2014_corewar/Kafei
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Thu Mar 20 10:12:34 2014 Pierrick Gicquelais
** Last update Mon Apr 14 13:24:12 2014 Pierrick Gicquelais
*/

#ifndef		__FUNCT_H_
# define	__FUNCT_H_

# include	<stdarg.h>
# include	"struct.h"

extern op_t	op_tab[];

t_champ		*my_append_to_champ(t_champ *, int);
char		*my_strcpy(char *, char *);
int		check_dump(t_vm *, char **);
int		check_champ(t_vm *, int, char **, int);
int		check_live(t_vm *);
int		corewar(t_vm *);
int		my_parsing(t_vm *, int, char **, int);
int		reverse_bit(int);
int		rev_ind(int);
int		get_int(int, unsigned char[], int);
int		fill_no_coding(unsigned char[], int, t_champ *);
int		try_opcode(int);
int		try_coding(unsigned char [], int, t_champ *, int);
int		try_p_ind(unsigned char[], t_champ *, int, int);
int		try_param(unsigned char[], t_champ *, int, int);
int		my_putchar(char);
int		my_getnbr(char *);
int		my_strncmp(char *, char *, int);
int		my_strlcmp(char *, char *, int);
int		check_champ_lives(t_vm *);
int		my_strlen(char *);
int		getmem(char *, int);
void		init_mlx(t_vm *);
void		init_arena(unsigned char[], int);
void		init_reg(t_champ *, t_info *);
void		init_champs(t_vm *);
void		init_pc(t_vm *);
void		game(t_vm *, int (*[])(t_vm *, t_champ *), int , int);
void		check_arg(int);
void		found_instruc(t_vm *, t_champ *);
void		fill_instru(int, char, t_champ *, int);
void		fill_param(t_champ *, unsigned char[], int, int);
void		exec_proc(t_vm *, t_champ *, int (*[17])(t_vm *, t_champ *));
void		write_arena(int, unsigned char[], int);
void		dump_arena(t_vm *);
void		free_list(t_champ *);
void		my_putstr(char *);
void		my_putnbr(int);
void		my_printf(const char *, ...);
void		my_print_error(const char *, ...);
void		my_error(char *, int);
void		my_show_alive_champions(t_vm *);
void		my_hook(t_vm *);
void		aff_grid(t_vm *);
void		my_fill_image(t_vm *);

#endif		/* !__FUNCT_H_ */
