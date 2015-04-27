/*
** fdf.h for fdf in /home/gicque_p/local/igraph/MUL_2013_fdf
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Nov 29 19:03:37 2013 Pierrick Gicquelais
** Last update Sun Dec  8 13:51:34 2013 Pierrick Gicquelais
*/

#ifndef FDF_H_
#	define FDF_H_

#include	"mlx.h"
#include	"mlx_int.h"

typedef struct s_ptr
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
} t_ptr;

typedef struct s_list
{
  int		x;
  int		y;
  int		z;
  int		X;
  int		Y;
  struct s_list	*next;
} t_list;

typedef struct s_dat
{
  int		bpp;
  int		sizeline;
  int		endian;
  float		cte1;
  float		cte2;
  int		x1;
  int		x2;
  int		y1;
  int		y2;
  int		i;
  int		j;
  int		mid_x;
  int		proj_x;
  int		mid_y;
  int		proj_y;
  int		save_line;
} t_dat;

void		my_draw(t_dat *, char *, t_list *, t_list *);
void		draw_case_one(t_dat *, char *);
void		draw_case_two(t_dat *, char *);
int		my_pixel_put_to_image(t_dat *, char *, int, int);
void		my_hook(t_ptr *, t_list **);
t_list		*my_parsing(t_list **, char **, t_dat *);
void		proj_iso_list(t_list **, t_dat *);
void		aff_list(t_list *elem);
void		display_map(t_list **, t_dat *, char *);
char		*get_next_line(const int);
char		*re_alloc(char *);
int		alpha(char);
int		word_len(char *);
int		word_count(char *);
char		**my_str_to_wordtab(char *);
void		my_putchar(char);
void		my_putstr(char *);
int		my_strlen(char *);
int		my_getnbr(char *);
int		my_abs(int);
void		my_error(char *);

#endif /* !FDF_H_ */
