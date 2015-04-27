/*
** parsing.h for rt in /home/gicque_p/rendu/MUL_2013_rtracer/include
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 14:31:27 2014 Pierrick Gicquelais
** Last update Wed May 14 18:41:23 2014 Pierrick Gicquelais
*/

#ifndef		PARSING_H_
# define	PARSING_H_

# define	EYE		("<EYE>")
# define	SPHERE		("<SPHERE>")
# define	CYL		("<CYLINDER>")
# define	CONE		("<CONE>")
# define	PLAN		("<PLAN>")
# define	SPOT		("<SPOT>")
# define	X		("X:")
# define	Y		("Y:")
# define	Z		("Z:")
# define	ROT_X		("ROT_X:")
# define	ROT_Y		("ROT_Y:")
# define	ROT_Z		("ROT_Z:")
# define	ANGLE		("ANGLE:")
# define	COLOR		("COLOR:")
# define	COMMENT_CHAR	('#')

typedef	struct	s_obj	t_obj;
typedef	struct	s_tmp	t_tmp;

struct		s_obj
{
  t_obj		*prev;
  t_obj		*next;
  char		*name;
  int		x;
  int		y;
  int		z;
  int		rot_x;
  int		rot_y;
  int		rot_z;
  int		angle;
  int		color;
};

struct		s_tmp
{
  char		*name;
  int		x;
  int		y;
  int		z;
  int		rot_x;
  int		rot_y;
  int		rot_z;
  int		angle;
  int		color;
};

t_obj		*new_obj();
t_obj		*my_obj();
t_obj		*first_obj(t_obj *);
t_obj		*last_obj(t_obj *);
t_obj		*append_obj(t_obj *, t_tmp *);
t_obj		*my_parsing(t_obj *, char *);
t_obj		*stock_choice(t_obj *, char *, int, int *);
t_obj		*my_eye(t_obj *, int, int *);
t_obj		*my_sphere(t_obj *, int, int *);
t_obj		*my_cyl(t_obj *, int, int *);
t_obj		*my_cone(t_obj *, int, int *);
t_obj		*my_plan(t_obj *, int, int *);
t_obj		*my_spot(t_obj *, int, int *);
t_tmp		*new_tmp();
t_tmp		*parse_str(t_tmp *, char *, int *);
t_tmp		*stock_val(t_tmp *, char *, char *, int);
int		get_val(char *);
void		check_val(char *, int);
void		check_eye(t_obj *);
void		aff_all_obj(t_obj *);
void		free_all_obj(t_obj *);
void		free_str(char *, char *, char *);

#endif		/* !PARSING_H_ */
