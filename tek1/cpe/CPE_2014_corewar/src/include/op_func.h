/*
** op_func.h for corewar in /home/ribeir_b/rendu/B2/B02_C_Prog_Elem/Corewar/CPE_2014_corewar/src/corewar
** 
** Made by Nicolas Ribeiro Teixeira
** Login   <ribeir_b@epitech.net>
** 
** Started on Thu Apr 10 12:45:29 2014 Nicolas Ribeiro Teixeira
** Last update Fri Apr 11 19:52:45 2014 Pierrick Gicquelais
*/

#ifndef		OP_FUNC_H_
# define	OP_FUNC_H_

int		my_void(t_vm *, t_champ *);
int		my_live(t_vm *, t_champ *);
int		my_ld(t_vm *, t_champ *);
int		my_st(t_vm *, t_champ *);
int		my_add(t_vm *, t_champ *);
int		my_sub(t_vm *, t_champ *);
int		my_and(t_vm *, t_champ *);
int		my_or(t_vm *, t_champ *);
int		my_xor(t_vm *, t_champ *);
int		my_zjmp(t_vm *, t_champ *);
int		my_ldi(t_vm *, t_champ *);
int		my_sti(t_vm *, t_champ *);
int		my_fork(t_vm *, t_champ *);
int		my_lld(t_vm *, t_champ *);
int		my_lldi(t_vm *, t_champ *);
int		my_lfork(t_vm *, t_champ *);
int		my_aff(t_vm *, t_champ *);

#endif		/* !OP_FUNC_H_ */
