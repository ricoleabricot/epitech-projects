/*
** wolf.h for wolf3d in /home/gicque_p/local/igraph/MUL_2013_wolf3d
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue Dec 10 09:06:22 2013 Pierrick Gicquelais
** Last update Tue Feb  4 15:19:28 2014 Pierrick Gicquelais
*/

#ifndef		WOLF_H_
# define	WOLF_H_

# include	<X11/X.h>
# include	"mlx.h"
# include	"mlx_int.h"

# define	WIN_LENGHT (1000)
# define	WIN_WIDTH (800)
# define	MAP_LENGHT (24)
# define	MAP_WIDTH (24)
# define	ROTATE_SPEED (0.03)
# define	ARROW_LEFT (65361)
# define	ARROW_UP (65362)
# define	ARROW_RIGHT (65363)
# define	ARROW_DOWN (65364)
# define	SHIFT_KEY (65505)
# define	CTRL_KEY (65507)
# define	END_KEY (65307)

typedef struct	s_ptr
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
  char		**map;
}		t_ptr;

typedef struct	s_numb
{
  double	speed;
  double	pos_x;
  double	pos_y;
  double	dir_x;
  double	dir_y;
  double	plan_u;
  double	plan_v;
  int		x;
  int		y;
  int		bpp;
  int		sizeline;
  int		endian;
  int		side;
  int		wall;
}		t_numb;

typedef struct	s_color
{
  int		red_pixel;
  int		green_pixel;
  int		blue_pixel;
}		t_color;

typedef struct	s_algo
{
  double	screen;
  double	ray_x;
  double	ray_y;
  double	dist_x;
  double	dist_y;
  double	delta_x;
  double	delta_y;
  int		map_x;
  int		map_y;
  int		step_x;
  int		step_y;
  int		side;
  int		side_color;
}		t_algo;

typedef struct	s_move
{
  int		move_left;
  int		move_right;
  int		move_up;
  int		move_down;
  int		move_end;
}		t_move;

typedef struct	s_wolf
{
  t_ptr		*ptr;
  t_numb	*numb;
  t_color	*color;
  t_algo	*algo;
  t_move	*move;
}		t_wolf;

t_wolf		*init_wolf();
t_ptr		*init_ptr(t_wolf *);
t_numb		*init_numb(t_wolf *);
t_color		*init_color(t_wolf *);
t_algo		*init_algo(t_wolf *);
t_move		*init_move(t_wolf *);
char		*get_next_line(int);
void		my_parsing(t_ptr *);
char		**my_str_to_wordtab(char *);
void		my_init(t_wolf *);
void		display_wall(t_wolf *, t_numb *);
void		my_color(t_color *, t_algo *, int, double);
void		change_color(t_color *, int, int, int);
void		my_hook(t_wolf *);
void		left_rotate(t_numb *);
void		right_rotate(t_numb *);
void		blue_tp(t_ptr *, t_numb *);
void		orange_tp(t_ptr *, t_numb *);
void		display_minimap(t_wolf *, t_numb *);
void		my_minimap_color(t_wolf *, t_numb *, t_color *);
void		my_wall_minimap(t_ptr *, t_numb *, t_color *);
void		my_next_wall_minimap(t_ptr *, t_numb *, t_color *);
void		my_putchar(char);
void		my_putstr(char *);
void		my_putnbr(int);
void		my_error(char *);
int		my_pixel_put_to_image(t_numb *, t_color *, char *);
int		up_deplacement(t_ptr *, t_numb *);
int		down_deplacement(t_ptr *, t_numb *);
int		my_strlen(char *);
int		my_getnbr(char *);
int		move_on(int, t_wolf *);
int		move_off(int, t_wolf *);
int		move_end(t_wolf *);
double		algo_raycasting(t_ptr *, t_algo *, t_numb *);

#endif /* !WOLF_H_ */
