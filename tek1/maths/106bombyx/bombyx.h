/*
** bombyx.h for 106bombyx in /home/gicque_p/local/maths/106bombyx
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon Feb 10 09:02:50 2014 Pierrick Gicquelais
** Last update Wed Feb 19 19:51:27 2014 Pierrick Gicquelais
*/

#ifndef		BOMBYX_H_
# define	BOMBYX_H_

# include	<X11/X.h>
# include	<math.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"mlx.h"

# define	WIN_LENGHT (1920)
# define	WIN_WIDTH (1020)
# define	ZOOM_PLUS (65451)
# define	ZOOM_MINUS (65453)
# define	END_KEY (65307)

typedef struct	s_ptr
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
}		t_ptr;

typedef struct	s_nb
{
  int		xo;
  int		yo;
  int		zoomx;
  int		zoomy;
  int		bpp;
  int		sizeline;
  int		endian;
  int		flag;
}		t_nb;

typedef struct	s_color
{
  int		red;
  int		green;
  int		white;
}		t_color;

typedef struct  s_bomb
{
  t_ptr         *ptr;
  t_nb          *nb;
  t_color	*color;
}               t_bomb;

int		my_put_pixel_to_image(t_nb *, char *, int, int, int);
int		my_put_courbe(t_nb *, char *, int, int);
void		my_init(t_bomb *);
void		check_ex1(double);
void		check_ex2(double, double);
void		fill_ex1(t_bomb *, char *);
void		fill_ex2(t_bomb *, char *, char *);
void		my_draw(t_bomb *, int, int, int, int);
void		my_first_scale(t_ptr *, t_nb *);
void		my_second_scale(t_ptr *, t_nb *);
void		my_third_scale(t_ptr *, t_nb *);
void		my_fourth_scale(t_ptr *, t_nb *);
void		my_hook(t_bomb *);
void		my_free(t_bomb *);
void		my_error(char *, int);

#endif		/* !BOMBYX_H_ */
