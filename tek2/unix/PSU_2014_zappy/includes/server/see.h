/*
** see.h for zappy in /home/boisso_c/rendu/PSU_2014_zappy/includes/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Mon Jun 29 16:33:09 2015 Christian Boisson
** Last update Thu Jul  2 14:20:15 2015 Christian Boisson
*/

#ifndef			SEE_H_
# define		SEE_H_

void			aply_dx(t_client *client, int *x, int dx);
void			aply_dy(t_client *client, int *y, int dy);
char			*print_line(char *str, char *tmp, int lvl, int cas);
char			*print_see(char *string, char *tmp, int lvl, int max_lvl);
void			get_resources(t_case *cas, char **str);
char			*get_case(t_client *client, t_case *cas, int lvl);
char			*get_line(t_server *s, t_client *client, int lvl, int cas);


#endif			/* !SEE_H_ */
