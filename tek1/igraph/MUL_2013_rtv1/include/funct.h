/*
** funct.h for rtv1 in /home/gicque_p/local/igraph/MUL_2014_rtv1/include
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Feb  7 09:32:53 2014 Pierrick Gicquelais
** Last update Fri Mar 14 14:35:49 2014 Pierrick Gicquelais
*/

#ifndef		FUNCT_H_
# define	FUNCT_H_

# include	<math.h>
# include	"mlx.h"
# include	"mlx_int.h"

t_vec		*init_oeil(t_vec *, int, int);
t_vec		*rotate_x(t_vec *, double);
t_vec		*rotate_y(t_vec *, double);
t_vec		*rotate_z(t_vec *, double);
int		my_lum(t_vec *, int);
int		my_pixel_put_to_image(t_rt *, int, int, int);
void		my_init(t_rt *);
void		init_mlx(t_ptr *, t_nb *);
void		my_hook(t_rt *);
void		my_free(t_rt *);
void		remplis_img(t_rt *);
void		my_inter_sphere(t_nb *, t_vec *, int);
void		my_inter_cylinder(t_nb *, t_vec *, int);
void		my_inter_cone(t_nb *, t_vec *, double);
void		my_inter_plan(t_nb *, t_vec *);
void		delta_sphere(t_nb *, double, double, double);
void		delta_cylinder(t_nb *, double, double, double);
void		delta_cone(t_nb *, double, double, double);
void		shadow_sphere(t_nb *, t_vec *, int);
void		shadow_cylinder(t_nb *, t_vec *, int);
void		shadow_cone(t_nb *, t_vec *, double);
void		shadow_plan(t_nb *, t_vec *);
void		vec_lum(t_nb *, t_vec *);
void		my_putstr(char *);
void		my_putnbr(int);
void		my_error(char *, int);

#endif		/* !FUNCT_H_ */
