/*
** file.h for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Sun Apr 12 12:29:25 2015 Pierrick Gicquelais
** Last update Sun Apr 12 18:42:37 2015 Pierrick Gicquelais
*/

#ifndef		FILE_H_
# define	FILE_H_

# include	"server.h"

t_file		*new_file(void);
t_file		*append_file(t_file *, char *, int);
t_file		*first_file(t_file *);
t_file		*last_file(t_file *);
t_file		*pop_file(t_file *, char *, char *);
t_file		*get_file_by_fromto(t_file *, char *, char *);
t_file		*get_file_by_fd(t_file *, int);

bool		file_exists(t_file *, char *);

void		free_file(t_file *);
void		free_files(t_file *);

#endif		/* !FILE_H_ */
