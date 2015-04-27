/*
** struct.h for rvt1 in /home/gicque_p/local/igraph/MUL_2013_rtv1/include
**
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
**
** Started on  Fri Mar 14 09:29:36 2014 Pierrick Gicquelais
** Last update Wed May 14 16:01:19 2014 Pierrick Gicquelais
*/

#ifndef		STRUCT_H_
# define	STRUCT_H_

typedef struct	s_ptr
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
}		t_ptr;

typedef struct	s_nb
{
  int		bpp;
  int		sizeline;
  int		endian;
  int		color;
  double	k;
}		t_nb;

typedef struct	s_vec
{
  double	vx;
  double	vy;
  double	vz;
  double	px;
  double	py;
  double	pz;
  double	lx;
  double	ly;
  double	lz;
  double	sx;
  double	sy;
  double	sz;
}		t_vec;

typedef struct	s_rt
{
  t_ptr		*ptr;
  t_nb		*nb;
  t_vec		*vec;
}		t_rt;

#endif		/* !STRUCT_H_ */
