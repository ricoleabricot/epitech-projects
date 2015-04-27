/*
** my_ls.h for my_ls in /home/gicque_p/local/unix/PSU_2013_my_ls
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Nov 25 16:47:33 2013 Pierrick Gicquelais
** Last update Fri Nov 29 14:06:18 2013 Pierrick Gicquelais
*/

#ifndef MY_LS_H_
#	define MY_LS_H_

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdarg.h>
#include	<dirent.h>
#include	<time.h>
#include	<pwd.h>
#include	<grp.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"myprintf.h"

void		my_ls(DIR *, char **, int, char);
void		my_ls_el(DIR *, char **, int);
void		my_ls_standard(DIR *, char);
void		my_ls_el_standard(DIR *);
void		my_lsd(char **, int);
char		check_options(char **);
char		*my_strcat(char *, char *);
void		tmp_error(char **);
void		standard_input(DIR *, char);
void		other_input(DIR *, int, char, char **);
void		maff_detailed(struct dirent *, struct stat *, int);
void		maff_color(struct dirent *, struct stat *);
void		rights(struct stat *, struct dirent *);
void		rights_file(struct dirent *);
void		rights_usr(struct stat *);
void		rights_grp(struct stat *);
void		rights_oth(struct stat *);

#endif /* !MY_LS_H_ */
